#include"StageActorBase.hpp"
#include"Game/Stage/Scene/StageScene.hpp"

namespace Game::Stage
{
	ActorBase::ActorBase(Scene* scene, int updateOrder)
		:GameLib::Actor{scene,updateOrder}
	{
		scene->AddStageActor(this);
	}
	ActorBase::~ActorBase()
	{
		auto scene = static_cast<Scene*>(mOwner);
		scene->Remove(this);
	}
}