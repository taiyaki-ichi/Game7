#include"Game.hpp"
#include"StageSelect/StageSelect.hpp"
#include"StageData.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"Stage/Stage.hpp"
#include"StageSelect/HexChip/ToVector2.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"RectCurtain/RectCurtain.hpp"
#include"Stage/Stage.hpp"
#include"Stage/StageFlag.hpp"
#include"StageSelect/PairVec.hpp"
#include"StageStateFlag.hpp"

namespace Game
{
	Game::Game(GameLib::Actor* actor)
		:GameLib::Actor{actor}
		, mTitle{nullptr}
		, mStageSelect{nullptr}
		, mStage{nullptr}
		, mSaveData{}
		, mPlayerLifeNum{5}
		, mPlayerGemNum{ 0 }
		, mPosition{ std::make_pair(0,0) }
		, mRectCurtain{nullptr}
	{
		Load();

		mRectCurtain = new RectCurtain{ this };

		//仮
		mStageSelect = new StageSelect{ this,mSaveData,gStageData,std::make_pair(0,0),mPlayerLifeNum,mPlayerGemNum };

	}

	void Game::CustomizeUpdate()
	{
		if (mTitle)
			UpdateTitle();
		else if (mStageSelect)
			UpdateStageSelect();
		else if (mStage)
			UpdateStage();
	}

	bool Game::Load()
	{
		//仮
		mSaveData.emplace(std::make_pair(1, 0), 0b1);
		//mSaveData.emplace(std::make_pair(2, 0), 0b10110);
		//mSaveData.emplace(std::make_pair(3, 0), 0b1);
	}

	bool Game::Save()
	{

	}

	void Game::UpdateTitle()
	{

	}

	void Game::UpdateStageSelect()
	{
		if (GameLib::InputState::GetState(GameLib::Key::Space) == GameLib::ButtonState::Pressed)
		{
			auto iter = gStageData.find(mStageSelect->GetChoicePos());
			if (iter != gStageData.end())
			{
				mPosition = iter->first;
				mStageSelect->ChoiceIconStop();
				mRectCurtain->Close();
			}

		}
		else if (mRectCurtain->IsClose())
		{
			auto iter = gStageData.find(mPosition);
			if (iter != gStageData.end())
			{
				mStageSelect->SetState(GameLib::Actor::State::Dead);
				mStageSelect = nullptr;

				mStage = new ::Stage::Stage{ this,"../Data/Stage/" + iter->second[0] + ".json" ,mPlayerLifeNum,mPlayerGemNum };

				mRectCurtain->Open();
			}
		}
	}

	void Game::UpdateStage()
	{
		if (mRectCurtain->IsOpen() && mStage->CheckFlag(Stage::StageFlag::CLEAR_FLAG))
		{
			mRectCurtain->Close();

			auto item = mStage->GetItemNumData();
			mPlayerLifeNum = item.mLifeNum;
			mPlayerGemNum = item.mGemNum;

			//セーブデータの更新
			//クリア情報
			unsigned char flag{ 0 };
			flag |= StageStateFlag::OPEN_FLAG;
			flag |= StageStateFlag::CLEAR_FLAG;
			if (item.mTearGemCnt[0])
				flag |= StageStateFlag::TEARGEM1_FLAG;
			if (item.mTearGemCnt[1])
				flag |= StageStateFlag::TEARGEM2_FLAG;
			if (item.mTearGemCnt[2])
				flag |= StageStateFlag::TEARGEM3_FLAG;
			mSaveData.insert_or_assign(mPosition, flag);

			//新しくいける場所
			//すでにデータが存在する場合、挿入しない
			auto iter1 = gStageData.find(AddPair(mPosition, DIR_E_PAIR));
			if (iter1 != gStageData.end())
				mSaveData.emplace(iter1->first, StageStateFlag::OPEN_FLAG);

			auto iter2 = gStageData.find(AddPair(mPosition, DIR_D_PAIR));
			if (iter2 != gStageData.end())
				mSaveData.emplace(iter2->first, StageStateFlag::OPEN_FLAG);

			auto iter3 = gStageData.find(AddPair(mPosition, DIR_X_PAIR));
			if (iter3 != gStageData.end())
				mSaveData.emplace(iter3->first, StageStateFlag::OPEN_FLAG);

		}
		else if (mRectCurtain->IsOpen() && mStage->CheckFlag(Stage::StageFlag::MISS_FLAG))
		{
			mRectCurtain->Close();

			auto item = mStage->GetItemNumData();
			mPlayerLifeNum = item.mLifeNum;
			mPlayerGemNum = item.mGemNum;

			mPlayerLifeNum--;
		}
		else if (mRectCurtain->IsOpen() && mStage->CheckFlag(Stage::StageFlag::RETURN_TO_TITLE_FLAG))
		{
			mRectCurtain->Close();
		}

		if (mRectCurtain->IsClose())
		{
			mStage->SetState(GameLib::Actor::State::Dead);
			mStage = nullptr;

			mStageSelect = new StageSelect{ this,mSaveData,gStageData,mPosition,mPlayerLifeNum,mPlayerGemNum };
			
			mRectCurtain->Open();
		}
	}


}