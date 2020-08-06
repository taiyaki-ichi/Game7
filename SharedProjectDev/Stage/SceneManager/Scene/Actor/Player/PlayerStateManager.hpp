#pragma once
#include"Stage/Utilty/State/StageStateManager.hpp"
#include"PlayerStateBase.hpp"

namespace Stage::PlayerState
{

	class Manager : public StateManager<char>
	{
	public:
		Manager(StateBase* state)
			:StateManager<char>{state}
		{}
		virtual ~Manager() = default;

		void SetPosiotion(const GameLib::Vector2& pos)
		{
			if (mNowState)
			{
				auto playerState = static_cast<StateBase*>(mNowState);
				playerState->SetPosition(pos);
			}
		}

		void ResetPotentialPower()
		{
			if (mNowState)
			{
				auto playerState = static_cast<StateBase*>(mNowState);
				playerState->ResetPotentialPower();
			}
		}
	};
}