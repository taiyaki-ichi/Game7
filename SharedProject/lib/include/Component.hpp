#pragma once
#include<type_traits>
#include"Actor.hpp"

namespace GameLib
{

	class Actor;

	class Component
	{
	public:
		Component(Actor* actor,int updateOrder=0)
			:mOwnerActor(actor)
			,mUpdateOrder(updateOrder)
		{
			mOwnerActor->Add({ this,updateOrder });
		}
		virtual ~Component() {
			mOwnerActor->Remove(this);
		}

		virtual void Update() {

		}

		int GetUpdateOrder() const noexcept {
			return mUpdateOrder;
		}

	private:
		Actor* mOwnerActor;
		int mUpdateOrder;

	};

}