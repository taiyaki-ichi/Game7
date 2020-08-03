#include"StageScene.hpp"
#include"Actor/Player.hpp"
#include"ActorInfo.hpp"
#include"CreateActor.hpp"
#include"Actor/WarpBase.hpp"

namespace Stage
{

	Scene::Scene(GameLib::Actor* manager)
		:GameLib::Actor{ manager }
		, mCamera{nullptr}
	{

	}

	void Scene::CreateActors(std::vector<ActorInfo>&& actorInfos, Player* player)
	{
		bool startSceneFlag = false;

		for (auto& info : actorInfos) {
			ActorBase* ptr = nullptr;
			if (info.mName == "Player") {
				startSceneFlag = true;
				ptr = player;
			}
			else if (info.mName == "Warp") {
				auto warpType = info.mStringData[""];
				auto nameTag = info.mStringData[""];
				auto destinationNameTag = info.mStringData[""];

				ptr = CreateStageWarp(this, std::move(warpType), std::move(nameTag), std::move(destinationNameTag));
			}
			else {
				ptr = CreateStageActor(this, std::move(info.mName));
			}

			if (ptr)
				ptr->LoadData(std::move(info.mFloatData));
		}

		if (startSceneFlag)
			Active();
		else
			Pause();
	}

	

	void Scene::AdjustCameraPosiotion()
	{

	}



}