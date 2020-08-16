#include"PlayerActive.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"Stage/Utilty/Geometry.hpp"
#include"Stage/Utilty/Dir4Vec.hpp"
#include"Stage/Gravity/Gravity.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"PlayerParam.hpp"
#include"PlayerFlag.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"PlayerDeath.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Stage/WindowSize.hpp"
#include"Life/Life.hpp"
#include"ItemNum/ItemNum.hpp"

#include<iostream>

namespace Stage::PlayerState
{

	Active::Active(GameLib::DrawAnimation* anim, Stage::Life* life,Stage::ItemNum* itemNum)
		:StateBase{}
		, mAnimation{ anim }
		, mCollider{}
		, mPhysicsModel{ anim->GetPosition(),GameLib::Vector2{0.f,0.f},0.1f,0.f }
		, mJumpFlag{ 0 }
		, mInvincibleCnt{-1}
		, mLife{life}
		, mItemNum{itemNum}
	{
		using namespace GameLib;

		mCollider.SetNameTag("Player");
		mCollider.Set(mPhysicsModel.mPosition, PlayerParam::WIDTH, PlayerParam::HEIGHT, PlayerParam::SCALE, 0.f);
		mCollider.SetColor({ 255,0,0,255 });
		AdjustCollider();

		auto hitGround = [this](const GameLib::Collider& c) {
			GameLib::Vector2 adjust{};

			//Gravity以下のXを切り捨て引っかかりをなくす
			if (Gravity::GetDir4() == Dir4::Down || Gravity::GetDir4() == Dir4::Up)
				adjust = GetParallelRectAdjustVec(mCollider, c, 1.f, 0.f);
			else
				adjust = GetParallelRectAdjustVec(mCollider, c, 0.f, 1.f);
			auto dir4Vec = GetDir4Vec(adjust);

			//std::cout << "c wigth: " << c.GetWidth() << "\n";
			//std::cout << "c height: " << c.GetHeigth() << "\n";
			//std::cout << "adjust: " << adjust.x << "," << adjust.y << "\n";
			/*
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

			if (dir4Vec.mSize > 0.f && dir4Vec.mDir4 == Dir4::Up) {
				UpFlag(PlayerFlag::ON_GROUND_FLAG);
				mJumpFlag = 1;

				//ADが押されいているときはヨコの向きには補正しない
				if (InputState::GetState(Key::A) == ButtonState::None &&
					InputState::GetState(Key::D) == ButtonState::None)
					adjust += c.GetRerativePos();
				else
				{
					adjust += GetDirSizeSetVector2(c.GetRerativePos(), Dir4::Right, 0.f);
				}
				//std::cout << c.GetRerativePos().x << "," << c.GetRerativePos().y << "\n";
			}


			mPhysicsModel.mPosition += adjust;

			if (adjust.x * mPhysicsModel.mVelocity.x < 0.f)
				mPhysicsModel.mVelocity.x = 0.f;
			else if (adjust.y * mPhysicsModel.mVelocity.y < 0.f)
				mPhysicsModel.mVelocity.y = 0.f;

			//A,Dが押されているときなどは摩擦の影響なし
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

			/*
			//ゴールの時は簡単に止まるように
			if (CheckFlag(PlayerFlag::GOAL_FLAG)) {
				if (Gravity::GetDir4() == Dir4::Up || Gravity::GetDir4() == Dir4::Down)
					mPhysicsModel.Friction(0.8f, 1.f);
				else
					mPhysicsModel.Friction(1.f, 0.8f);
			}
			*/

			AdjustCollider();
			mAnimation->SetPosition(mPhysicsModel.mPosition);
		};


		auto hitEnemyWeakness = [this](const GameLib::Collider& c) {
			float upSize = GetDir4DirectionSize(mPhysicsModel.mVelocity, Dir4::Up);
			//敵を踏んだら少しジャンプ
			mPhysicsModel.mVelocity += GetVector2(Dir4::Up, -upSize + 3.f);

			//4フレームの間はジャンプできる
			mJumpFlag = 4;
		};

		auto hitEnemyStrength = [this](const GameLib::Collider& c) {
			//UpFlag(PlayerFlag::DEATH_FLAG);
			if (mInvincibleCnt < 0) {
				SufferDamage();
				mLife->Damage();
			}
			
		};

		auto hitGravituBox = [this](const GameLib::Collider& c) {
			auto adjust = GetParallelRectAdjustVec(mCollider, c);
			auto dir4Adjust = GetDir4Vec(std::move(adjust));
			if (dir4Adjust.mDir4 == Dir4::Down)
				ResetPotentialPower();
		};

		auto hitGoal = [this](const GameLib::Collider& c) {
			UpFlag(PlayerFlag::GOAL_FLAG);
		};

		auto hitGem = [this](const GameLib::Collider& c) {
			mItemNum->AddGem();
		};

		auto hitTearGem1= [this](const GameLib::Collider& c) {
			mItemNum->AddTearGem(1);
		};

		auto hitTearGem2 = [this](const GameLib::Collider& c) {
			mItemNum->AddTearGem(2);
		};

		auto hitTearGem3 = [this](const GameLib::Collider& c) {
			mItemNum->AddTearGem(3);
		};

		auto hitThroughFloor = [this,hitGround](const GameLib::Collider& c) {
			auto adjust = GetParallelRectAdjustVec(mCollider, c, 0.5f);
			auto dir4Vec = GetDir4Vec(adjust);
			if (dir4Vec.mDir4 == Dir4::Up && GetDir4DirectionSize(mPhysicsModel.mVelocity, Dir4::Down) > 0.f)
				hitGround(c);
		};

		mCollider.AddHitFunction("ThroughFloor", hitThroughFloor);
		mCollider.AddHitFunction("Ground", std::move(hitGround));
		mCollider.AddHitFunction("TripleWeakness", hitEnemyWeakness);
		mCollider.AddHitFunction("TripleStrength", hitEnemyStrength);
		mCollider.AddHitFunction("TogeBody", hitEnemyStrength);
		mCollider.AddHitFunction("GravityBox", std::move(hitGravituBox));
		mCollider.AddHitFunction("Goal", std::move(hitGoal));
		mCollider.AddHitFunction("Gem", std::move(hitGem));
		mCollider.AddHitFunction("TearGem1", std::move(hitTearGem1));
		mCollider.AddHitFunction("TearGem2", std::move(hitTearGem2));
		mCollider.AddHitFunction("TearGem3", std::move(hitTearGem3));
		mCollider.AddHitFunction("FrogWeakness", hitEnemyWeakness);
		mCollider.AddHitFunction("FrogStrength", hitEnemyStrength);

	}

