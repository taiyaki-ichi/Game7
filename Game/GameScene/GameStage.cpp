#include"GameStage.hpp"
#include"Stage/Stage.hpp"
#include"Stage/StageFlag.hpp"
#include"GameSceneFlag.hpp"
#include"StageStateFlag.hpp"

namespace Game
{
	GameStage::GameStage(GameLib::Actor* actor,const GameData& gameData,const std::string& stageName,Stage::BackGroundType&& bgType)
		:SceneBase{ actor,gameData }
		, mStage{ nullptr }
	{
		mStage = new ::Stage::Stage{ this,"../Data/Stage/" + stageName + ".json",
			mGameData.mPlayerLifeNum,mGameData.mPlayerGemNum ,bgType };
	}

	void GameStage::CustomizeUpdate()
	{
		if (mStage->CheckFlag(Stage::StageFlag::CLEAR_FLAG)) {

			auto itemNum = mStage->GetItemNumData();
			mGameData.mPlayerGemNum = itemNum.mGemNum;
			mGameData.mPlayerLifeNum = itemNum.mLifeNum;

			unsigned char flag = StageStateFlag::CLEAR_FLAG | StageStateFlag::OPEN_FLAG;
			if (itemNum.mTearGemCnt[0])
				flag |= StageStateFlag::TEARGEM1_FLAG;
			if (itemNum.mTearGemCnt[1])
				flag |= StageStateFlag::TEARGEM2_FLAG;
			if (itemNum.mTearGemCnt[2])
				flag |= StageStateFlag::TEARGEM3_FLAG;
			mGameData.mSaveData.insert_or_assign(mGameData.mNowPos, flag);

			UpFlag(SceneFlag::STAGE_CLAER_FLAG);
		}
		else if (mStage->CheckFlag(Stage::StageFlag::MISS_FLAG)) {

			auto itemNum = mStage->GetItemNumData();
			mGameData.mPlayerGemNum = itemNum.mGemNum;
			mGameData.mPlayerLifeNum = itemNum.mLifeNum - 1;

			UpFlag(SceneFlag::STAGE_MISS_FLAG);
		}
		else if (mStage->CheckFlag(Stage::StageFlag::RETURN_STAGESELECT_FLAG))
			UpFlag(SceneFlag::GO_STAGESELECT_FLAG);
	}

}