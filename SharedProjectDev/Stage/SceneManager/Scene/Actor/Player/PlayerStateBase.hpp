#pragma once
#include"Stage/Utilty/State/StageStateBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"

namespace Stage
{
	class PlayerStateBase : public StateBase<char>
	{
	public:
		PlayerStateBase(StateManager<char>* manager)
			:StateBase<char>{manager}
		{}
		virtual ~PlayerStateBase() = default;

		//Warp‚Æ‚©—p
		virtual void SetPosition(const GameLib::Vector2& pos) = 0;
	};
}