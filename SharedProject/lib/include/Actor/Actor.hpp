#pragma once
#include"lib/include/Manager/Manager.hpp"
#include"ActorPolicy.hpp"

namespace GameLib
{
	class Collider;

	class Actor
	{
	public:
		enum class State {
			Active,
			Pause,
			Dead
		};


	private:
		Actor* mOwner;
		int mUpdateOrder;
		State mState;

	protected:
		OwnerManager<Actor> mOwnedActors;

	public:
		Actor(Actor* owner, int updateOrder = 0)
			:mOwner(owner)
			, mUpdateOrder(updateOrder)
			,mOwnedActors()
			,mState(State::Active)
		{
			if (mOwner)
				mOwner->Add({ this,mUpdateOrder });

		}
		virtual ~Actor() {
			if (mOwner)
				mOwner->Remove(this);
		}

		void Update() {
			mOwnedActors.Invoke<UpdatePolicy<Actor>>();
			CustomizeUpdate();
			mOwnedActors.Invoke<DeadObjectDeletePolicy<Actor>>();
		}

		
		virtual void CustomizeUpdate() {}

		void Add(Node<Actor>&& node) {
			mOwnedActors.Add(std::move(node));
		}
		void Remove(Actor* actor) {
			mOwnedActors.Remove(actor);
		}

		int GetUpdateOrder() const noexcept {
			return mUpdateOrder;
		}

		void SetState(State&& state) {
			mState = std::move(state);
		}
		void SetState(const State& state) {
			mState = state;
		}
		const State& GetState() const noexcept {
			return mState;
		}
	};

}