	Stage::StateBase<char>* Active::Update()
	{

		//std::cout << (mFlags & ON_GROUND_FLAG);

		//std::cout << "player active pos1: " << mPhysicsModel.mPosition.x << "," << mPhysicsModel.mPosition.y << "\n";
		//std::cout << mInvincibleCnt << "\n";
		if (mInvincibleCnt > 0)
			mInvincibleCnt--;
		if (mInvincibleCnt == 0) {
			mCollider.SetNameTag("Player");
			mInvincibleCnt--;
		}

		CheckFallDeath();

		if (mLife->IsLifeZero())
			UpFlag(PlayerFlag::DEATH_FLAG);

		if (CheckFlag(PlayerFlag::DEATH_FLAG))
			return new Death{ mAnimation };

		auto power = GetPowerPerFrame();
		UpdatePhysicsModelWithGravity(mPhysicsModel, power, PlayerParam::MAX_HORIZON_SPEED, PlayerParam::MAX_VERTICAL_SPEED);

		AdjustCollider();
		UpdateAnimation(std::move(power));

		DownFlag(PlayerFlag::ON_GROUND_FLAG);

		//std::cout << "jumpFlag: " << mJumpFlag << "\n";

		if (mJumpFlag > 0)
			mJumpFlag--;
			
		//std::cout << "player active pos2: " << mPhysicsModel.mPosition.x << "," << mPhysicsModel.mPosition.y << "\n";

		if (CheckFlag(PlayerFlag::GOAL_FLAG)) {
			mPhysicsModel.Friction(0.9f, 0.9f);
		}

		return this;
	}


	void Active::SetPosition(const GameLib::Vector2& pos)
	{
		//std::cout << "set pos: " << pos.x << "," << pos.y << "\n";
		mPhysicsModel.mPosition = pos;
		mAnimation->SetPosition(pos);
		AdjustCollider();
	}

