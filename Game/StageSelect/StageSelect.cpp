#include"StageSelect.hpp"
#include"HexChip.hpp"
#include"StageData.hpp"
#include"PairVec.hpp"
#include"ChoiceIcon.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"LevelDisplay/LevelDisplay.hpp"
#include"StageSelectFlag.hpp"

namespace Game::StageSelect
{
	StageSelect::StageSelect(GameLib::Actor* actor, const std::map<PairVec, unsigned char>& data, const PairVec& nowPos, int lifeNum, int gemNum)
		:GameLib::Actor{ actor }
		, mStageState{data}
		, mChoiceIcon{ nullptr }
		, mLevelDisplay{ nullptr }
		, mLifeDisplay{HexMapParam::LIFE_NUM_POSITION,lifeNum}
		, mGemDisplay{HexMapParam::GEM_NUM_POSITION,gemNum}
		, mTearGemDisplay{HexMapParam::TEARGEM_DISPLAY_POSITON}
	{
		for (const auto& d : gStageInfo)
			new HexChip{ this,ToVector2(d.first),"../Assets/StageSelect/batu_hex.png",-1 };

		for (const auto& d : mStageState)
		{
			std::string fileName{};
			if (d.second & StageSelectFlag::CLEAR_FLAG)
				fileName = "../Assets/StageSelect/clear_hex.png";
			else if (d.second & StageSelectFlag::OPEN_FLAG)
				fileName = "../Assets/StageSelect/circle_hex.png";

			new HexChip{ this,ToVector2(d.first),std::move(fileName) };
		}

		new HexChip{ this,ToVector2(std::make_pair(0,0)),"../Assets/StageSelect/hex.png" };

		mChoiceIcon = new ChoiceIcon{ this };
		mChoiceIcon->SetPosision(nowPos);
		mLevelDisplay = new LevelDisplay{ this };

		mTearGemDisplay.NotDrawing();
	}

	void StageSelect::CustomizeUpdate()
	{
		UpdateChoiceIcon();



		auto iter = gStageInfo.find(mChoiceIcon->GetPosition());
		if (iter != gStageInfo.end()) {

			mLevelDisplay->SetLevelString(iter->second.mLevel);


			//if (GameLib::InputState::GetState(GameLib::Key::Space) == GameLib::ButtonState::Pressed)
			
		}
		else
			mLevelDisplay->SetLevelString("-");

		mLevelDisplay->AdjustPos();
		mLifeDisplay.AdjustPos();
		mGemDisplay.AdjustPos();

		UpdateTearGemDisplay();
	}

	void StageSelect::UpdateChoiceIcon()
	{
		auto pos = mChoiceIcon->GetPosition();
		GameLib::Viewport::SetPos(ToVector2(pos));
		if (GameLib::InputState::GetState(GameLib::Key::E) == GameLib::ButtonState::Pressed)
			pos = AddPair(pos, DIR_E_PAIR);
		if (GameLib::InputState::GetState(GameLib::Key::D) == GameLib::ButtonState::Pressed)
			pos = AddPair(pos, DIR_D_PAIR);
		if (GameLib::InputState::GetState(GameLib::Key::X) == GameLib::ButtonState::Pressed)
			pos = AddPair(pos, DIR_X_PAIR);

		if (GameLib::InputState::GetState(GameLib::Key::Z) == GameLib::ButtonState::Pressed)
			pos = AddPair(pos, DIR_Z_PAIR);
		if (GameLib::InputState::GetState(GameLib::Key::A) == GameLib::ButtonState::Pressed)
			pos = AddPair(pos, DIR_A_PAIR);
		if (GameLib::InputState::GetState(GameLib::Key::W) == GameLib::ButtonState::Pressed)
			pos = AddPair(pos, DIR_W_PAIR);

		auto iter = mStageState.find(pos);
		if (iter != mStageState.end()) 
			mChoiceIcon->SetPosision(pos);
		else
			mTearGemDisplay.NotDrawing();

		if (pos.first == 0 && pos.second == 0)
			mChoiceIcon->SetPosision(pos);
	}

	void StageSelect::UpdateTearGemDisplay()
	{
		auto iconPos = mChoiceIcon->GetPosition();
		auto iter = mStageState.find(iconPos);
		if (iter != mStageState.end())
		{
			mTearGemDisplay.SetFrame();
			if (iter->second & StageSelectFlag::TEARGEM1_FLAG)
				mTearGemDisplay.SetTearGem(1);
			if (iter->second & StageSelectFlag::TEARGEM2_FLAG)
				mTearGemDisplay.SetTearGem(2);
			if (iter->second & StageSelectFlag::TEARGEM3_FLAG)
				mTearGemDisplay.SetTearGem(3);
		}
		else
			mTearGemDisplay.NotDrawing();

		mTearGemDisplay.AdjustPos();
	}


}