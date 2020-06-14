#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"UtilityVectorFunction.hpp"
#include"PhisicModel.hpp"
#include"GameLib/include/InputState/InputState.hpp"

namespace Game::Stage
{
	class Player : public GameLib::Actor
	{

		GameLib::DrawAnimation mAnimation;
		GameLib::Collider mCollider;

		PhysicModel mPhisicsModel;

	public:
		Player(Actor* owner, int updateOrder = 0)
			:Actor(owner, updateOrder)
			, mAnimation(10)
			, mCollider("Player", { 0.f,-12.f }, 250.f, 500.f, 0.1f, 0.f, { 255,0,0,255 })
			, mPhisicsModel({ 0.f,200.f }, {0.f,0.f},5.f,10.f)
		{
			mAnimation.AddAnimation({ "../Assets/run001.png","../Assets/run002.png" ,"../Assets/run002.png" });
			mAnimation.SetScale(0.1f);

			mCollider.AddHitFunction("Ground", [this](const GameLib::Collider& c) {
				auto adjust = GetParallelRectAdjustVec(mCollider, c);
				mPhisicsModel.AdjustPosiotion(adjust);
				if (std::abs(adjust.x) > 0.f) 
					mPhisicsModel.ResetVelocityX();
				if (std::abs(adjust.y) > 0.f)
					mPhisicsModel.ResetVelocityY();

				if (adjust.y > 0.f)
					mPhisicsModel.Friction(0.8, 0.f);
				else
					mPhisicsModel.Friction(0.98, 0.f);

				mCollider.SetPosition(mPhisicsModel.GetPosition() + Vector2{ 0.f, -12.f });
				mAnimation.SetPosition(mPhisicsModel.GetPosition());
				});
		}

		void CustomizeUpdate() override {
			mAnimation.Update();
			Vector2 add = { 0.f,-0.5f };
			if (GameLib::InputState::GetState(GameLib::Key::A) == GameLib::ButtonState::Held)
				add += {-0.5f, 0.f};
			if (GameLib::InputState::GetState(GameLib::Key::D) == GameLib::ButtonState::Held)
				add += {0.5f, 0.f};
			if (GameLib::InputState::GetState(GameLib::Key::Space) == GameLib::ButtonState::Pressed)
				add += {0.f, 10.f};
			
			mPhisicsModel.Update(add);

			mCollider.SetPosition(mPhisicsModel.GetPosition() + Vector2{ 0.f, -12.f });
			mAnimation.SetPosition(mPhisicsModel.GetPosition());
		}


	};
}