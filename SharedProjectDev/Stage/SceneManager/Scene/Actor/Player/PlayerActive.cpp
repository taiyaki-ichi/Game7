#include"PlayerActive.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"Stage/Utilty/Geometry.hpp"
#include"Stage/Utilty/Dir4Vec.hpp"
#include"Stage/Gravity/Gravity.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"PlayerParam.hpp"
#include"PlayerFlag.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"

namespace Stage
{
	PlayerActive::PlayerActive(StateManager<char>* manager, GameLib::DrawAnimation* anim)
		:PlayerStateBase{ manager }
		, mAnimation{ anim }
		, mCollider{}
		, mPhysicsModel{ anim->GetPosition(),GameLib::Vector2{0.f,0.f},0.1f,0.f }
		, mJumpFlag{ 0 }
	{
		using namespace GameLib;

		mCollider.Set(mPhysicsModel.mPosition, PlayerParam::WIDTH, PlayerParam::HEIGHT, PlayerParam::SCALE, 0.f);
		mCollider.SetColor({ 255,0,0,255 });
		AdjustCollider();

		auto hitGround = [this](const GameLib::Collider& c) {
			auto adjust = GetParallelRectAdjustVec(mCollider, c, 0.5f);
			auto dir4Vec = GetDir4Vec(adjust);

			/*
			std::cout << "adjust: " << adjust.x << "," << adjust.y << "\n";
			std::cout << "dir: ";
			if (dir4Vec.mDir4 == Dir4::Left)
				std::cout << "left";
			if (dir4Vec.mDir4 == Dir4::Right)
				std::cout << "right";
			if (dir4Vec.mDir4 == Dir4::Down)
				std::cout << "down";
			if (dir4Vec.mDir4 == Dir4::Up)
				std::cout << "up";
			std::cout << "\n";
			*/

			mPhysicsModel.mPosition += adjust;

			if (adjust.x * mPhysicsModel.mVelocity.x < 0.f)
				mPhysicsModel.mVelocity.x = 0.f;
			else if (adjust.y * mPhysicsModel.mVelocity.y < 0.f)
				mPhysicsModel.mVelocity.y = 0.f;

			if (dir4Vec.mSize > 0.f && dir4Vec.mDir4 == Dir4::Up) {
				UpFlag(PlayerFlag::ON_GROUND_FLAG);
				mJumpFlag = 1;
			}

			if ((InputState::GetState(Key::A) == ButtonState::None &&
				InputState::GetState(Key::D) == ButtonState::None) ||
				(InputState::GetState(Key::A) == ButtonState::Held &&
					InputState::GetState(Key::D) == ButtonState::Held) ||
				(InputState::GetState(Key::A) == ButtonState::Held &&
					GetDir4DirectionSize(mPhysicsModel.mVelocity, Dir4::Right) > 0.f) ||
				(InputState::GetState(Key::D) == ButtonState::Held &&
					GetDir4DirectionSize(mPhysicsModel.mVelocity, Dir4::Left) > 0.f
					))

			{
				if (dir4Vec.mDir4 == Dir4::Up) {
					if (Gravity::GetDir4() == Dir4::Up || Gravity::GetDir4() == Dir4::Down)
						mPhysicsModel.Friction(0.8f, 1.f);
					else
						mPhysicsModel.Friction(1.f, 0.8f);
				}
			}

			AdjustCollider();
			mAnimation->SetPosition(mPhysicsModel.mPosition);
		};

		auto hitEnemyWeakness = [this](const GameLib::Collider& c) {
			float upSize = GetDir4DirectionSize(mPhysicsModel.mVelocity, Dir4::Up);
			//�G�𓥂񂾂班���W�����v
			mPhysicsModel.mVelocity += GetVector2(Dir4::Up, -upSize + 3.f);

			//4�t���[���̊Ԃ̓W�����v�ł���
			mJumpFlag = 4;
		};

		auto hitEnemyStrength = [this](const GameLib::Collider& c) {
			UpFlag(PlayerFlag::DEATH_FLAG);
		};

		mCollider.AddHitFunction("Ground", std::move(hitGround));
		mCollider.AddHitFunction("TripleWeakness", hitEnemyWeakness);
		mCollider.AddHitFunction("TripleStrength", hitEnemyStrength);
		mCollider.AddHitFunction("TogeStrength", hitEnemyStrength);

	}

