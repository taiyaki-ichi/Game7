#include"WarpBase.hpp"
#include"Game/Stage/Stage.hpp"
#include"Game/Stage/Scene/Scene.hpp"
#include"Game/Stage/Scene/Scene.hpp"
#include"Game/Stage/Stage.hpp"

namespace Game::Stage
{
	WarpBase::WarpBase(Scene* scene,const GameLib::Vector2& pos)
		:ActorBase{ scene }
		, mPosition{pos}
	{
		scene->GetStage()->AddWarpGate(this);
	}
	WarpBase::~WarpBase()
	{
		auto scene = static_cast<Scene*>(mOwner);
		scene->GetStage()->RemoveWarpGate(this);
	}
	void WarpBase::SetStringInfo(std::string&& nameTag, std::string&& destinationNameTag)
	{
		mThisNameTag = std::move(nameTag);
		mDestinationNameTag = std::move(destinationNameTag);
	}
	const GameLib::Vector2& WarpBase::GetPosition() const noexcept
	{
		return mPosition;
	}
	const std::string& WarpBase::GetNameTag() const noexcept
	{
		return mThisNameTag;
	}
	void WarpBase::WarpPlayer()
	{
		auto stage = GetScene()->GetStage();
		stage->PlayerWarp(mDestinationNameTag);
	}
}