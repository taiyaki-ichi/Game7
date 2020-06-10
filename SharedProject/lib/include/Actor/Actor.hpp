#pragma once
#include"lib/include/Manager/Manager.hpp"
#include"lib/include/Manager/StanderdInvokeFunc.hpp"

namespace GameLib
{
	class Collider;

	class Actor
	{
		Actor* mOwner;
		int mUpdateOrder;

	protected:
		OwnerManager<Actor> mOwnedActors;

	public:
		Actor(Actor* owner, int updateOrder = 0)
			:mOwner(owner)
			, mUpdateOrder(updateOrder)
			,mOwnedActors()
		{
			if (mOwner)
				mOwner->Add({ this,mUpdateOrder });

		}
		virtual ~Actor() {
			if (mOwner)
				mOwner->Remove(this);
		}

		virtual void Update() {
			mOwnedActors.Invoke<UpdatePolicy<Actor>>();
		}

		//所有するColliderが別のColliderに当たった時の通知
		virtual void HitCollider(const Collider& collider){}

		void Add(Node<Actor>&& node) {
			mOwnedActors.Add(std::move(node));
		}
		void Remove(Actor* actor) {
			mOwnedActors.Remove(actor);
		}

		int GetUpdateOrder() const noexcept {
			return mUpdateOrder;
		}

	};

}