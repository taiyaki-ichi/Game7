#pragma once
#include"GravityActor.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Game/Stage/PhysicsModel.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"Game/Stage/UtilityVectorFunction.hpp"
#include"GameLib/include/Math/Numbers.hpp"


namespace Game::Stage
{
	class Player : public GravityActor
	{
		constexpr static float MAX_SPEED = 5.5f;
		constexpr static  float JUMP_POWER_MAX = 9.f;
		constexpr static  float JUMP_POWER_MIN = 7.f;
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
			, mPhisicsModel({ 0.f,200.f }, { 0.f,0.f }, MAX_SPEED)
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
				auto dir4Vec = GetRoundedDir4Vec(adjust);

				mPhisicsModel.AdjustPosiotion(adjust);

				
				if (adjust.x * mPhisicsModel.GetVelocity().x < 0.f)
					mPhisicsModel.ResetVelocityX();
				else if (adjust.y * mPhisicsModel.GetVelocity().y < 0.f)
					mPhisicsModel.ResetVelocityY();
					
				if (dir4Vec.mDir4 == Dir4::Up) {
					mFlags |= JUMP_FLAG_1;
					mFlags |= ON_GROUND_FLAG;
				}

				
				if ((InputState::GetState(Key::A) == ButtonState::None &&
					InputState::GetState(Key::D) == ButtonState::None) ||
					(InputState::GetState(Key::A) == ButtonState::Held &&
						InputState::GetState(Key::D) == ButtonState::Held))

				{
					if (dir4Vec.mDir4 == Dir4::Up) {
						if (mGravityDir4 == Dir4::Up || mGravityDir4 == Dir4::Down)
							mPhisicsModel.Friction(0.8f, 1.f);
						else
							mPhisicsModel.Friction(1.f, 0.8f);
					}
				}
			

				if (mGravityDir4 == Dir4::Down) {
					mCollider.SetPosition(mPhisicsModel.GetPosition() + GameLib::Vector2{ 0.f, -12.f });
				}
				else if (mGravityDir4 == Dir4::Up) {
					mCollider.SetPosition(mPhisicsModel.GetPosition() + GameLib::Vector2{ 0.f, 12.f });
				}
				else if (mGravityDir4 == Dir4::Right) {
					mCollider.SetPosition(mPhisicsModel.GetPosition() + GameLib::Vector2{ 12.f, 0.f });
				}
				else {
					mCollider.SetPosition(mPhisicsModel.GetPosition() + GameLib::Vector2{ -12.f, 0.f });
				}
				mAnimation.SetPosition(mPhisicsModel.GetPosition());
				}
			);
		}

		void CustomizeUpdate() override {

			auto power = GetPowerPerFrame();
			mPhisicsModel.Update(power);

			if (mGravityDir4 == Dir4::Down) {
				mCollider.SetWidthAndHeith(250.f, 500.f);
				mCollider.SetPosition(mPhisicsModel.GetPosition() + GameLib::Vector2{ 0.f, -12.f });
			}
			else if (mGravityDir4 == Dir4::Up) {
				mCollider.SetWidthAndHeith(250.f, 500.f);
				mCollider.SetPosition(mPhisicsModel.GetPosition() + GameLib::Vector2{ 0.f, 12.f });
			}
			else if (mGravityDir4 == Dir4::Right) {
				mCollider.SetWidthAndHeith(500.f, 250.f);
				mCollider.SetPosition(mPhisicsModel.GetPosition() + GameLib::Vector2{ 12.f, 0.f });
			}
			else {
				mCollider.SetWidthAndHeith(500.f, 250.f);
				mCollider.SetPosition(mPhisicsModel.GetPosition() + GameLib::Vector2{ -12.f, 0.f });
			}

			UpdateAnimation(power);

			mFlags &= ~ON_GROUND_FLAG;
			mFlags &= ~JUMP_FLAG_1;
		}

	private:
		GameLib::Vector2 GetPowerPerFrame() {
			using namespace GameLib;
			Vector2 power{ 0.f,0.f };

			//d—ÍAŒã‚Å•ÏX
			power += GetGravityVec();

			if (InputState::GetState(Key::Left) == ButtonState::Pressed)
				mGravityDir4 = Dir4::Left;
			if (InputState::GetState(Key::Right) == ButtonState::Pressed)
				mGravityDir4 = Dir4::Right;
			if (InputState::GetState(Key::Up) == ButtonState::Pressed)
				mGravityDir4 = Dir4::Up;
			if (InputState::GetState(Key::Down) == ButtonState::Pressed)
				mGravityDir4 = Dir4::Down;

			if (InputState::GetState(Key::A) == ButtonState::Pressed ||
				InputState::GetState(Key::A) == ButtonState::Held)
				power += GetSubjectiveDirVec(Dir4::Left, RUN_POWER);
			if (InputState::GetState(Key::D) == ButtonState::Pressed ||
				InputState::GetState(Key::D) == ButtonState::Held)
				power += GetSubjectiveDirVec(Dir4::Right, RUN_POWER);

			if (InputState::GetState(Key::Space) == ButtonState::Pressed &&
				(mFlags & JUMP_FLAG_1)) {

				
				auto v = GetRoundedDir4Vec(mPhisicsModel.GetVelocity());
				float rate = std::abs(v.mSize) / MAX_SPEED;
				power += GetSubjectiveDirVec(Dir4::Up, (JUMP_POWER_MAX - JUMP_POWER_MIN) * rate + JUMP_POWER_MIN);
				
				power += GetSubjectiveDirVec(Dir4::Up, JUMP_POWER_MAX);
				mFlags &= ~JUMP_FLAG_1;
			}

			return power;
		}

		void UpdateAnimation(const GameLib::Vector2& power) {
			mAnimation.Update();

			mAnimation.SetPosition(mPhisicsModel.GetPosition());

			if (mGravityDir4 == Dir4::Down)
				mAnimation.SetRotation(0.f);
			else if (mGravityDir4 == Dir4::Right)
				mAnimation.SetRotation(GameLib::PI / 2.f);
			else if (mGravityDir4 == Dir4::Up)
				mAnimation.SetRotation(GameLib::PI);
			else
				mAnimation.SetRotation(-GameLib::PI / 2.f);


			float horizonPowerDir = GetDir4Size(power, Dir4::Right);
			float verticalDir = GetDir4Size(mPhisicsModel.GetVelocity(), Dir4::Up);
			if (!(mFlags & ON_GROUND_FLAG) && verticalDir < 0.f)
				mAnimation.SetChannel(3);
			else if (!(mFlags & ON_GROUND_FLAG) && verticalDir > 0.f)
				mAnimation.SetChannel(2);
			else if (horizonPowerDir == 0.f)
				mAnimation.SetChannel(0);
			else
				mAnimation.SetChannel(1);
			
			if (horizonPowerDir > 0.f)
				mAnimation.SetHorizontalFlip(false);
			else if (horizonPowerDir < 0.f)
				mAnimation.SetHorizontalFlip(true);
		}


	};
}