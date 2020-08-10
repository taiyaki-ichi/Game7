#pragma once
#include"ActorsManager.hpp"
#include"ActorPolicy.hpp"
#include<vector>

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


	protected:
		Actor* mOwner;
		ActorsManager<Actor> mOwnedActors;

	private:
		int mUpdateOrder;
		State mStateManager;

		//UpdateíÜÇ…í«â¡Ç≥ÇÍÇΩèÍçáÇ±Ç±Ç…àÍéûï€ë∂
		std::vector<Node<Actor>> mPendingActors;
		bool mIsUpdating;

	public:
		Actor(Actor* owner, int updateOrder = 0)
			:mOwner(owner)
			, mUpdateOrder(updateOrder)
			,mOwnedActors()
			,mStateManager(State::Active)
			,mIsUpdating(false)
		{
			if (mOwner)
				mOwner->Add({ this,mUpdateOrder });

		}
		virtual ~Actor() {
			if (mOwner)
				mOwner->Remove(this);
		}

		void Update() {
			mIsUpdating = true;
			mOwnedActors.Invoke<UpdatePolicy<Actor>>();
			CustomizeUpdate();
			mIsUpdating = false;
			while (!mPendingActors.empty()) {
				auto&& actor = mPendingActors.back();
				mPendingActors.pop_back();
				mOwnedActors.Add(std::move(actor));
			}
			mPendingActors.clear();
			mOwnedActors.DeleteDeadActors();
		}

		
		virtual void CustomizeUpdate() {}

		void Add(Node<Actor>&& node) {
			if (!mIsUpdating)
				mOwnedActors.Add(std::move(node));
			else
				mPendingActors.emplace_back(std::move(node));
		}
		void Remove(Actor* actor) {
			mOwnedActors.Remove(actor);
		}

		int GetUpdateOrder() const noexcept {
			return mUpdateOrder;
		}

		void SetState(State&& state) {
			mStateManager = std::move(state);
		}
		void SetState(const State& state) {
			mStateManager = state;
		}
		const State& GetState() const noexcept {
			return mStateManager;
		}

		Actor* GetOwner() const noexcept {
			return mOwner;
		}

		template<typename Policy,typename... Args>
		void InvokeActors(Args&& ...args) {
			mOwnedActors.Invoke<Policy>(std::forward(args)...);
		}
	};

}