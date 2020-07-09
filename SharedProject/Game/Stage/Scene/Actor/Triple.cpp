#include"Triple.hpp"
#include"Game/Stage/UtilityVectorFunction.hpp"
#include"Game/Stage/Gravity.hpp"
#include"Game/Stage/PhysicsModel.hpp"

namespace Game::Stage::Triple
{
	Actor::Actor(Scene* scene, std::vector<float>&& data)
		:ActorBase{scene}
		, mAnimation{}
		, mStateManager{}
	{
		mAnimation.AddAnimation({ "../Assets/Enemy/Triple/left001.png","../Assets/Enemy/Triple/left002.png" });
		mAnimation.AddAnimation({ "../Assets/Enemy/Triple/right001.png","../Assets/Enemy/Triple/right002.png" });
		mAnimation.AddAnimation({ "../Assets/Enemy/Triple/death-left.png" });
		mAnimation.AddAnimation({ "../Assets/Enemy/Triple/death-right.png" });
		mAnimation.SetScale(0.1f);
		mAnimation.SetDrawOrder(10);
		mAnimation.SetAnimationFPS(10);

		GameLib::Vector2 pos{ data[0],data[1] };
		mStateManager.SetState(new TripleActive{ std::move(pos),&mAnimation });
		
	}
	bool Actor::UpdateOrNot()
	{
		return true;
	}
	void Actor::UpdateActor()
	{
		mAnimation.Update();
		mStateManager.Update();
		if (mStateManager.GetFlag() == 4)
			SetState(GameLib::Actor::State::Dead);
	}

	void Actor::Active()
	{
		mAnimation.SetIsAutoDrawing(true);
		mStateManager.Active();
	}

	void Actor::Pause()
	{
		mAnimation.SetIsAutoDrawing(false);
		mStateManager.Pause();
	}

	TripleActive::TripleActive(GameLib::Vector2&& pos,GameLib::DrawAnimation* anim)
		:StateBase{}
		, mAnimation{anim}
		, mBody{ "",pos + GameLib::Vector2{0.f,-6.f}, 350.f,600.f,0.1f,0.f,{0,0,0,0} }
		, mWeakness{ "TripleWeakness",pos + GameLib::Vector2{0.f,14.f}, 350.f,200.f,0.1f,0.f,{255,0,0,255} }
		, mStrength{ "TripleStrength",pos + GameLib::Vector2{0.f,-16.f}, 350.f,400.f,0.1f,0.f,{0,0,255,255} }
		, mPhysicsModel{ std::move(pos),GameLib::Vector2{-2.f,0.f},0.1f,0.f }
		, mDir4{ Dir4::Left }
		, mFlatDeathFlag{false}
	{

		mBody.AddHitFunction("Ground", [this](const GameLib::Collider& c) {
			auto adjust = GetParallelRectAdjustVec(mBody, c);
			mPhysicsModel.mPosition += adjust;

			auto dir4Adjust = Gravity::GetDir4Vec(adjust);
			auto velocityDr4 = Gravity::GetDir4Vec(mPhysicsModel.mVelocity);
			if (dir4Adjust.mDir4 == Dir4::Up)
				mPhysicsModel.mVelocity += Gravity::GetVector2(Dir4::Up, velocityDr4.mSize);
			else if (dir4Adjust.mDir4 == Dir4::Right && velocityDr4.mDir4 == Dir4::Left) {
				mPhysicsModel.mVelocity = Gravity::GetHolizonalFlippedVector2(mPhysicsModel.mVelocity);
				mDir4 = Dir4::Right;
			}
			else if (dir4Adjust.mDir4 == Dir4::Left && velocityDr4.mDir4 == Dir4::Right) {
				mPhysicsModel.mVelocity = Gravity::GetHolizonalFlippedVector2(mPhysicsModel.mVelocity);
				mDir4 = Dir4::Left;
			}

			ReflectAnimation();

			ReflectCollider();
		});

		auto flatDeathFunc = [this](const GameLib::Collider& c) {
			mFlatDeathFlag = true;
		};

		mWeakness.AddHitFunction("Player", flatDeathFunc);

	}

	StateBase* TripleActive::Update()
	{
		Gravity::UpdatePhysicsModel(mPhysicsModel, Gravity::GetVector2(mDir4, RUN_POWER) + Gravity::GetGravityVector2(), MAX_SPEED, 20.f, true);
		ReflectCollider();
		ReflectAnimation();

		if (mFlatDeathFlag) {
			return new FlatDeath{ mAnimation };
		}
		return this;
	}

	void TripleActive::ReflectAnimation()
	{
		int channel = (mDir4 == Dir4::Left) ? 0 : 1;
		mAnimation->Set(mPhysicsModel.mPosition, mPhysicsModel.mScale, mPhysicsModel.mRotation);
		mAnimation->SetChannel(channel);
	}

	void TripleActive::ReflectCollider()
	{
		mBody.SetRotation(mPhysicsModel.mRotation);
		mBody.SetPosition(mPhysicsModel.mPosition + Gravity::GetVector2(Dir4::Down, 6));

		mWeakness.SetRotation(mPhysicsModel.mRotation);
		mWeakness.SetPosition(mPhysicsModel.mPosition + Gravity::GetVector2(Dir4::Up, 14));

		mStrength.SetRotation(mPhysicsModel.mRotation);
		mStrength.SetPosition(mPhysicsModel.mPosition + Gravity::GetVector2(Dir4::Down, 16));
	}

	void TripleActive::Active()
	{
		mBody.Active();
		mWeakness.Active();
		mStrength.Active();
	}

	void TripleActive::Pause()
	{
		mBody.Pause();
		mWeakness.Pause();
		mStrength.Pause();
	}
	

	FlatDeath::FlatDeath(GameLib::DrawAnimation* anim)
		:StateBase{}
		, mCnt{0}
	{
		int c = anim->GetChannel();
		anim->SetChannel(c + 2);
		auto aniPos = anim->GetPosition();
		anim->SetPosition(aniPos + Gravity::GetVector2(Dir4::Down, 10.f));
	}

	StateBase* FlatDeath::Update()
	{
		mCnt++;
		return this;
	}

	int FlatDeath::GetFlag()
	{
		if (mCnt > DEATH_TIME)
			return 4;
		return 0;
	}

}