	void Active::ResetPotentialPower()
	{
		mPhysicsModel.mVelocity = GameLib::Vector2{};
	}

	void Active::AdjustCollider()
	{
		mCollider.SetRotation(mPhysicsModel.mRotation);

		//AnimにCollderの位置が合うように調整
		mCollider.SetPosition(mPhysicsModel.mPosition + GetVector2(Dir4::Down, PlayerParam::COLLIDER_ADJUST_DOWN_SIZE));
	}


	GameLib::Vector2 Active::GetPowerPerFrame()
	{
		using namespace GameLib;
		Vector2 power{ 0.f,0.f };

		//重力
		if (CheckFlag(PlayerFlag::ON_GROUND_FLAG) &&
			GetDir4DirectionSize(mPhysicsModel.mVelocity, Dir4::Up) > 0.f &&
			InputState::GetState(Key::Space) == ButtonState::Held)
			power += Gravity::GetVector2() * PlayerParam::JUMPING_GRAVITY_RATE;
		else
			power += Gravity::GetVector2();

		//ゴールしたら動けない
		if (!CheckFlag(PlayerFlag::GOAL_FLAG))
		{
			//ヨコの力
			if (InputState::GetState(Key::A) == ButtonState::Pressed ||
				InputState::GetState(Key::A) == ButtonState::Held) {
				power += GetVector2(Dir4::Left, PlayerParam::RUN_POWER);
			}
			if (InputState::GetState(Key::D) == ButtonState::Pressed ||
				InputState::GetState(Key::D) == ButtonState::Held)
				power += GetVector2(Dir4::Right, PlayerParam::RUN_POWER);

			//ジャンプ
			if (InputState::GetState(Key::Space) == ButtonState::Pressed &&
				(mJumpFlag > 0)) {

				auto v = GetDir4Vec(mPhysicsModel.mVelocity);
				float rate = std::abs(v.mSize) / PlayerParam::MAX_HORIZON_SPEED;
				power += GetVector2(Dir4::Up, (PlayerParam::JUMP_POWER_MAX - PlayerParam::JUMP_POWER_MIN) * rate + PlayerParam::JUMP_POWER_MIN);

				mJumpFlag = 0;
			}
		}

		//std::cout << "power: "<<power.x << "," << power.y << "\n";
		return power;
	}



	void Active::UpdateAnimation(GameLib::Vector2&& power)
	{
		mAnimation->Update();

		mAnimation->SetPosition(mPhysicsModel.mPosition);
		mAnimation->SetRotation(mPhysicsModel.mRotation);

		float horizonPowerDir = GetDir4DirectionSize(power, Dir4::Right);
		float verticalDir = GetDir4DirectionSize(mPhysicsModel.mVelocity, Dir4::Up);
		int channel;
		if (!CheckFlag(PlayerFlag::ON_GROUND_FLAG) && verticalDir < 0.f)
			channel = 3;
		else if (!CheckFlag(PlayerFlag::ON_GROUND_FLAG) && verticalDir > 0.f)
			channel = 2;
		else if (horizonPowerDir == 0.f)
			channel = 0;
		else
			channel = 1;

		if (mInvincibleCnt > 0)
			channel += 4;
		
		mAnimation->SetChannel(channel);

		if (horizonPowerDir > 0.f)
			mAnimation->SetHorizontalFlip(false);
		else if (horizonPowerDir < 0.f)
			mAnimation->SetHorizontalFlip(true);

		//std::cout << mAnimation->GetChannel()<<"\n";
	}

	void Active::CheckFallDeath()
	{
		auto pos = GameLib::Affine(mPhysicsModel.mPosition, GameLib::Viewport::GetPos(), GameLib::Viewport::GetRotation(), GameLib::Viewport::GetScale());

		if (GetDir4DirectionSize(pos, Dir4::Down) > WindowSize::HEIGHT / 2.f + PlayerParam::FALL_DEATH_LINE)
			UpFlag(PlayerFlag::DEATH_FLAG);

	}

	void Active::SufferDamage()
	{
		mCollider.SetNameTag("InvinciblePlayer");
		mInvincibleCnt = PlayerParam::INVINCIBLE_TIME;
	}

}