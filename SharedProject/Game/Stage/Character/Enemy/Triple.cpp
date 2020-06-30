#include"Triple.hpp"
#include"Game/Stage/UtilityVectorFunction.hpp"

namespace Game::Stage::Triple
{
	Actor::Actor(GameLib::Actor* owner,GameLib::Vector2&& pos, int updateOrder)
		:GameLib::Actor(owner,updateOrder)
		, mAnimation{10}
		, mState{nullptr}
	{
		mAnimation.AddAnimation({ "../Assets/Enemy/Triple/left001.png","../Assets/Enemy/Triple/left002.png" });
		mAnimation.AddAnimation({ "../Assets/Enemy/Triple/right001.png","../Assets/Enemy/Triple/right002.png" });
		mAnimation.AddAnimation({ "../Assets/Enemy/Triple/death-left.png" });
		mAnimation.AddAnimation({ "../Assets/Enemy/Triple/death-right.png" });
		mAnimation.SetScale(0.1f);
		mAnimation.SetDrawOrder(10);
		mState = new Active{ this ,std::move(pos) };
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
		, mBody{ "",pos + GameLib::Vector2{0.f,-16.f}, 350.f,400.f,0.1f,0.f,{0,0,255,255} }
		, mWeakness{"",pos + GameLib::Vector2{0.f,14.f}, 350.f,200.f,0.1f,0.f,{255,0,0,255} }
		, mPhysicsModel{ std::move(pos),GameLib::Vector2{-2.f,0.f},0.1f,0.f }
		, mDir4{Dir4::Left}
	{

		mBody.AddHitFunction("Ground", [this](const GameLib::Collider& c) {
			auto adjust = GetParallelRectAdjustVec(mBody, c);
			mPhysicsModel.mPosiotion += adjust;

			auto dir4Adjust = GetRoundedDir4Vec(adjust);
			auto velocityDr4 = GetRoundedDir4Vec(mPhysicsModel.mVelocity);
			if (dir4Adjust.mDir4 == Dir4::Up)
				mPhysicsModel.mVelocity += GetDir4Vec(Dir4::Up, velocityDr4.mSize);
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
		});

		ReflectCollider();
	}

	void Active::CustomizeUpdate()
	{

		//TODO
		if (mGravityDir4 == Dir4::Down || mGravityDir4 == Dir4::Up)
			mPhysicsModel.Update(GetPowerPerFrame(), MAX_SPEED, 20.f);
		else
			mPhysicsModel.Update(GetPowerPerFrame(), 20.f, MAX_SPEED);
		mPhysicsModel.mRotation = GetGravityRotation();

		ReflectCollider();

		ReflectAnimation();
	}

	void Active::ReflectCollider()
	{
		mBody.SetRotation(mPhysicsModel.mRotation);
		mBody.SetPosition(mPhysicsModel.mPosiotion + GetDir4Vec(Dir4::Down, 16));

		mWeakness.SetRotation(mPhysicsModel.mRotation);
		mWeakness.SetPosition(mPhysicsModel.mPosiotion + GetDir4Vec(Dir4::Up, 14));
	}

	void Active::ReflectAnimation()
	{
		int channel = (mDir4 == Dir4::Left) ? 0 : 1;
		auto owenr = static_cast<Triple::Actor*>(mOwner);
		owenr->ReflectAnimation(mPhysicsModel.mPosiotion, mPhysicsModel.mScale, mPhysicsModel.mRotation, channel);
	}

	GameLib::Vector2 Active::GetPowerPerFrame()
	{
		return GetGravityVector2() + GetDir4Vec(mDir4, RUN_POWER);
	}

	FlatDead::FlatDead(Actor* owner, PhysicsModel&& model)
		:GravityActor{owner}
		, mPhysicsModel{ GameLib::Vector2{0.f,0.f} }
	{
	}

	void FlatDead::CustomizeUpdate()
	{
	}

}