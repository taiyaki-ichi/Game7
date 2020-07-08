#include"Scene.hpp"
#include"Game/Stage/Stage.hpp"
#include"Actor/ActorBase.hpp"

namespace Game::Stage
{

	Scene::Scene(Stage* stage,int updateOrder)
		:GameLib::Actor{stage,updateOrder}
		, mStageActors{}
	{
	}

	void Scene::Active()
	{
		SetState(Actor::State::Active);
		for (auto& actorPtr : mStageActors)
			actorPtr->Active();
	}

	void Scene::Pause()
	{
		SetState(Actor::State::Pause);
		for (auto& actorPtr : mStageActors)
			actorPtr->Pause();
	}

	void Scene::AddStageActor(ActorBase* actor)
	{
		mStageActors.emplace_back(actor);
	}

	void Scene::RemoveStageActor(ActorBase* actor)
	{
		auto i = std::find(mStageActors.begin(), mStageActors.end(), actor);
		if (i != mStageActors.end())
			mStageActors.erase(i);
	}

	Stage* Scene::GetStage()
	{
		return static_cast<Stage*>(mOwner);
	}

}