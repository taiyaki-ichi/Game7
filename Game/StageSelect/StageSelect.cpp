#include"StageSelect.hpp"
#include"HexChip.hpp"
#include"StageData.hpp"
#include"PairVec.hpp"
#include"ChoiceIcon.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"LevelDisplay/LevelDisplay.hpp"

namespace Game::StageSelect
{
	StageSelect::StageSelect(GameLib::Actor* actor,const std::map<PairVec,int>& data)
		:GameLib::Actor{ actor }
		, mStageData{ data }
		, mChoiceIcon{nullptr}
		, mStageFileName{""}
		, mLevelDisplay{nullptr}
	{
		for (const auto& d : gStageInfo)
			new HexChip{ this,ToVector2(d.first),"../Assets/StageSelect/batu_hex.png",-1 };

		for (const auto& d : mStageData)
		{
			std::string fileName{};
			if (d.second == 0)
				fileName = "../Assets/StageSelect/hex.png";
			else if(d.second==1)
				fileName = "../Assets/StageSelect/clear_hex.png";
			new HexChip{ this,ToVector2(d.first),std::move(fileName) };
		}

		new HexChip{ this,ToVector2(std::make_pair(0,0)),"../Assets/StageSelect/hex.png" };

		mChoiceIcon = new ChoiceIcon{ this };
		mLevelDisplay = new LevelDisplay{ this };
	}

	void StageSelect::CustomizeUpdate()
	{
		UpdateChoiceIcon();

		auto iter = gStageInfo.find(mChoiceIcon->GetPosition());
		if (iter != gStageInfo.end()) {

			mLevelDisplay->SetLevelString(iter->second.mLevel);

			if (GameLib::InputState::GetState(GameLib::Key::Space) == GameLib::ButtonState::Pressed)
				mStageFileName = iter->second.mFileName;
		}
		else
			mLevelDisplay->SetLevelString("-");

		mLevelDisplay->AdjustPos();
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

		auto iter = mStageData.find(pos);
		if (iter != mStageData.end())
			mChoiceIcon->SetPosision(pos);

		if (pos.first == 0 && pos.second == 0)
			mChoiceIcon->SetPosision(pos);
	}
}