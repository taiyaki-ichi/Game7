#pragma once

namespace Stage
{
	class StateBase;

	class StateManager
	{
		StateBase* mNowState;
		bool mIsAcitve;
		bool mIsUpdating;

	public:
		StateManager(StateBase* state = nullptr);
		virtual ~StateManager();

		void Update();

		void Active();
		void Pause();

		void SetState(StateBase* state);

		bool CheckFlag(char flag);
		void UpFlag(char flag);
		void DownFlag(char flag);
	};
}