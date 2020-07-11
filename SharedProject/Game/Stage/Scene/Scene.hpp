#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<vector>

namespace Game::Stage
{
	class Stage;
	class ActorBase;
	class Camera;

	class Scene : public GameLib::Actor
	{
		//SceneÇ…ëÆÇµÇƒÇ¢ÇÈActorÇ÷ÇÃéQè∆
		std::vector<ActorBase*> mStageActors;

		Camera* mCamera;

	public:
		Scene(Stage* stage, int updateOrder = 0);
		virtual ~Scene() = default;

		void Active();
		void Pause();

		void AddStageActor(ActorBase* actor);
		void RemoveStageActor(ActorBase* actor);

		Stage* GetStage();

		void SetCamera(Camera* c);
		void AdjustCameraPos();
	};
}