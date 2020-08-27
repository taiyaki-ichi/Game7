#include"FrogActive.hpp"
#include"FrogParam.hpp"
#include"FrogFlag.hpp"
#include"Stage/Utilty/Geometry.hpp"
#include"Stage/Gravity/Gravity.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/WindowSize.hpp"
#include"Stage/Utilty/IsInScope.hpp"
#include"Stage/Utilty/State/DeathTimerState.hpp"
#include"Stage/SceneManager/Scene/Actor/Trampoline/HitTrampoline.hpp"
#include"Stage/SceneManager/Scene/Actor/Trampoline/TrampolineParam.hpp"

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


			auto sHitGround = [this](const GameLib::Collider& c) {
				auto adjust = GetParallelRectAdjustVec(mStrength, c);
				auto adjustDir4Vec = GetDir4Vec(adjust);
				if (adjustDir4Vec.mDir4 == Dir4::Up) {
					UpFlag(FrogFlag::ON_GROUND_FLAG);
					if (GetDir4DirectionSize(mPhysicsModel.mVelocity, Dir4::Up) < 0.f)
						mPhysicsModel.mVelocity = GetDirSizeSetVector2(mPhysicsModel.mVelocity, Dir4::Up, 0.f);

					adjust += c.GetRerativePos();
				}

				mPhysicsModel.mPosition += adjust;

				AdjustColliders();
				AdjustAnim();

			};

			auto wHitGround = [this](const GameLib::Collider& c) {
				auto adjust = GetParallelRectAdjustVec(mWeakness, c);
				auto adjustDir4Vec = GetDir4Vec(adjust);
				if (adjustDir4Vec.mDir4 == Dir4::Down)
					mPhysicsModel.mVelocity = GetDirSizeSetVector2(mPhysicsModel.mVelocity, Dir4::Up, 0.f);

				mPhysicsModel.mPosition += adjust;

				AdjustColliders();
				AdjustAnim();
			};

			auto hitPlayer = [this](const GameLib::Collider& c)
			{
				UpFlag(FrogFlag::FLAD_DEATH_FLAG);
			};

			auto weaknessHitT = [this, wHitGround](Dir4&& dir, const GameLib::Collider& c) {
				auto v = hitTrampoline(mPhysicsModel.mVelocity, mWeakness, std::move(dir), c, TrampolineParam::ENEMY_POWER);
				wHitGround(c);
				mPhysicsModel.mVelocity = v;
			};
			auto wHitUpT = [this, weaknessHitT](const GameLib::Collider& c) {
				weaknessHitT(Dir4::Up, c);
			};
			auto wHitDownT = [this, weaknessHitT](const GameLib::Collider& c) {
				weaknessHitT(Dir4::Down, c);
			};
			auto wHitRightT = [this, weaknessHitT](const GameLib::Collider& c) {
				weaknessHitT(Dir4::Right, c);
			};
			auto wHitLeftT = [this, weaknessHitT](const GameLib::Collider& c) {
				weaknessHitT(Dir4::Left, c);
			};

			auto sHitT = [this, sHitGround](Dir4&& dir, const GameLib::Collider& c) {
				auto v = hitTrampoline(mPhysicsModel.mVelocity, mStrength, std::move(dir), c, TrampolineParam::ENEMY_POWER);
				sHitGround(c);
				mPhysicsModel.mVelocity = v;
			};
			auto sHitUpT = [this, sHitT](const GameLib::Collider& c) {
				sHitT(Dir4::Up, c);
			};
			auto sHitDownT = [this, sHitT](const GameLib::Collider& c) {
				sHitT(Dir4::Down, c);
			};
			auto sHitRightT = [this, sHitT](const GameLib::Collider& c) {
				sHitT(Dir4::Right, c);
			};
			auto sHitLeftT = [this, sHitT](const GameLib::Collider& c) {
				sHitT(Dir4::Left, c);
			};

			mWeakness.AddHitFunction("TogeBlock", wHitGround);
			mWeakness.AddHitFunction("Ground", std::move(wHitGround));
			mStrength.AddHitFunction("TogeBlock", sHitGround);
			mStrength.AddHitFunction("Ground", std::move(sHitGround));
			mWeakness.AddHitFunction("Player", std::move(hitPlayer));

			mWeakness.AddHitFunction("UpTrampoline", std::move(wHitUpT));
			mWeakness.AddHitFunction("DownTrampoline", std::move(wHitDownT));
			mWeakness.AddHitFunction("RightTrampoline", std::move(wHitRightT));
			mWeakness.AddHitFunction("LeftTrampoline", std::move(wHitLeftT));

			mStrength.AddHitFunction("UpTrampoline", std::move(sHitUpT));
			mStrength.AddHitFunction("DownTrampoline", std::move(sHitDownT));
			mStrength.AddHitFunction("RightTrampoline", std::move(sHitRightT));
			mStrength.AddHitFunction("LeftTrampoline", std::move(sHitLeftT));

			AdjustColliders();
		}

		
		bool Active::UpdateOrNot()
		{
			auto pos = mPhysicsModel.mPosition;
			return IsInScope(pos, WindowSize::WIDTH + 100.f, WindowSize::WIDTH + 100.f);
		}
		
		

		StateBase<>* Active::Update()
		{
			if (CheckFlag(FrogFlag::FLAD_DEATH_FLAG)) {
				auto pos = mPhysicsModel.mPosition + GameLib::Vector2{ 0.f,FrogParam::FLATDEATH_ADJUST_Y };
				return new DeathTimerState<>{ mAnim,3, std::move(pos),FrogParam::FLAT_MOTION_TIME,FrogFlag::DEATH_MOTION_END_FLAD };
			}

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

			mWeakness.SetPosition(mPhysicsModel.mPosition + GetVector2(Dir4::Up, HEIGHT * COLLIDER_WEAKNESS_RATE * SCALE / 2.f));
			mWeakness.SetRotation(mPhysicsModel.mRotation);

			mStrength.SetPosition(mPhysicsModel.mPosition + GetVector2(Dir4::Down, HEIGHT * COLLIDER_STRENGTH_RATE * SCALE / 2.f));
			mStrength.SetRotation(mPhysicsModel.mRotation);
		}
	}
}