#include"TripleActive.hpp"
#include"TripleParam.hpp"
#include"Stage/Gravity/Gravity.hpp"
#include"Stage/Utilty/Geometry.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"TripleFlatDeath.hpp"
#include"Stage/Utilty/IsInScope.hpp"
#include"Stage/WindowSize.hpp"
#include"Stage/SceneManager/Scene/Actor/Trampoline/HitTrampoline.hpp"
#include"Stage/SceneManager/Scene/Actor/Trampoline/TrampolineParam.hpp"

namespace Stage
{
	namespace TripleState
	{
		Active::Active(GameLib::DrawAnimation* anim)
			:StateBase{}
			, mBody{""}
			, mWeakness{ "TripleWeakness" }
			, mStrength{ "TripleStrength" }
			, mPhysicsModel{ anim->GetPosition() ,GameLib::Vector2{-2.f,0.f},0.1f,0.f }
			, mDir4{Dir4::Left}
			, mFlatDeathFlag{false}
			, mAnimation{anim}
		{
			using namespace TripleRaram;
			mBody.SetWidthAndHeith(WIDTH, HEIGHT);
			mWeakness.SetWidthAndHeith(WIDTH, HEIGHT* WEAKNESS_RATE);
			mStrength.SetWidthAndHeith(WIDTH, HEIGHT* STRENGTH_RATE);

			mWeakness.SetColor({ 0,255,0,255 });
			mStrength.SetColor({ 0,0,255,255 });

			mBody.SetScale(SCALE);
			mWeakness.SetScale(SCALE);
			mStrength.SetScale(SCALE);

			auto hitGround = [this](const GameLib::Collider& c) {
				auto gravityDir4 = Gravity::GetDir4();
				GameLib::Vector2 adjust;
				if (gravityDir4 == Dir4::Down || gravityDir4 == Dir4::Up)
					adjust = GetParallelRectAdjustVec(mBody, c, Gravity::GetSize(), 0.f);
				else
					adjust = GetParallelRectAdjustVec(mBody, c, 0.f, Gravity::GetSize());

				auto dir4Adjust = GetDir4Vec(adjust);
				auto velocityDr4 = GetDir4Vec(mPhysicsModel.mVelocity);
				if (dir4Adjust.mDir4 == Dir4::Up) {
					mPhysicsModel.mVelocity += GetVector2(Dir4::Up, velocityDr4.mSize);
					adjust += c.GetRerativePos();
				}
				else if (dir4Adjust.mDir4 == Dir4::Right && velocityDr4.mDir4 == Dir4::Left) {
					mPhysicsModel.mVelocity = GetHolizonalFlippedVector2(mPhysicsModel.mVelocity);
					mDir4 = Dir4::Right;
				}
				else if (dir4Adjust.mDir4 == Dir4::Left && velocityDr4.mDir4 == Dir4::Right) {
					mPhysicsModel.mVelocity = GetHolizonalFlippedVector2(mPhysicsModel.mVelocity);
					mDir4 = Dir4::Left;
				}

				mPhysicsModel.mPosition += adjust;

				ReflectAnimation();
				ReflectCollider();
			};

			auto flatDeathFunc = [this](const GameLib::Collider& c) {
				mFlatDeathFlag = true;
			};

			auto hitT = [this, hitGround](Dir4&& dir, const GameLib::Collider& myC,const GameLib::Collider& c)
			{
				auto v = hitTrampoline(mPhysicsModel.mVelocity, myC, std::move(dir), c, TrampolineParam::ENEMY_POWER);
				hitGround(c);
				mPhysicsModel.mVelocity = v;
			};

			auto bodyHitUpT = [this, hitT](const GameLib::Collider& c) {
				hitT(Dir4::Up, mBody, c);
			};
			auto bodyHitDownT = [this, hitT](const GameLib::Collider& c) {
				hitT(Dir4::Down,mBody, c);
			};
			auto bodyHitRightT = [this, hitT](const GameLib::Collider& c) {
				hitT(Dir4::Right,mBody, c);
			};
			auto bodyHitLeftT = [this, hitT](const GameLib::Collider& c) {
				hitT(Dir4::Left,mBody, c);
			};
			
			auto weaknessHitUpT = [this, hitT](const GameLib::Collider& c) {
				hitT(Dir4::Up, mWeakness, c);
			};
			auto weaknessHitDonwT = [this, hitT](const GameLib::Collider& c) {
				hitT(Dir4::Down, mWeakness, c);
			};
			auto weaknessHitRightT = [this, hitT](const GameLib::Collider& c) {
				hitT(Dir4::Right, mWeakness, c);
			};
			auto weaknessHitLeftT = [this, hitT](const GameLib::Collider& c) {
				hitT(Dir4::Left, mWeakness, c);
			};

			auto hitThrough = [this, hitGround](const GameLib::Collider& c) {
				auto ad = GetParallelRectAdjustVec(mBody, c);
				if (GetDir4DirectionSize(ad, Dir4::Up) > 0.f)
					hitGround(c);
			};

			mBody.AddHitFunction("ThroughFloor", std::move(hitThrough));

			mBody.AddHitFunction("TogeBlock", hitGround);

			mBody.AddHitFunction("IceGround", hitGround);

			mBody.AddHitFunction("UpTrampoline", std::move(bodyHitUpT));
			mBody.AddHitFunction("DonwTrampoline", std::move(bodyHitDownT));
			mBody.AddHitFunction("RightTrampoline", std::move(bodyHitRightT));
			mBody.AddHitFunction("LeftTrampoline", std::move(bodyHitLeftT));
			mBody.AddHitFunction("Ground",hitGround);
			mWeakness.AddHitFunction("Ground", hitGround);
			mWeakness.AddHitFunction("Player", flatDeathFunc);
			mWeakness.AddHitFunction("UpTrampoline", std::move(weaknessHitUpT));
			mWeakness.AddHitFunction("DownTrampoline", std::move(weaknessHitDonwT));
			mWeakness.AddHitFunction("RightTrampoline", std::move(weaknessHitRightT));
			mWeakness.AddHitFunction("LeftTrampoline", std::move(weaknessHitLeftT));

			ReflectAnimation();
			ReflectCollider();
		}

