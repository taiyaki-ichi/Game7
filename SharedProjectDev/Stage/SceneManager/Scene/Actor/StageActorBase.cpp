#include"StageActorBase.hpp"
#include"Stage/SceneManager/StageSceneManager.hpp"
#include"Stage/Gravity/Gravity.hpp"

namespace Stage
{
	ActorBase::ActorBase(GameLib::Actor* scene)
		:GameLib::Actor{scene}
	{}

	const GameLib::Vector2& ActorBase::GetPlayerPos() const
	{
		auto ptr = static_cast<SceneManager*>(mOwner->GetOwner());
		return ptr->GetPlayerPos();
	}


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