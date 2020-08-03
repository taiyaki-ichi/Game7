#include"WarpBase.hpp"
#include"Stage/SceneManager/StageSceneManager.hpp"

namespace Stage
{
	WarpBase::WarpBase(GameLib::Actor* actor)
		:ActorBase{ actor }
		, mNameTag{""}
	{
		auto ptr = static_cast<SceneManager*>(mOwner->GetOwner());
		ptr->AddWarpBase(this);
	}

	WarpBase::~WarpBase()
	{
		auto ptr = static_cast<SceneManager*>(mOwner->GetOwner());
		ptr->RemoveWarpBase(this);
	}

	const std::string& WarpBase::GetNameTag() const
	{
		return mNameTag;
	}
}