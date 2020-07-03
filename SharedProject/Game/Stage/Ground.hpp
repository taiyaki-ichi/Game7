#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace Game::Stage
{
	class Ground : public GameLib::Actor
	{
		GameLib::Collider mCollider;
		GameLib::DrawRect mDrawRect;

		GameLib::Vector2 mPosition;
		float mWidth;
		float mHeigth;

	public:
		Ground(Actor* owner, GameLib::Vector2&& pos, float width, float heigth, int updateOrder = 0)
			:Actor(owner, updateOrder)
			, mPosition(std::move(pos))
			, mWidth(width)
			, mHeigth(heigth)
			, mCollider("Ground")
			, mDrawRect{}
		{
			mCollider.Set(mPosition, mWidth, mHeigth, 1.f, 0.f);

			mDrawRect.Set(mPosition, 1.f, 0.f);
			mDrawRect.SetWidthAndHeight(mWidth, mHeigth);
			mDrawRect.SetColor({ 50,50,50,255 });
		}
	};
}