		bool Active::UpdateOrNot()
		{
			auto pos = mPhysicsModel.mPosition;
			return IsInScope(pos, WindowSize::WIDTH + 100.f, WindowSize::WIDTH + 100.f);
		}

		StateBase<>* Active::Update()
		{
			using namespace TripleRaram;
			auto vec = GetVector2(mDir4, RUN_POWER);
			//std::cout << vec.x << "," << vec.y << "\n";
			UpdatePhysicsModelWithGravity(mPhysicsModel, GetVector2(mDir4, RUN_POWER) + Gravity::GetVector2(), MAX_SPEED, 20.f, true);
			ReflectCollider();
			ReflectAnimation();

			if (mFlatDeathFlag) {
				return new FlatDeath{ mAnimation };
			}
			return this;
		}


		void Active::ReflectAnimation()
		{
			int channel = (mDir4 == Dir4::Left) ? 0 : 1;
			mAnimation->Set(mPhysicsModel.mPosition, mPhysicsModel.mScale, mPhysicsModel.mRotation);
			mAnimation->SetChannel(channel);
		}


		void Active::ReflectCollider()
		{
			using namespace TripleRaram;

			mBody.SetRotation(mPhysicsModel.mRotation);
			mBody.SetPosition(mPhysicsModel.mPosition + GetVector2(Dir4::Down, COLLIDER_ADJUST_Y));

			mWeakness.SetRotation(mPhysicsModel.mRotation);
			mWeakness.SetPosition(mPhysicsModel.mPosition + GetVector2(Dir4::Up, HEIGHT * WEAKNESS_RATE * SCALE / 2.f + COLLIDER_ADJUST_Y));

			mStrength.SetRotation(mPhysicsModel.mRotation);
			mStrength.SetPosition(mPhysicsModel.mPosition + GetVector2(Dir4::Up, -HEIGHT * STRENGTH_RATE * SCALE / 2.f + COLLIDER_ADJUST_Y));
		}

		void Active::BeginWorking()
		{
			mBody.Active();
			mWeakness.Active();
			mStrength.Active();
		}

		void Active::BeginToRest()
		{
			mBody.Pause();
			mWeakness.Pause();
			mStrength.Pause();
		}


	}
}