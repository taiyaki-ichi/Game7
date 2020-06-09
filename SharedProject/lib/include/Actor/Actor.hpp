#pragma once
#include"lib/include/Manager/Manager.hpp"
#include"lib/include/Manager/StanderdInvokeFunc.hpp"

namespace GameLib
{

	class Actor
	{
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



		void Add(Node<Actor>&& node) {
			mOwnedActors.Add(std::move(node));
		}
		void Remove(Actor* actor) {
			mOwnedActors.Remove(actor);
		}


		int GetUpdateOrder() const noexcept {
			return mUpdateOrder;
		}

		template<typename Policy>
		void InvokeOwnedActors() {
			mOwnedActors->Invoke<Policy>();
		}

	protected:
		OwnerManager<Actor> mOwnedActors;


	private:
		Actor* mOwner;
		int mUpdateOrder;


	};

}