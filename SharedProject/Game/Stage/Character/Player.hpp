#pragma once
#include"GravityActor.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Game/Stage/PhysicsModel.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"Game/Stage/UtilityVectorFunction.hpp"


namespace Game::Stage
{
	class Player : public GravityActor
	{
		constexpr static float MAX_SPEED = 5.5f;
		//constexpr static  float JUMP_POWER_MAX = 11.5f;
		constexpr static  float JUMP_POWER_MAX = 21.5f;
		constexpr static  float JUMP_POWER_MIN = 9.5f;
		constexpr static  float RUN_POWER = 0.2f;


		GameLib::DrawAnimation mAnimation;
		GameLib::Collider mCollider;

		PhysicsModel mPhisicsModel;

		constexpr static char JUMP_FLAG_1 = 0b00000001;
		constexpr static char ON_GROUND_FLAG = 0b00000010;
		char mFlags;

	public:
		Player(Actor* owner, int updateOrder = 0)
			:GravityActor(owner, updateOrder)
			, mAnimation(10)
			, mCollider("Player", { 0.f,-12.f }, 250.f, 500.f, 0.1f, 0.f, { 255,0,0,255 })
			, mPhisicsModel({ 0.f,200.f }, { 0.f,0.f }, MAX_SPEED, 10.f)
			, mFlags(0)
		{
			using namespace GameLib;

			mAnimation.AddAnimation({ "../Assets/Player/stay001.png" });
			mAnimation.AddAnimation({ "../Assets/Player/run001.png","../Assets/Player/run002.png" ,"../Assets/Player/run003.png" });
			mAnimation.AddAnimation({ "../Assets/Player/up.png" });
			mAnimation.AddAnimation({ "../Assets/Player/down.png" });
			mAnimation.SetScale(0.1f);

			mCollider.AddHitFunction("Ground", [this](const GameLib::Collider& c) {
				auto adjust = GetParallelRectAdjustVec(mCollider, c);
				mPhisicsModel.AdjustPosiotion(adjust);
				if (std::abs(adjust.x) > 0.f)
					mPhisicsModel.ResetVelocityX();
				if (std::abs(adjust.y) > 0.f) {
					mPhisicsModel.ResetVelocityY();
					mFlags |= JUMP_FLAG_1;
					mFlags |= ON_GROUND_FLAG;
				}

				if ((InputState::GetState(Key::A) == ButtonState::None &&
					InputState::GetState(Key::D) == ButtonState::None) ||
					(InputState::GetState(Key::A) == ButtonState::Held &&
						InputState::GetState(Key::D) == ButtonState::Held))

				{
					if (adjust.y > 0.f)
						mPhisicsModel.Friction(0.8, 0.f);
					else
						mPhisicsModel.Friction(0.98, 0.f);
				}

				mCollider.SetPosition(mPhisicsModel.GetPosition() + GameLib::Vector2{ 0.f, -12.f });
				mAnimation.SetPosition(mPhisicsModel.GetPosition());
				}
			);
		}

		void CustomizeUpdate() override {

			auto power = GetPowerPerFrame();
			mPhisicsModel.Update(power);

			mCollider.SetPosition(mPhisicsModel.GetPosition() + GameLib::Vector2{ 0.f, -12.f });

			UpdateAnimation(power);

			mFlags &= ~ON_GROUND_FLAG;
		}

	private:
		GameLib::Vector2 GetPowerPerFrame() {
			using namespace GameLib;
			Vector2 power{ 0.f,0.f };

			//d—ÍAŒã‚Å•ÏX
			power += GetGravityVec();

			if (InputState::GetState(Key::A) == ButtonState::Pressed ||
				InputState::GetState(Key::A) == ButtonState::Held)
				power += GetSubjectiveDirVec(Dir4::Left, RUN_POWER);
			if (InputState::GetState(Key::D) == ButtonState::Pressed ||
				InputState::GetState(Key::D) == ButtonState::Held)
				power += GetSubjectiveDirVec(Dir4::Right, RUN_POWER);

			if (InputState::GetState(Key::Space) == ButtonState::Pressed &&
				(mFlags & JUMP_FLAG_1)) {

				auto velocityX = mPhisicsModel.GetVelocity() * GetSubjectiveDirVec(Dir4::Right, 1.f);
				float v= (std::abs(velocityX.x) > std::abs(velocityX.y)) ? velocityX.x : velocityX.y;
				float rate = std::abs(v) / MAX_SPEED;
				power += GetSubjectiveDirVec(Dir4::Up, (JUMP_POWER_MAX - JUMP_POWER_MIN) * rate + JUMP_POWER_MIN);

				mFlags &= ~JUMP_FLAG_1;
			}

			return power;
		}

		void UpdateAnimation(const GameLib::Vector2& power) {
			mAnimation.Update();

			auto gravity = mPhisicsModel.GetVelocity() * GetSubjectiveDirVec(Dir4::Up, 1.f);
			float dir = (std::abs(gravity.x) > std::abs(gravity.y)) ? gravity.x : gravity.y;
			if (!(mFlags & ON_GROUND_FLAG) && dir < 0.f)
				mAnimation.SetChannel(3);
			else if (!(mFlags & ON_GROUND_FLAG) && dir > 0.f)
				mAnimation.SetChannel(2);
			else if (power.x == 0.f)
				mAnimation.SetChannel(0);
			else
				mAnimation.SetChannel(1);

			if (power.x < 0.f)
				mAnimation.SetHorizontalFlip(true);
			else if (power.x > 0.f)
				mAnimation.SetHorizontalFlip(false);


			mAnimation.SetPosition(mPhisicsModel.GetPosition());
		}


	};
}