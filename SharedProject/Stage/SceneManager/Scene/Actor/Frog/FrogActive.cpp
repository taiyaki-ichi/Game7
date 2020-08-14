#include"FrogActive.hpp"
#include"FrogParam.hpp"
#include"FrogFlag.hpp"
#include"Stage/Utilty/Geometry.hpp"
#include"Stage/Gravity/Gravity.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/WindowSize.hpp"
#include"Stage/Utilty/IsInScope.hpp"

namespace Stage
{
	namespace FrogState
	{
		Active::Active(GameLib::DrawAnimation* anim,float jumpSpeed)
			:StateBase<>{}
			, mPhysicsModel{}
			, mJumpSpeed{ jumpSpeed }
			, mCnt{ 0 }
			, mStrength{"FrogStrength"}
			, mWeakness{"FrogWeakness"}
			, mAnim{anim}
		{
			mPhysicsModel.mPosition = mAnim->GetPosition();
			mPhysicsModel.mScale = FrogParam::SCALE;

			mStrength.SetWidthAndHeith(FrogParam::WIDTH, FrogParam::HEIGHT* FrogParam::COLLIDER_STRENGTH_RATE);
			mStrength.SetScale(FrogParam::SCALE);
			mStrength.SetColor({ 0,0,255,255 });
			mWeakness.SetWidthAndHeith(FrogParam::WIDTH, FrogParam::HEIGHT* FrogParam::COLLIDER_WEAKNESS_RATE);
			mWeakness.SetScale(FrogParam::SCALE);
			mWeakness.SetColor({ 0,255,0,255 });


			auto weaknessHitGround = [this](const GameLib::Collider& c) {
				auto adjust = GetParallelRectAdjustVec(mWeakness, c);
				auto adjustDir4Vec = GetDir4Vec(adjust);
				if (adjustDir4Vec.mDir4 == Dir4::Up) {
					UpFlag(FrogFlag::ON_GROUND_FLAG);
					if (GetDir4DirectionSize(mPhysicsModel.mVelocity, Dir4::Up) < 0.f)
						mPhysicsModel.mVelocity = GetDirSizeSetVector2(mPhysicsModel.mVelocity, Dir4::Up, 0.f);
				}

				mPhysicsModel.mPosition += adjust;

				AdjustColliders();
				AdjustAnim();

			};

			auto strengthHitGround = [this](const GameLib::Collider& c) {
				auto adjust = GetParallelRectAdjustVec(mStrength, c);
				auto adjustDir4Vec = GetDir4Vec(adjust);
				if (adjustDir4Vec.mDir4 == Dir4::Down)
					mPhysicsModel.mVelocity = GetDirSizeSetVector2(mPhysicsModel.mVelocity, Dir4::Up, 0.f);


				mPhysicsModel.mPosition += adjust;

				AdjustColliders();
				AdjustAnim();
			};

			mWeakness.AddHitFunction("Ground", std::move(weaknessHitGround));
			mStrength.AddHitFunction("Ground", std::move(strengthHitGround));
		}

		
		bool Active::UpdateOrNot()
		{
			auto pos = mPhysicsModel.mPosition;
			return IsInScope(pos, WindowSize::WIDTH + 400.f, WindowSize::WIDTH + 400.f);
		}
		

		StateBase<>* Active::Update()
		{
			UpdatePhysicsModelWithGravity(mPhysicsModel, Gravity::GetVector2(), -1.f, -1.f);

			//std::cout << mPhysicsModel.mVelocity.x << "," << mPhysicsModel.mVelocity.y << "\n";

			if (mCnt == FrogParam::STAY_TIME)
			{
				mPhysicsModel.mVelocity = GetVector2(Dir4::Up, mJumpSpeed);
				mCnt = 0;
			}

			if(CheckFlag(FrogFlag::ON_GROUND_FLAG))
				mCnt++;

			AdjustAnim();
			AdjustColliders();

			DownFlag(FrogFlag::ON_GROUND_FLAG);

			return this;
		}

		void Active::BeginWorking()
		{
			mWeakness.Active();
			mStrength.Active();
		}

		void Active::BeginToRest()
		{
			mWeakness.Pause();
			mStrength.Pause();
		}

		void Active::AdjustAnim()
		{
			mAnim->Set(mPhysicsModel.mPosition, mPhysicsModel.mScale, mPhysicsModel.mRotation);
			if (CheckFlag(FrogFlag::ON_GROUND_FLAG))
				mAnim->SetChannel(0);
			else
				mAnim->SetChannel(1);
		}

		void Active::AdjustColliders()
		{
			using namespace FrogParam;

			mWeakness.SetPosition(mPhysicsModel.mPosition + GetVector2(Dir4::Down, HEIGHT * COLLIDER_WEAKNESS_RATE * SCALE / 2.f));
			mWeakness.SetRotation(mPhysicsModel.mRotation);

			mStrength.SetPosition(mPhysicsModel.mPosition + GetVector2(Dir4::Up, HEIGHT * COLLIDER_STRENGTH_RATE * SCALE / 2.f));
			mStrength.SetRotation(mPhysicsModel.mRotation);
		}
	}
}