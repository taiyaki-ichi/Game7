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
		GameLib::DrawRect mRect;

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
			, mRect{}
		{
			mCollider.Set(mPosition, mWidth, mHeigth, 1.f, 0.f);

			mRect.Set(mPosition, 1.f, 0.f);
			mRect.SetWidthAndHeight(mWidth, mHeigth);
			mRect.SetColor({ 50,50,50,255 });
		}
	};
}