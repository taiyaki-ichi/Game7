#include"StageSceneManager.hpp"
#include"Scene/StageScene.hpp"
#include"Scene/Actor/Player.hpp"
#include"Scene/Actor/WarpBase.hpp"
#include"StageSceneChanger.hpp"
#include"GameLib/include/InputState/InputState.hpp"

namespace Stage
{

	SceneManager::SceneManager(GameLib::Actor* stage)
		:GameLib::Actor{stage}
		, mWarpBases{}
		, mFlags{0}
		, mPlayer{nullptr}
	{
		mPlayer = new Player{ this };
	}


	void SceneManager::CustomizeUpdate()
	{
		//kari
		/*
		auto warpNameTag = mPlayer->GetWarpNameTag();
		if (warpNameTag.has_value()) {
			Warp(warpNameTag.value().first, warpNameTag.value().second);
		}
		*/
	}
	char SceneManager::GetFlags()
	{
		return mFlags;
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

}