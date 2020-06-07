#pragma once
#include"lib/include/Manager/Manager.hpp"
#include"lib/include/Component/Component.hpp"
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
			,mComponents()
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
			mComponents.Invoke<UpdatePolicy<Component>>();
		}



		void Add(Node<Actor>&& node) {
			mOwnedActors.Add(std::move(node));
		}
		void Add(Node<Component>&& node) {
			mComponents.Add(std::move(node));
		}
		void Remove(Actor* actor) {
			mOwnedActors.Remove(actor);
		}
		void Remove(Component* component) {
			mComponents.Remove(component);
		}


		int GetUpdateOrder() const noexcept {
			return mUpdateOrder;
		}

		template<typename Policy>
		void InvokeOwnedActors() {
			mOwnedActors->Invoke<Policy>();
		}
		template<typename Policy>
		void InvokeComponents() {
			mComponents->Invoke<Policy>();
		}

	protected:
		OwnerManager<Actor> mOwnedActors;
		OwnerManager<Component> mComponents;

	private:
		Actor* mOwner;
		int mUpdateOrder;


	};

}