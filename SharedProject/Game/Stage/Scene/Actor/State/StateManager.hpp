#pragma once
#include"StateBase.hpp"

namespace Game::Stage
{
	class StateManager
	{
		StateBase* mNowState;
		bool mIsAcitve;
		bool mIsUpdating;

	public:
		StateManager(StateBase* state = nullptr);
		virtual ~StateManager();

		void Update();

		int GetFlag();

		void Active();
		void Pause();

		void SetState(StateBase* state);
	};
}