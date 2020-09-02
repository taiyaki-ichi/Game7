#include"StageScene.hpp"
#include"Actor/Player.hpp"
#include"ActorInfo.hpp"
#include"CreateActor.hpp"
#include"Actor/WarpBase.hpp"
#include"Actor/Camera.hpp"

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
			else if (info.mName == "Camera")
			{
				ptr = CreateStageActor(this, std::move(info.mName));
				mCamera = static_cast<Camera*>(ptr);
			}
			else {
				ptr = CreateStageActor(this, std::move(info.mName));
			}

			
			if (ptr) {
				ptr->LoadPosData(std::move(info.mPosData));
				ptr->LoadStringData(std::move(info.mStringData));
			}
		}

		if (startSceneFlag)
			BeginWorking();
		else
			BeginToRest();
	}


	void Scene::AdjustCameraPosiotion()
	{
		if (mCamera)
			mCamera->AdjustPos();
	}


	
}