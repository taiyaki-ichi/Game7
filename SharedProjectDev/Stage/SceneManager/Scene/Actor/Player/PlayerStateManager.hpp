#pragma once
#include"Stage/Utilty/State/StageStateManager.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"PlayerActive.hpp"

namespace GameLib
{
	class DrawAnimation;
}

namespace Stage
{
	class PlayerStateManager : public StateManager<char>
	{
		GameLib::DrawAnimation* mAnim;

	public:
		PlayerStateManager(GameLib::Actor* player, GameLib::DrawAnimation* anim)
			:StateManager<char>{ player }
			, mAnim{ anim }
		{
			SetState(new PlayerActive{ this,mAnim });
		}
		virtual ~PlayerStateManager() = default;

		void CustomizeUpdate() override;

		void SetPosition(const GameLib::Vector2& pos);
	};
}