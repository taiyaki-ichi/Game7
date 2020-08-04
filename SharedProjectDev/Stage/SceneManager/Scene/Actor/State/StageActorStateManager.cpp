#include"StageActorStateManager.hpp"
#include"StageActorStateBase.hpp"

namespace Stage
{
	StateManager::StateManager(StateBase* state)
		:mNowState{ state }
		, mIsAcitve{ true }
		, mIsUpdating{ false }
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

	bool StateManager::CheckFlag(char flag)
	{
		if (mNowState)
			return mNowState->CheckFlag(flag);
		else
			return false;
	}

	void StateManager::UpFlag(char flag)
	{
		if (mNowState)
			mNowState->UpFlag(flag);
	}

	void StateManager::DownFlag(char flag)
	{
		if (mNowState)
			mNowState->DownFlag(flag);
	}



}