#include"Player.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"Game/Stage/UtilityVectorFunction.hpp"
#include"GameLib/include/Math/Numbers.hpp"


namespace Game::Stage
{
	/*
	Player::Player(Actor* owner, int updateOrder) 
		:GravityActor(owner, updateOrder)
		, mAnimation(10)
		, mCollider("Player", { 0.f,-12.f }, 250.f, 500.f, 0.1f, 0.f, { 255,0,0,255 })
		, mPhysicsModel({ 0.f,200.f }, { 0.f,0.f })
		, mFlags(0)
		, mJumpFlag{0}
	{
		using namespace GameLib;

		mAnimation.AddAnimation({ "../Assets/Player/stay001.png" });
		mAnimation.AddAnimation({ "../Assets/Player/run001.png","../Assets/Player/run002.png" ,"../Assets/Player/run003.png" });
		mAnimation.AddAnimation({ "../Assets/Player/up.png" });
		mAnimation.AddAnimation({ "../Assets/Player/down.png" });
		mAnimation.SetScale(0.1f);
		mAnimation.SetDrawOrder(50);

		auto hitGround = [this](const GameLib::Collider& c) {
			auto adjust = GetParallelRectAdjustVec(mCollider, c);
			auto dir4Vec = GetRoundedDir4Vec(adjust);

			mPhysicsModel.mPosiotion += adjust;

			if (adjust.x * mPhysicsModel.mVelocity.x < 0.f)
				mPhysicsModel.mVelocity.x = 0.f;
			else if (adjust.y * mPhysicsModel.mVelocity.y < 0.f)
				mPhysicsModel.mVelocity.y = 0.f;

			if (dir4Vec.mDir4 == Dir4::Up) {
				mFlags |= ON_GROUND_FLAG;
				mJumpFlag = 1;
			}

			if ((InputState::GetState(Key::A) == ButtonState::None &&
				InputState::GetState(Key::D) == ButtonState::None) ||
				(InputState::GetState(Key::A) == ButtonState::Held &&
					InputState::GetState(Key::D) == ButtonState::Held) ||
				(InputState::GetState(Key::A) == ButtonState::Held &&
					GetDir4Size(mPhysicsModel.mVelocity, Dir4::Right) > 0.f) ||
				(InputState::GetState(Key::D) == ButtonState::Held &&
					GetDir4Size(mPhysicsModel.mVelocity, Dir4::Left) > 0.f
					))

			{
				if (dir4Vec.mDir4 == Dir4::Up) {
					if (GetGravityDir4() == Dir4::Up || GetGravityDir4() == Dir4::Down)
						mPhysicsModel.Friction(0.8f, 1.f);
					else
						mPhysicsModel.Friction(1.f, 0.8f);
				}
			}

			UpdateCollider();
			mAnimation.SetPosition(mPhysicsModel.mPosiotion);
		};

		auto hitEnemyWeakness = [this](const GameLib::Collider& c) {
			float upSize = GetDir4Size(mPhysicsModel.mVelocity, Dir4::Up);
			mPhysicsModel.mVelocity += GetVector2(Dir4::Up, -upSize + 3.f);

			//4フレームの間はジャンプできる
			mJumpFlag = 4;
		};

		mCollider.AddHitFunction("Ground", std::move(hitGround));
		mCollider.AddHitFunction("EnemyTripleWeakness", std::move(hitEnemyWeakness));
	}

	void Player::CustomizeUpdate() 
	{
		auto power = GetPowerPerFrame();
		UpdatePhysicsModel(mPhysicsModel, power, MAX_HORIZON_SPEED, MAX_VERTICAL_SPEED);
		UpdateCollider();
		UpdateAnimation(power);

		mFlags &= ~ON_GROUND_FLAG;
		
		if (mJumpFlag > 0)
			mJumpFlag--;
	}


	GameLib::Vector2 Player::GetPowerPerFrame()
	{
		using namespace GameLib;
		Vector2 power{ 0.f,0.f };

		//重力
		if (~(mFlags & ON_GROUND_FLAG) &&
			GetDir4Size(mPhysicsModel.mVelocity, Dir4::Up) > 0.f &&
			InputState::GetState(Key::Space) == ButtonState::Held)
			power += GetGravityVector2() * JUMPING_GRAVITY_RATE;
		else
			power += GetGravityVector2();

		//ヨコの力
		if (InputState::GetState(Key::A) == ButtonState::Pressed ||
			InputState::GetState(Key::A) == ButtonState::Held) {
			power += GetVector2(Dir4::Left, RUN_POWER);
		}
		if (InputState::GetState(Key::D) == ButtonState::Pressed ||
			InputState::GetState(Key::D) == ButtonState::Held)
			power += GetVector2(Dir4::Right, RUN_POWER);

		//ジャンプ
		if (InputState::GetState(Key::Space) == ButtonState::Pressed &&
			(mJumpFlag>0)) {

			auto v = GetRoundedDir4Vec(mPhysicsModel.mVelocity);
			float rate = std::abs(v.mSize) / MAX_HORIZON_SPEED;
			power += GetVector2(Dir4::Up, (JUMP_POWER_MAX - JUMP_POWER_MIN) * rate + JUMP_POWER_MIN);

			power += GetVector2(Dir4::Up, JUMP_POWER_MAX);

			mJumpFlag = 0;
		}

		return power;
	}

	//毎フレーム呼ぶ
	void Player::UpdateAnimation(const GameLib::Vector2& power) {
		mAnimation.Update();

		mAnimation.SetPosition(mPhysicsModel.mPosiotion);
		mAnimation.SetRotation(mPhysicsModel.mRotation);
		
		float horizonPowerDir = GetDir4Size(power, Dir4::Right);
		float verticalDir = GetDir4Size(mPhysicsModel.mVelocity, Dir4::Up);
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
		mCollider.SetRotation(mPhysicsModel.mRotation);
		mCollider.SetPosition(mPhysicsModel.mPosiotion + GetVector2(Dir4::Down, 12.f));
	}


	*/


}


