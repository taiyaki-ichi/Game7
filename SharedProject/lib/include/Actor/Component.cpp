#include"Component.hpp"
#include"Actor.hpp"

namespace GameLib
{

	Component::Component(Actor* owner, int updateOrder)
		:mOwner(owner)
		, mUpdateOrder(updateOrder)
	{
		mOwner->Add({ this,updateOrder });
	}

	Component::~Component()
	{
		mOwner->Remove(this);
	}

	void Component::Update()
	{
	}

}