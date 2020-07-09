#include"StateManager.hpp"

namespace Game::Stage
{
	StateManager::StateManager(StateBase* state)
		:mNowState{state}
		,mIsAcitve{true}
		,mIsUpdating{false}
	{
	}

	StateManager::~StateManager()
	{
		if (mNowState)
			delete mNowState;
	}

	void StateManager::Update()
	{
		mIsUpdating = true;
		if (mIsAcitve)
		{
			StateBase* nextStateBase = nullptr;
			if (mNowState) {
				nextStateBase = mNowState->Update();

				if (mNowState != nextStateBase) {
					delete mNowState;
					mNowState = nextStateBase;
				}

			}
		}
		mIsUpdating = false;
			
	}

	int StateManager::GetFlag()
	{
		if (mNowState)
			return mNowState->GetFlag();
		else
			return -1;
	}

	void StateManager::Active()
	{
		mIsAcitve = true;
	}

	void StateManager::Pause()
	{
		mIsAcitve = false;
	}

	void StateManager::SetState(StateBase* state)
	{
		if (!mIsUpdating)
		{
			if (mNowState)
				delete mNowState;
			mNowState = state;
		}
	}

}