namespace Game::Stage::Player
{
	Actor::Actor(GameLib::Actor* owner, GameLib::Vector2&& pos, int updateOrder)
		:GameLib::Actor(owner)
		, mAnimation{10}
	{
		using namespace GameLib;

		mAnimation.AddAnimation({ "../Assets/Player/stay001.png" });
		mAnimation.AddAnimation({ "../Assets/Player/run001.png","../Assets/Player/run002.png" ,"../Assets/Player/run003.png" });
		mAnimation.AddAnimation({ "../Assets/Player/up.png" });
		mAnimation.AddAnimation({ "../Assets/Player/down.png" });
		mAnimation.AddAnimation({ "../Assets/Player/death.png" });
		mAnimation.SetScale(0.1f);
		mAnimation.SetDrawOrder(50);
		mAnimation.SetPosition(pos);
		
		new Active(this, std::move(pos), &mAnimation);
	}

	void Actor::CustomizeUpdate()
	{

	}

	void Actor::SetAnamtion(const GameLib::Vector2& pos,float scale,float rot,int chanel)
	{
		mAnimation.Set(pos, scale, rot);
		if (chanel >= 0)
			mAnimation.SetChannel(chanel);
	}


	Active::Active(Actor* player,GameLib::Vector2&& pos,GameLib::DrawAnimation* anim)
		:GravityActor(player)
		, mCollider{"Player"}
		, mPhysicsModel{ std::move(pos),GameLib::Vector2{0.f,0.f},0.1f,0.f }
		, mFlags{0}
		, mJumpFlag{ 0 }
		, mAnimation{ anim }
	{
		using namespace GameLib;

		mCollider.Set(mPhysicsModel.mPosiotion, 250.f, 500.f, 0.1f, 0.f);
		mCollider.SetColor({ 255,0,0,255 });
		UpdateCollider();

		auto hitGround = [this](const GameLib::Collider& c) {
			auto adjust = GetParallelRectAdjustVec(mCollider, c);
			auto dir4Vec = GetRoundedDir4Vec(adjust);

			mPhysicsModel.mPosiotion += adjust;

			if (adjust.x * mPhysicsModel.mVelocity.x < 0.f)
				mPhysicsModel.mVelocity.x = 0.f;
			else if (adjust.y * mPhysicsModel.mVelocity.y < 0.f)
				mPhysicsModel.mVelocity.y = 0.f;

			if (dir4Vec.mDir4 == Dir4::Up) {
				mFlags |= ON_GROUND_FLAG;
				mJumpFlag = 1;
			}

			if ((InputState::GetState(Key::A) == ButtonState::None &&
				InputState::GetState(Key::D) == ButtonState::None) ||
				(InputState::GetState(Key::A) == ButtonState::Held &&
					InputState::GetState(Key::D) == ButtonState::Held) ||
				(InputState::GetState(Key::A) == ButtonState::Held &&
					GetDir4Size(mPhysicsModel.mVelocity, Dir4::Right) > 0.f) ||
				(InputState::GetState(Key::D) == ButtonState::Held &&
					GetDir4Size(mPhysicsModel.mVelocity, Dir4::Left) > 0.f
					))

			{
				if (dir4Vec.mDir4 == Dir4::Up) {
					if (GetGravityDir4() == Dir4::Up || GetGravityDir4() == Dir4::Down)
						mPhysicsModel.Friction(0.8f, 1.f);
					else
						mPhysicsModel.Friction(1.f, 0.8f);
				}
			}

			UpdateCollider();
			mAnimation->SetPosition(mPhysicsModel.mPosiotion);
		};

		auto hitEnemyWeakness = [this](const GameLib::Collider& c) {
			float upSize = GetDir4Size(mPhysicsModel.mVelocity, Dir4::Up);
			mPhysicsModel.mVelocity += GetVector2(Dir4::Up, -upSize + 3.f);

			//4フレームの間はジャンプできる
			mJumpFlag = 4;
		};

		auto hitEnemyStrength = [this](const GameLib::Collider& c) {
			SetState(Actor::State::Dead);
			new Death(mOwner, mPhysicsModel, mAnimation);
		};

		mCollider.AddHitFunction("Ground", std::move(hitGround));
		mCollider.AddHitFunction("EnemyTripleWeakness", hitEnemyWeakness);
		mCollider.AddHitFunction("EnemyTripleStrength", hitEnemyStrength);
		mCollider.AddHitFunction("EnemyTogeStrength", hitEnemyStrength);
		
	}

