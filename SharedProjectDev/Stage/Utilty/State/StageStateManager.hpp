#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"StageStateBase.hpp"

namespace Stage
{
	template<typename T>
	class StateBase;

	template<typename T=char>
	class StateManager 
	{
		bool mIsWorking;

	protected:
		StateBase<T>* mNowState;

	public:
		StateManager(StateBase<T>* state)
			: mNowState{state}
			, mIsWorking{true}
		{}

		virtual ~StateManager()
		{
			if (mNowState)
				delete mNowState;
		}

		void Update()
		{
			if (mNowState && mIsWorking) {
				StateBase<T>* state = mNowState->Update();
				if (state != mNowState) {
					delete mNowState;
					mNowState = state;
				}
			}	
		}

		void SetStartState(StateBase<T>* state)
		{
			if (!mNowState)
				mNowState = state;
			else if (state)
				delete state;
		}

		void BeginWorking()
		{
			if (mNowState)
				mNowState->BeginWorking();
			mIsWorking = true;
		}
		void BeginToRest()
		{
			if (mNowState)
				mNowState->BeginToRest();
			mIsWorking = false;
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