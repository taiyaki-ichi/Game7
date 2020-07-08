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

	private:
		int mUpdateOrder;
		State mState;

		ActorsManager<Actor> mOwnedActors;
		//Update中に追加された場合ここに一時保存
		std::vector<Node<Actor>> mPendingActors;
		bool mIsUpdating;

	public:
		Actor(Actor* owner, int updateOrder = 0)
			:mOwner(owner)
			, mUpdateOrder(updateOrder)
			,mOwnedActors()
			,mState(State::Active)
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
			mState = std::move(state);
		}
		void SetState(const State& state) {
			mState = state;
		}
		const State& GetState() const noexcept {
			return mState;
		}

		Actor* GetOwner() const noexcept {
			return mOwner;
		}
	};

}