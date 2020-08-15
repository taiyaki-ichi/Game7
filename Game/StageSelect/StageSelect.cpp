#include"StageSelect.hpp"
#include"StageSelectParam.hpp"
#include"StageStateFlag.hpp"
#include"HexChip/HexChip.hpp"
#include"ChoiceIcon.hpp"
#include"PairVec.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"HexChip/ToVector2.hpp"

namespace Game
{
	StageSelect::StageSelect(GameLib::Actor* actor, const std::map<std::pair<int, int>, unsigned char>& saveData,
		const std::map<std::pair<int, int>, std::vector<std::string>>& stageData,
		const std::pair<int, int>& nowPos, int lifeNum, int gemNum)
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
		auto stageDataIter = stageData.begin();
		auto saveDataIter = saveData.begin();

		while (stageDataIter != stageData.end())
		{
			//特殊なマスの場合
			if (stageDataIter->second.size() == 1)
			{
				//仮
				if (stageDataIter->second[0] == "start")
					new HexChip{ this,stageDataIter->first,"../Assets/StageSelect/hex.png" };
				else if (stageDataIter->second[0] == "save")
					new HexChip{ this,stageDataIter->first,"../Assets/StageSelect/hex.png" };
				else if (stageDataIter->second[0] == "title")
					new HexChip{ this,stageDataIter->first,"../Assets/StageSelect/hex.png" };

				//特別なマスは必ず通れるので追加
				mStageData.emplace(stageDataIter->first, std::make_pair(stageDataIter->second, saveDataIter->second));

			}
			//そのステージの進捗情報がsaveDataに記載されている場合
			else if (stageDataIter->first == saveDataIter->first)
			{
				if (saveDataIter->second & StageStateFlag::CLEAR_FLAG)
					new HexChip{ this,stageDataIter->first,"../Assets/StageSelect/clear_hex.png" };
				else //if(saveDataIter->second & StageSelectFlag::OPEN_FLAG)
					new HexChip{ this,stageDataIter->first,"../Assets/StageSelect/circle_hex.png" };

				//saveDataに記載されているということは通れるので追加
				mStageData.emplace(stageDataIter->first, std::make_pair(stageDataIter->second, saveDataIter->second));
				saveDataIter++;
			}
			else
			{
				new HexChip{ this,stageDataIter->first,"../Assets/StageSelect/batu_hex.png" };
			}

			stageDataIter++;
		}

		mChoiceIcon = new ChoiceIcon{ this };
		//nowPOsが有効な値でなかった時の保険
		mChoiceIcon->SetPosision(std::make_pair(0, 0));
		CheckposAndUpdateDisplay(nowPos);

		AdjustDisplayPos();
	}

	void StageSelect::CustomizeUpdate()
	{
		if (!mChoiceIconStopFlag)
		{
			auto pos = mChoiceIcon->GetPosition();
			GameLib::Viewport::SetPos(ToVector2(pos));
			auto addPairVec = GetPairVecPerFrame();
			if (addPairVec != NON_DIR)
			{
				pos = AddPair(pos, addPairVec);
				CheckposAndUpdateDisplay(std::move(pos));
			}
		}
		AdjustDisplayPos();
	}

	const PairVec& StageSelect::GetPairVecPerFrame()
	{
		if (GameLib::InputState::GetState(GameLib::Key::E) == GameLib::ButtonState::Pressed)
			return DIR_E_PAIR;
		if (GameLib::InputState::GetState(GameLib::Key::D) == GameLib::ButtonState::Pressed)
			return DIR_D_PAIR;
		if (GameLib::InputState::GetState(GameLib::Key::X) == GameLib::ButtonState::Pressed)
			return DIR_X_PAIR;

		if (GameLib::InputState::GetState(GameLib::Key::Z) == GameLib::ButtonState::Pressed)
			return DIR_Z_PAIR;
		if (GameLib::InputState::GetState(GameLib::Key::A) == GameLib::ButtonState::Pressed)
			return DIR_A_PAIR;
		if (GameLib::InputState::GetState(GameLib::Key::W) == GameLib::ButtonState::Pressed)
			return DIR_W_PAIR;

		return NON_DIR;
	}

	void StageSelect::CheckposAndUpdateDisplay(const std::pair<int, int>& pos)
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

	const PairVec& StageSelect::GetChoicePos() const 
	{
		return mChoiceIcon->GetPosition();
	}

	void StageSelect::ChoiceIconStop()
	{
		mChoiceIconStopFlag = true;
	}
}