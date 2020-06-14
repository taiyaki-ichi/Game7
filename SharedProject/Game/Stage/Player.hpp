#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"UtilityVectorFunction.hpp"

namespace Game::Stage
{
	class Player : public GameLib::Actor
	{

		GameLib::DrawAnimation mAnimation;
		GameLib::Collider mCollider;

		GameLib::Vector2 mPosition;

	public:
		Player(Actor* owner, int updateOrder = 0)
			:Actor(owner, updateOrder)
			, mPosition({ 0.f,200.f })
			, mAnimation(10)
			, mCollider("Player", { 0.f,-12.f }, 250.f, 500.f, 0.1f, 0.f, { 255,0,0,255 })
		{
			mAnimation.AddAnimation({ "../Assets/run001.png","../Assets/run002.png" ,"../Assets/run002.png" });
			mAnimation.SetScale(0.1f);

			mCollider.AddHitFunction("Ground", [this](const GameLib::Collider& c) {
				auto adjust = GetParallelRectAdjustVec(mCollider, c);
				mPosition += adjust;
				mCollider.SetPosition(mPosition + Vector2{ 0.f, -12.f });
				mAnimation.SetPosition(mPosition);
				});
		}

		void CustomizeUpdate() override {
			mAnimation.Update();
			mPosition += {0.f,-1.f};
			mCollider.SetPosition(mPosition + Vector2{ 0.f, -12.f });
			mAnimation.SetPosition(mPosition);
		}


	};
}