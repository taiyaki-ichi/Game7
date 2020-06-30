#include"Toge.hpp"
#include"Game/Stage/UtilityVectorFunction.hpp"

namespace Game::Stage::Toge
{
	Actor::Actor(GameLib::Actor* owner, GameLib::Vector2&& pos, int updateOrder)
		:GameLib::Actor(owner, updateOrder)
		, mAnimation{10}
	{
		mAnimation.AddAnimation({ "../Assets/Enemy/Toge/stay.png" });
		mAnimation.AddAnimation({ "../Assets/Enemy/Toge/fall.png" });

		new Active(this, std::move(pos));
	}

	void Actor::CustomizeUpdate()
	{
		mAnimation.Update();
	}

	void Actor::SetAnimation(const GameLib::Vector2& pos, float scale, float rot, float channel)
	{
		mAnimation.Set(pos, scale, rot);
		if (channel >= 0)
			mAnimation.SetChannel(channel);
	}


	Active::Active(Actor* toge, GameLib::Vector2&& pos)
		:GravityActor{toge}
		, mPhysicsModel{ std::move(pos),GameLib::Vector2{0.f,0.f} ,0.1f,0.f}
		, mCnt{0}
		, mBody{ "EnemyTogeStrength",pos, 550.f,550.f,0.1f,0.f,{0,0,255,255} }
	{
		auto hitGround = [this](const GameLib::Collider& c) {

			auto adjust = GetParallelRectAdjustVec(mBody, c);
			mPhysicsModel.mPosiotion += adjust;

			auto dir4Adjust = GetRoundedDir4Vec(adjust);
			auto velocityDr4 = GetRoundedDir4Vec(mPhysicsModel.mVelocity);
			if (dir4Adjust.mDir4 == Dir4::Up || dir4Adjust.mDir4 == Dir4::Down)
				mPhysicsModel.mVelocity += GetVector2(dir4Adjust.mDir4, velocityDr4.mSize);

			auto toge = static_cast<Toge::Actor*>(this->mOwner);
			toge->SetAnimation(mPhysicsModel.mPosiotion, mPhysicsModel.mScale, mPhysicsModel.mRotation, 0);
			mBody.Set(mPhysicsModel.mPosiotion, 550.f, 550.f, mPhysicsModel.mScale, mPhysicsModel.mRotation);

			if (dir4Adjust.mDir4 == Dir4::Up)
				mPhysicsModel.Friction(0.8f, 0.8f);
		};

		mBody.AddHitFunction("Ground", std::move(hitGround));
	}

	void Active::CustomizeUpdate()
	{
		UpdatePhysicsModel(mPhysicsModel, GetGravityVector2(), 1.f, 20.f, false);
		mPhysicsModel.mScale = 0.15f + 0.05f * std::sin(GameLib::PI * mCnt / 300.f);
		mCnt++;
		
		auto toge = static_cast<Toge::Actor*>(this->mOwner);
		toge->SetAnimation(mPhysicsModel.mPosiotion, mPhysicsModel.mScale, mPhysicsModel.mRotation, 0);
		mBody.Set(mPhysicsModel.mPosiotion, 550.f, 550.f, mPhysicsModel.mScale, mPhysicsModel.mRotation);
	}

}