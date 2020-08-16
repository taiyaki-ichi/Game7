#include"StageSelect.hpp"
#include"StageSelectParam.hpp"
#include"StageStateFlag.hpp"
#include"HexChip/HexChip.hpp"
#include"ChoiceIcon.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"HexChip/ToVector2.hpp"

namespace Game
{
	StageSelect::StageSelect(GameLib::Actor* actor, const std::unordered_map<HexVec, unsigned char>& saveData,
		const std::unordered_map<HexVec, std::vector<std::string>>& stageData,
		const HexVec& nowPos, int lifeNum, int gemNum)
		:GameLib::Actor{actor}
		, mStageData{}
		, mChoiceIcon{nullptr}
		, mStageNameDisplay{StageSelectParam::STAGENAME_DISPLAY_POSITION,GameLib::Font::Size::Size_48}
		, mStageLevelDisplay{StageSelectParam::LEVEL_DISPLAY_POSITION,GameLib::Font::Size::Size_36}
		, mTearGemDisplay{StageSelectParam::TEARGEM_DIPLAY_POSITION}
		, mGemDisplay{ StageSelectParam::GEM_NUM_POSITION,gemNum }
		, mLifeDisplay{ StageSelectParam::LIFE_NUM_POSITION,lifeNum }
		, mChoiceIconStopFlag{false}
	{

		for (const auto& stageDataTmp : stageData)
		{
			auto saveDataIter = saveData.find(stageDataTmp.first);
			//特別なマスの場合
			if (stageDataTmp.second.size() == 1)
			{
				//仮
				if (stageDataTmp.second[0] == "start")
					new HexChip{ this,stageDataTmp.first.x,stageDataTmp.first.y,"../Assets/StageSelect/hex.png" };
				else if (stageDataTmp.second[0] == "save")
					new HexChip{ this,stageDataTmp.first.x,stageDataTmp.first.y,"../Assets/StageSelect/hex.png" };
				else if (stageDataTmp.second[0] == "title")
					new HexChip{ this,stageDataTmp.first.x,stageDataTmp.first.y,"../Assets/StageSelect/hex.png" };

				//特別なマスは必ず通れるので追加
				mStageData.emplace(stageDataTmp.first, std::make_pair(stageDataTmp.second, saveDataIter->second));
			}
			//saveDataが存在する場合、つまり進むことできる通常のマス
			else if (saveDataIter != saveData.end())
			{
				if (saveDataIter->second & StageStateFlag::CLEAR_FLAG)
					new HexChip{ this,stageDataTmp.first.x,stageDataTmp.first.y,"../Assets/StageSelect/clear_hex.png" };
				else //if(saveDataIter->second & StageSelectFlag::OPEN_FLAG)
					new HexChip{ this,stageDataTmp.first.x,stageDataTmp.first.y,"../Assets/StageSelect/circle_hex.png" };

				//saveDataに記載されているということは通れるので追加
				mStageData.emplace(stageDataTmp.first, std::make_pair(stageDataTmp.second, saveDataIter->second));
			}
			//クリアできてない進むことができないマス
			else
			{
				new HexChip{ this,stageDataTmp.first.x,stageDataTmp.first.y,"../Assets/StageSelect/batu_hex.png" };
			}
		}

		mChoiceIcon = new ChoiceIcon{ this };
		//nowPOsが有効な値でなかった時の保険
		mChoiceIcon->SetPosision({ 0,0 });
		CheckposAndUpdateDisplay(nowPos);

		AdjustDisplayPos();
	}

	void StageSelect::CustomizeUpdate()
	{
		if (!mChoiceIconStopFlag)
		{
			auto pos = mChoiceIcon->GetPosition();
			GameLib::Viewport::SetPos(ToVector2(pos.x, pos.y));
			auto addPairVec = GetPairVecPerFrame();
			if (addPairVec != HexVec{0,0})
			{
				pos = pos + addPairVec;
				CheckposAndUpdateDisplay(std::move(pos));
			}
		}
		AdjustDisplayPos();
	}

	const HexVec& StageSelect::GetPairVecPerFrame()
	{
		if (GameLib::InputState::GetState(GameLib::Key::E) == GameLib::ButtonState::Pressed)
			return DIR_E;
		if (GameLib::InputState::GetState(GameLib::Key::D) == GameLib::ButtonState::Pressed)
			return DIR_D;
		if (GameLib::InputState::GetState(GameLib::Key::X) == GameLib::ButtonState::Pressed)
			return DIR_X;

		if (GameLib::InputState::GetState(GameLib::Key::Z) == GameLib::ButtonState::Pressed)
			return DIR_Z;
		if (GameLib::InputState::GetState(GameLib::Key::A) == GameLib::ButtonState::Pressed)
			return DIR_A;
		if (GameLib::InputState::GetState(GameLib::Key::W) == GameLib::ButtonState::Pressed)
			return DIR_W;

		return { 0,0 };
	}

	void StageSelect::CheckposAndUpdateDisplay(const HexVec& pos)
	{
		auto iter = mStageData.find(pos);
		if (iter != mStageData.end())
		{
			if (iter->second.first.size() == 1)
			{
				mStageNameDisplay.SetText(iter->second.first[0]);
				mStageLevelDisplay.SetText("");
				mTearGemDisplay.NotDrawing();
			}
			else
			{
				mStageNameDisplay.SetText(iter->second.first[2]);
				mStageLevelDisplay.SetText("level : " + iter->second.first[1]);
				mTearGemDisplay.SetFrame();
				if (iter->second.second & StageStateFlag::TEARGEM1_FLAG)
					mTearGemDisplay.SetTearGem(1);
				if (iter->second.second & StageStateFlag::TEARGEM2_FLAG)
					mTearGemDisplay.SetTearGem(2);
				if (iter->second.second & StageStateFlag::TEARGEM3_FLAG)
					mTearGemDisplay.SetTearGem(3);
			}

			mChoiceIcon->SetPosision(pos);
		}
	}

	void StageSelect::AdjustDisplayPos()
	{
		mStageNameDisplay.AdjustPos();
		mStageLevelDisplay.AdjustPos();
		mGemDisplay.AdjustPos();
		mTearGemDisplay.AdjustPos();
		mLifeDisplay.AdjustPos();
	}

	const HexVec& StageSelect::GetChoicePos() const 
	{
		return mChoiceIcon->GetPosition();
	}

	void StageSelect::ChoiceIconStop()
	{
		mChoiceIconStopFlag = true;
	}
}