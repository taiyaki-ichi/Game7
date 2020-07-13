#include"ActorBase.hpp"
#include"Game/Stage/Scene/Scene.hpp"

namespace Game::Stage
{
	ActorBase::ActorBase(Scene* scene,int updateOrder)
		:GameLib::Actor{scene,updateOrder}
	{
		scene->AddStageActor(this);
	}
	ActorBase::~ActorBase()
	{
		auto scene = static_cast<Scene*>(mOwner);
		scene->Remove(this);
	}
	void ActorBase::CustomizeUpdate()
	{
		if (UpdateOrNot())
			ActorUpdate();
	}

	bool ActorBase::UpdateOrNot()
	{
		return true;
	}
	Scene* ActorBase::GetScene()
	{
		return static_cast<Scene*>(mOwner);
	}
}