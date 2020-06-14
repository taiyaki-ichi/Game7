#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Draw/DrawFillTriangle.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"

namespace Game::Stage
{
	class Ground : public GameLib::Actor
	{
		GameLib::Collider mCollider;
		GameLib::DrawFillTriangle mTriangle1;
		GameLib::DrawFillTriangle mTriangle2;

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
			, mTriangle1()
			, mTriangle2()
		{
			mCollider.Set(mPosition, mWidth, mHeigth, 1.f, 0.f);
			auto vecs = GameLib::GetRectangleVectors(mPosition, mWidth, mHeigth, 0.f);
			mTriangle1.SetPoints(vecs[0], vecs[1], vecs[2]);
			mTriangle2.SetPoints(vecs[2], vecs[3], vecs[0]);
			mTriangle1.SetColor({ 50,50,50,255 });
			mTriangle2.SetColor({ 50,50,50,255 });
		}
	};
}