	void PlayerActive::CustomizeUpdate()
	{

		//std::cout << (mFlags & ON_GROUND_FLAG);

		auto power = GetPowerPerFrame();
		UpdatePhysicsModelWithGravity(mPhysicsModel, power, PlayerParam::MAX_HORIZON_SPEED, PlayerParam::MAX_VERTICAL_SPEED);

		AdjustCollider();
		UpdateAnimation(std::move(power));

		DownFlag(PlayerFlag::ON_GROUND_FLAG);

		//std::cout << "jumpFlag: " << mJumpFlag << "\n";

		if (mJumpFlag > 0)
			mJumpFlag--;

		//std::cout << "player pos: " << mPhysicsModel.mPosition.x << "," << mPhysicsModel.mPosition.y << "\n";

	}

	void PlayerActive::Active()
	{
		
	}

	void PlayerActive::Pause()
	{
	}

	void PlayerActive::SetPosition(const GameLib::Vector2& pos)
	{
		mPhysicsModel.mPosition = pos;
		mAnimation->SetPosition(pos);
		AdjustCollider();
	}

	void PlayerActive::AdjustCollider()
	{
		mCollider.SetRotation(mPhysicsModel.mRotation);

		//Anim��Collder�̈ʒu�������悤�ɒ���
		mCollider.SetPosition(mPhysicsModel.mPosition + GetVector2(Dir4::Down, 12.f));
	}

	GameLib::Vector2 PlayerActive::GetPowerPerFrame()
	{
		using namespace GameLib;
		Vector2 power{ 0.f,0.f };

		//�d��
		if (CheckFlag(PlayerFlag::ON_GROUND_FLAG) &&
			GetDir4DirectionSize(mPhysicsModel.mVelocity, Dir4::Up) > 0.f &&
			InputState::GetState(Key::Space) == ButtonState::Held)
			power += Gravity::GetVector2() * PlayerParam::JUMPING_GRAVITY_RATE;
		else
			power += Gravity::GetVector2();

		//���R�̗�
		if (InputState::GetState(Key::A) == ButtonState::Pressed ||
			InputState::GetState(Key::A) == ButtonState::Held) {
			power += GetVector2(Dir4::Left, PlayerParam::RUN_POWER);
		}
		if (InputState::GetState(Key::D) == ButtonState::Pressed ||
			InputState::GetState(Key::D) == ButtonState::Held)
			power += GetVector2(Dir4::Right, PlayerParam::RUN_POWER);

		//�W�����v
		if (InputState::GetState(Key::Space) == ButtonState::Pressed &&
			(mJumpFlag > 0)) {

			auto v = GetDir4Vec(mPhysicsModel.mVelocity);
			float rate = std::abs(v.mSize) / PlayerParam::MAX_HORIZON_SPEED;
			power += GetVector2(Dir4::Up, (PlayerParam::JUMP_POWER_MAX - PlayerParam::JUMP_POWER_MIN) * rate + PlayerParam::JUMP_POWER_MIN);

			mJumpFlag = 0;
		}

		//std::cout << "power: "<<power.x << "," << power.y << "\n";
		return power;
	}

	void PlayerActive::UpdateAnimation(GameLib::Vector2&& power)
	{
		mAnimation->Update();

		mAnimation->SetPosition(mPhysicsModel.mPosition);
		mAnimation->SetRotation(mPhysicsModel.mRotation);

		float horizonPowerDir = GetDir4DirectionSize(power, Dir4::Right);
		float verticalDir = GetDir4DirectionSize(mPhysicsModel.mVelocity, Dir4::Up);
		if (!CheckFlag(PlayerFlag::ON_GROUND_FLAG) && verticalDir < 0.f)
			mAnimation->SetChannel(3);
		else if (!CheckFlag(PlayerFlag::ON_GROUND_FLAG) && verticalDir > 0.f)
			mAnimation->SetChannel(2);
		else if (horizonPowerDir == 0.f)
			mAnimation->SetChannel(0);
		else
			mAnimation->SetChannel(1);

		if (horizonPowerDir > 0.f)
			mAnimation->SetHorizontalFlip(false);
		else if (horizonPowerDir < 0.f)
			mAnimation->SetHorizontalFlip(true);
	}







}