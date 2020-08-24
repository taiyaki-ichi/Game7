#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"DrawFlameRect.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace Stage
{
	class CursorButton : public GameLib::Actor
	{
		DrawFlameRect mFlameRect;

		bool mIsClicked;

	public:
		CursorButton(GameLib::Actor*, int drawOrder = 0);

		void CustomizeUpdate() override;

		void SetWidthAndHeight(float, float);
		void SetPosition(const GameLib::Vector2& pos);

		bool IsClicked() const;

	};
}