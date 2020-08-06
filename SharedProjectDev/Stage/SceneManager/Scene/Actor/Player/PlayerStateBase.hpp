#pragma once
#include"Stage/Utilty/State/StageStateBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"


namespace Stage::PlayerState
{
	class StateBase : public Stage::StateBase<char>
	{
	public:
		StateBase() = default;
		virtual ~StateBase() = default;

		//Warpとか用
		virtual void SetPosition(const GameLib::Vector2& pos) = 0;

		//速度なんかをリセット
		virtual void ResetPotentialPower() {};
	};
}