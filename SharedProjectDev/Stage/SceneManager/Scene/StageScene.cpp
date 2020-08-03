#include"StageScene.hpp"
#include"Actor/Player.hpp"
#include"ActorInfo.hpp"
#include"CreateActor.hpp"

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
			ActorBase* ptr;
			if (info.mName == "Player") {
				startSceneFlag = true;
				ptr = player;
			}
			else {
				ptr = CreateStageActor(this, std::move(info.mName));
			}

			ptr->LoadData(std::move(info.mFloatData), std::move(info.mStringData));
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