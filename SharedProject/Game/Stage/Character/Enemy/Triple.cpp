#include"Triple.hpp"
#include"Game/Stage/UtilityVectorFunction.hpp"

#include"GameLib/include/InputState/InputState.hpp"

namespace Game::Stage::Triple
{
	Actor::Actor(GameLib::Actor* owner,GameLib::Vector2&& pos, int updateOrder)
		:GameLib::Actor(owner,updateOrder)
		, mAnimation{10}
	{
		mAnimation.AddAnimation({ "../Assets/Enemy/Triple/left001.png","../Assets/Enemy/Triple/left002.png" });
		mAnimation.AddAnimation({ "../Assets/Enemy/Triple/right001.png","../Assets/Enemy/Triple/right002.png" });
		mAnimation.AddAnimation({ "../Assets/Enemy/Triple/death-left.png" });
		mAnimation.AddAnimation({ "../Assets/Enemy/Triple/death-right.png" });
		mAnimation.SetScale(0.1f);
		mAnimation.SetDrawOrder(10);
		new Active{ this ,std::move(pos) };
	}

	void Actor::CustomizeUpdate() 
	{
		mAnimation.Update();
	}

	void Actor::ReflectAnimation(const GameLib::Vector2& pos, float scale, float rot,int cannel)
	{
		mAnimation.Set(pos, scale, rot);
		if (cannel >= 0)
			mAnimation.SetChannel(cannel);
	}

	Active::Active(Actor* owner,GameLib::Vector2&& pos)
		:GravityActor{owner}
		, mBody{ "a",pos + GameLib::Vector2{0.f,-2.f}, 350.f,600.f,0.1f,0.f,{0,0,255,255} }
		, mWeakness{"EnemyTripleWeakness",pos + GameLib::Vector2{0.f,14.f}, 350.f,200.f,0.1f,0.f,{255,0,0,255} }
		, mStrength{"EnemyTripleStrength",pos+ GameLib::Vector2{0.f,-16.f}, 350.f,400.f,0.1f,0.f,{0,0,255,255} }
		, mPhysicsModel{ std::move(pos),GameLib::Vector2{-2.f,0.f},0.1f,0.f }
		, mDir4{Dir4::Left}
		, mFlatDeathFlag{false}
	{

		auto hitGround = [this](const GameLib::Collider& c) {
			auto adjust = GetParallelRectAdjustVec(mBody, c);
			mPhysicsModel.mPosiotion += adjust;

			auto dir4Adjust = GetRoundedDir4Vec(adjust);
			auto velocityDr4 = GetRoundedDir4Vec(mPhysicsModel.mVelocity);
			if (dir4Adjust.mDir4 == Dir4::Up || dir4Adjust.mDir4 == Dir4::Down)
				mPhysicsModel.mVelocity += GetVector2(dir4Adjust.mDir4, velocityDr4.mSize);
			else if (dir4Adjust.mDir4 == Dir4::Right && velocityDr4.mDir4 == Dir4::Left) {
				mPhysicsModel.mVelocity = GetHolizonalFlippedVector2(mPhysicsModel.mVelocity);
				mDir4 = Dir4::Right;
			}
			else if (dir4Adjust.mDir4 == Dir4::Left && velocityDr4.mDir4 == Dir4::Right) {
				mPhysicsModel.mVelocity = GetHolizonalFlippedVector2(mPhysicsModel.mVelocity);
				mDir4 = Dir4::Left;
			}

			ReflectAnimation();

			ReflectCollider();
		};

		auto hitPlayer = [this](const GameLib::Collider& c) {
			mFlatDeathFlag = true;
		};

		mBody.AddHitFunction("Ground", hitGround);
		mWeakness.AddHitFunction("Player", hitPlayer);
		
		ReflectCollider();
	}

	void Active::CustomizeUpdate()
	{

		UpdatePhysicsModel(mPhysicsModel, GetPowerPerFrame(), MAX_SPEED, 20.f);
		ReflectCollider();
		ReflectAnimation();

		if (mFlatDeathFlag) {
			SetState(Actor::State::Dead);
			new FlatDead(mOwner, mPhysicsModel, mDir4);
		}
	}

	void Active::ReflectCollider()
	{
		mBody.SetRotation(mPhysicsModel.mRotation);
		mBody.SetPosition(mPhysicsModel.mPosiotion + GetVector2(Dir4::Down, 6));

		mWeakness.SetRotation(mPhysicsModel.mRotation);
		mWeakness.SetPosition(mPhysicsModel.mPosiotion + GetVector2(Dir4::Up, 14));

		mStrength.SetRotation(mPhysicsModel.mRotation);
		mStrength.SetPosition(mPhysicsModel.mPosiotion + GetVector2(Dir4::Down, 16));
	}

	void Active::ReflectAnimation()
	{
		int channel = (mDir4 == Dir4::Left) ? 0 : 1;
		auto owenr = static_cast<Triple::Actor*>(mOwner);
		owenr->ReflectAnimation(mPhysicsModel.mPosiotion, mPhysicsModel.mScale, mPhysicsModel.mRotation, channel);
	}

	GameLib::Vector2 Active::GetPowerPerFrame()
	{
		return GetGravityVector2() + GetVector2(mDir4, RUN_POWER);
	}

	FlatDead::FlatDead(Actor* owner, PhysicsModel& model, Dir4& dir)
		:GravityActor{owner}
		, mCnt{0}
	{
		int channel = (dir == Dir4::Left) ? 2 : 3;
		auto actor = static_cast<Triple::Actor*>(mOwner);
		actor->ReflectAnimation(model.mPosiotion + GetVector2(Dir4::Down, 20.f), model.mScale, model.mRotation, channel);
	}

	void FlatDead::CustomizeUpdate()
	{
		if (mCnt > DEATH_CNT) {
			mOwner->SetState(Actor::State::Dead);
		}
		mCnt++;
	}

}