#include"StageSceneManager.hpp"
#include"Scene/StageScene.hpp"
#include"Scene/Actor/Player.hpp"
#include"Scene/Actor/WarpBase.hpp"
#include"StageSceneChanger.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"Scene/Actor/Player/PlayerFlag.hpp"
#include"SceneManagerFlag.hpp"
#include"StageSceneManagerParam.hpp"

namespace Stage
{

	SceneManager::SceneManager(GameLib::Actor* stage, int playerLifeNum, int playerGemNum)
		:GameLib::Actor{stage}
		, mWarpBases{}
		, mFlags{0}
		, mPlayer{nullptr}
		, mCnt{-1}
	{


		mPlayer = new Player{ this ,playerLifeNum,playerGemNum };
	}


	void SceneManager::CustomizeUpdate()
	{
		//std::cout << "scene manager player pos: " << mPlayer->GetPosition().x << "\n";
		if (mPlayer->CheckFlag(PlayerFlag::DEATH_MOTION_FINISH_FLAG))
			mFlags |= SceneManagerFlag::MISS_FLAG;
		if (mPlayer->CheckFlag(PlayerFlag::GOAL_FLAG) && mCnt == -1)
			mCnt = 0;
		if (mCnt >= SceneManagerParam::GOAL_MOVIE_TIME)
			mFlags |= SceneManagerFlag::CLEAR_FLAG;

		if (mPlayer->CheckFlag(PlayerFlag::GOAL_FLAG))
			mFlags |= SceneManagerFlag::PLAYER_CLEAR_MOTION_FLAG;
		if (mPlayer->CheckFlag(PlayerFlag::DEATH_FLAG))
			mFlags |= SceneManagerFlag::PLAYER_DEATH_MOTION_FLAG;

		if (mCnt >= 0)
			mCnt++;

		
	}
	void SceneManager::CreateScene(std::vector<std::vector<ActorInfo>>&& stageData)
	{
		for (auto& sceneData : stageData) {
			
			auto scenePtr = new Scene{ this };
			scenePtr->CreateActors(std::move(sceneData), mPlayer);	
		}
	}

	void SceneManager::AddWarpBase(WarpBase* warp)
	{
		if (warp)
			mWarpBases.emplace_back(warp);
	}
	void SceneManager::RemoveWarpBase(WarpBase* warp)
	{
		auto i = std::find(mWarpBases.begin(), mWarpBases.end(), warp);
		if (i != mWarpBases.end())
			mWarpBases.erase(i);
	}

	const GameLib::Vector2& SceneManager::GetPlayerPos() const
	{
		return mPlayer->GetPosition();
	}

	void SceneManager::Warp(WarpBase* prevWarpBase, const std::string& nextNameTag)
	{

		WarpBase* nextWarpPtr = nullptr;
		for (auto ptr : mWarpBases) {
			if (ptr->GetNameTag() == nextNameTag)
				nextWarpPtr = ptr;
		}

		if (prevWarpBase && nextWarpPtr)
			new SceneChanger{ this,mPlayer,prevWarpBase,nextWarpPtr };

	}

	bool SceneManager::CheckFlag(char flag)
	{
		return mFlags & flag;
	}

	ItemNumData SceneManager::GetItemNumData()
	{
		return mPlayer->GetItemNumData();
	}

	void SceneManager::ReturnStageSelect()
	{
		mFlags |= SceneManagerFlag::RETURN_STAGESELECT_FLAG;
	}
}