#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"StageStateBase.hpp"

namespace Stage
{
	template<typename T>
	class StateBase;

	template<typename T=char>
	class StateManager : public GameLib::Actor
	{
	protected:
		StateBase<T>* mNowState;

	public:
		StateManager(GameLib::Actor* owner)
			:GameLib::Actor{owner}
			, mNowState{nullptr}
		{}

		virtual ~StateManager() = default;

		void Active()
		{
			if (mNowState)
				mNowState->Active();
		}
		void Pause()
		{
			if (mNowState)
				mNowState->Pause();
		}

		void SetState(StateBase<T>* state)
		{
			if (mNowState)
				mNowState->SetState(GameLib::Actor::State::Dead);
			mNowState = state;
		}

		bool CheckFlag(T flag)
		{
			if (mNowState)
				return mNowState->CheckFlag(flag);
			else
				return false;
		}
		void UpFlag(T flag)
		{
			if (mNowState)
				mNowState->UpFlag(flag);
		}
		void DownFlag(T flag)
		{
			if (mNowState)
				mNowState->DownFlag(flag);
		}
	};
}