#include"Player.hpp"

namespace Game::Stage
{
	Player::Player(Actor* owner, int updateOrder) :GravityActor(owner, updateOrder)
		, mAnimation(10)
		, mCollider("Player", { 0.f,-12.f }, 250.f, 500.f, 0.1f, 0.f, { 255,0,0,255 })
		, mPhisicsModel({ 0.f,200.f }, { 0.f,0.f })
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

			mPhisicsModel.mPosiotion += adjust;

			if (adjust.x * mPhisicsModel.mVelocity.x < 0.f)
				mPhisicsModel.mVelocity.x = 0.f;
			else if (adjust.y * mPhisicsModel.mVelocity.y < 0.f)
				mPhisicsModel.mVelocity.y = 0.f;

			if (dir4Vec.mDir4 == Dir4::Up) {
				mFlags |= JUMP_FLAG_1;
				mFlags |= ON_GROUND_FLAG;
			}

			if ((InputState::GetState(Key::A) == ButtonState::None &&
				InputState::GetState(Key::D) == ButtonState::None) ||
				(InputState::GetState(Key::A) == ButtonState::Held &&
					InputState::GetState(Key::D) == ButtonState::Held)||
				(InputState::GetState(Key::A) == ButtonState::Held&&
					GetDir4Size(mPhisicsModel.mVelocity,Dir4::Right)>0.f)||
				(InputState::GetState(Key::D) == ButtonState::Held&&
					GetDir4Size(mPhisicsModel.mVelocity, Dir4::Left) > 0.f
				))

			{
				if (dir4Vec.mDir4 == Dir4::Up) {
					if (mGravityDir4 == Dir4::Up || mGravityDir4 == Dir4::Down)
						mPhisicsModel.Friction(0.8f, 1.f);
					else
						mPhisicsModel.Friction(1.f, 0.8f);
				}
			}
			
			UpdateCollider();
			mAnimation.SetPosition(mPhisicsModel.mPosiotion);
			}
		);
	}

	void Player::CustomizeUpdate() 
	{
		auto power = GetPowerPerFrame();
		UpdatePhysicsModel(power);
		UpdateCollider();
		UpdateAnimation(power);

		mFlags &= ~ON_GROUND_FLAG;
		mFlags &= ~JUMP_FLAG_1;
	}


	GameLib::Vector2 Player::GetPowerPerFrame()
	{
		using namespace GameLib;
		Vector2 power{ 0.f,0.f };

		//重力
		if (~(mFlags & ON_GROUND_FLAG) &&
			GetDir4Size(mPhisicsModel.mVelocity, Dir4::Up) > 0.f &&
			InputState::GetState(Key::Space) == ButtonState::Held)
			power += GetGravityVec() * JUMPING_GRAVITY_RATE;
		else
			power += GetGravityVec();

		//向き
		if (InputState::GetState(Key::Left) == ButtonState::Pressed)
			mGravityDir4 = Dir4::Left;
		if (InputState::GetState(Key::Right) == ButtonState::Pressed)
			mGravityDir4 = Dir4::Right;
		if (InputState::GetState(Key::Up) == ButtonState::Pressed)
			mGravityDir4 = Dir4::Up;
		if (InputState::GetState(Key::Down) == ButtonState::Pressed)
			mGravityDir4 = Dir4::Down;

		//ヨコの力
		if (InputState::GetState(Key::A) == ButtonState::Pressed ||
			InputState::GetState(Key::A) == ButtonState::Held) {
			power += GetSubjectiveDirVec(Dir4::Left, RUN_POWER);
		}
		if (InputState::GetState(Key::D) == ButtonState::Pressed ||
			InputState::GetState(Key::D) == ButtonState::Held)
			power += GetSubjectiveDirVec(Dir4::Right, RUN_POWER);

		//ジャンプ
		if (InputState::GetState(Key::Space) == ButtonState::Pressed &&
			(mFlags & JUMP_FLAG_1)) {

			auto v = GetRoundedDir4Vec(mPhisicsModel.mVelocity);
			float rate = std::abs(v.mSize) / MAX_HORIZON_SPEED;
			power += GetSubjectiveDirVec(Dir4::Up, (JUMP_POWER_MAX - JUMP_POWER_MIN) * rate + JUMP_POWER_MIN);

			power += GetSubjectiveDirVec(Dir4::Up, JUMP_POWER_MAX);
			mFlags &= ~JUMP_FLAG_1;
		}

		return power;
	}

	//毎フレーム呼ぶ
	void Player::UpdateAnimation(const GameLib::Vector2& power) {
		mAnimation.Update();

		mAnimation.SetPosition(mPhisicsModel.mPosiotion);
		mAnimation.SetRotation(mPhisicsModel.mRotation);
		
		float horizonPowerDir = GetDir4Size(power, Dir4::Right);
		float verticalDir = GetDir4Size(mPhisicsModel.mVelocity, Dir4::Up);
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

	void Player::UpdateCollider()
	{
		mCollider.SetRotation(mPhisicsModel.mRotation);
		mCollider.SetPosition(mPhisicsModel.mPosiotion + GetSubjectiveDirVec(Dir4::Down, 12.f));
	}

	void Player::UpdatePhysicsModel(const GameLib::Vector2& power)
	{
		if (mGravityDir4 == Dir4::Up || mGravityDir4 == Dir4::Down)
			mPhisicsModel.Update(power, MAX_HORIZON_SPEED, MAX_VERTICAL_SPEED);
		else
			mPhisicsModel.Update(power, MAX_VERTICAL_SPEED, MAX_HORIZON_SPEED);

		if (mGravityDir4 == Dir4::Down)
			mPhisicsModel.mRotation = 0.f;
		else if (mGravityDir4 == Dir4::Up)
			mPhisicsModel.mRotation = GameLib::PI;
		else if (mGravityDir4 == Dir4::Right)
			mPhisicsModel.mRotation = GameLib::PI / 2.f;
		else
			mPhisicsModel.mRotation = GameLib::PI * 3.f / 2.f;

	}





}