#include"StageActorBase.hpp"
#include"Stage/SceneManager/StageSceneManager.hpp"
#include"Stage/Gravity/Gravity.hpp"

namespace Stage
{
	ActorBase::ActorBase(GameLib::Actor* scene,int updateOrder)
		:GameLib::Actor{scene,updateOrder}
	{}

	void ActorBase::CustomizeUpdate()
	{
		if (UpdateOrNot())
			Update();
	}

	bool ActorBase::StageIsNotRotation()
	{
		return !Gravity::IsRotation();
	}
}