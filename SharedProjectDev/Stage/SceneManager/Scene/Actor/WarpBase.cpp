#include"WarpBase.hpp"
#include"Stage/SceneManager/StageSceneManager.hpp"

namespace Stage
{
	WarpBase::WarpBase(GameLib::Actor* actor)
		:ActorBase{ actor }
		, mNameTag{""}
		, mDestinationNameTag{""}
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

	void WarpBase::SetThisNameTag(std::string&& nameTag)
	{
		mNameTag = std::move(nameTag);
	}
	void WarpBase::SetDestinationNameTag(std::string&& nameTag)
	{
		mDestinationNameTag = std::move(nameTag);
	}

	void WarpBase::WarpPlayer()
	{
		auto ptr = static_cast<SceneManager*>(mOwner->GetOwner());
		ptr->Warp(this, mDestinationNameTag);
	}
}