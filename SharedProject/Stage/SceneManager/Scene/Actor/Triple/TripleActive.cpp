#include"TripleActive.hpp"
#include"TripleParam.hpp"
#include"Stage/Gravity/Gravity.hpp"
#include"Stage/Utilty/Geometry.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"TripleFlatDeath.hpp"
#include"Stage/Utilty/IsInScope.hpp"
#include"Stage/WindowSize.hpp"

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

			mBody.AddHitFunction("Ground", [this](const GameLib::Collider& c) {
				auto gravityDir4 = Gravity::GetDir4();
				GameLib::Vector2 adjust;
				if (gravityDir4 == Dir4::Down || gravityDir4 == Dir4::Up)
					adjust = GetParallelRectAdjustVec(mBody, c, Gravity::GetSize() ,0.f);
				else
					adjust = GetParallelRectAdjustVec(mBody, c, 0.f,Gravity::GetSize() );

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
			});

			auto flatDeathFunc = [this](const GameLib::Collider& c) {
				mFlatDeathFlag = true;
			};

			mWeakness.AddHitFunction("Player", flatDeathFunc);

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