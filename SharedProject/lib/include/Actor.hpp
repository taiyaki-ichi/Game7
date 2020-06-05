#pragma once
#include<memory>
#include<type_traits>
#include"Manager/Manager.hpp"
#include"Component.hpp"

namespace GameLib
{

	class Component;

	template<typename T>
	class Manager;

	class Actor
	{
	public:
		Actor(Actor* owner, int updateOrder = 0)
			:mOwner(owner)
			, mUpdateOrder(updateOrder)
		{
			mOwnedActors = std::make_unique<Manager<Actor>>();
			mComponents = std::make_unique<Manager<Component>>();

			if (mOwner)
				mOwner->Add({ this,mUpdateOrder });

		}
		virtual ~Actor() {

			if (mOwner)
				mOwner->Remove(this);
		}

		virtual void Update() {

		}



		void Add(Node<Actor>&& node) {
			mOwnedActors->Add(std::move(node));
		}
		void Add(Node<Component>&& node) {
			mComponents->Add(std::move(node));
		}
		void Remove(Actor* actor) {
			mOwnedActors->Remove(actor);
		}
		void Remove(Component* component) {
			mComponents->Remove(component);
		}


		int GetUpdateOrder() const noexcept {
			return mUpdateOrder;
		}

		//
		//
		template<typename Policy>
		void InvokeOwnedActors() {
			mOwnedActors->Invoke<Policy>();
		}

	protected:
		std::unique_ptr<Manager<Actor>> mOwnedActors;
		std::unique_ptr<Manager<Component>> mComponents;

	private:
		Actor* mOwner;
		int mUpdateOrder;

		
	};

}