	void Active::CustomizeUpdate()
	{
		auto power = GetPowerPerFrame();
		UpdatePhysicsModel(mPhysicsModel, power, MAX_HORIZON_SPEED, MAX_VERTICAL_SPEED);
		UpdateCollider();
		UpdateAnimation(std::move(power));

		mFlags &= ~ON_GROUND_FLAG;

		if (mJumpFlag > 0)
			mJumpFlag--;

	}


	GameLib::Vector2 Active::GetPowerPerFrame()
	{
		using namespace GameLib;
		Vector2 power{ 0.f,0.f };

		//重力
		if (~(mFlags & ON_GROUND_FLAG) &&
			GetDir4Size(mPhysicsModel.mVelocity, Dir4::Up) > 0.f &&
			InputState::GetState(Key::Space) == ButtonState::Held)
			power += GetGravityVector2() * JUMPING_GRAVITY_RATE;
		else
			power += GetGravityVector2();

		//ヨコの力
		if (InputState::GetState(Key::A) == ButtonState::Pressed ||
			InputState::GetState(Key::A) == ButtonState::Held) {
			power += GetVector2(Dir4::Left, RUN_POWER);
		}
		if (InputState::GetState(Key::D) == ButtonState::Pressed ||
			InputState::GetState(Key::D) == ButtonState::Held)
			power += GetVector2(Dir4::Right, RUN_POWER);

		//ジャンプ
		if (InputState::GetState(Key::Space) == ButtonState::Pressed &&
			(mJumpFlag > 0)) {

			auto v = GetRoundedDir4Vec(mPhysicsModel.mVelocity);
			float rate = std::abs(v.mSize) / MAX_HORIZON_SPEED;
			power += GetVector2(Dir4::Up, (JUMP_POWER_MAX - JUMP_POWER_MIN) * rate + JUMP_POWER_MIN);

			power += GetVector2(Dir4::Up, JUMP_POWER_MAX);

			mJumpFlag = 0;
		}

		return power;
	}
	void Active::UpdateAnimation(const GameLib::Vector2& power)
	{

		mAnimation->Update();

		mAnimation->SetPosition(mPhysicsModel.mPosiotion);
		mAnimation->SetRotation(mPhysicsModel.mRotation);

		float horizonPowerDir = GetDir4Size(power, Dir4::Right);
		float verticalDir = GetDir4Size(mPhysicsModel.mVelocity, Dir4::Up);
		if (!(mFlags & ON_GROUND_FLAG) && verticalDir < 0.f)
			mAnimation->SetChannel(3);
		else if (!(mFlags & ON_GROUND_FLAG) && verticalDir > 0.f)
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

	void Active::UpdateCollider()
	{
		mCollider.SetRotation(mPhysicsModel.mRotation);
		mCollider.SetPosition(mPhysicsModel.mPosiotion + GetVector2(Dir4::Down, 12.f));
	}

	Death::Death(Actor* player,const PhysicsModel& model, GameLib::DrawAnimation* anim)
		:GravityActor{player}
		, mCnt{0}
		, mPosition{model.mPosiotion}
		, mScale{ model.mScale }
		, mRotation{model.mRotation}
		, mAnimation{anim}
	{
		mAnimation->SetChannel(4);
	}

	void Death::CustomizeUpdate()
	{
		mCnt++;
		if (mCnt > DEATH_CNT)
			mOwner->SetState(Actor::State::Dead);

		mPosition += GetVector2(Dir4::Up, 4.f);
		mScale *= 0.99f;
		mRotation += 0.3f;

		mAnimation->Set(mPosition, mScale, mRotation);

	}
}