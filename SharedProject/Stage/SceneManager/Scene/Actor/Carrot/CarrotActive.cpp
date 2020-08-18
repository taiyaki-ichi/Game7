#include"CarrotActive.hpp"
#include"CarrotParam.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/Gravity/Gravity.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"Stage/SceneManager/Scene/Actor/Player.hpp"
#include"CarrotStay.hpp"
#include"Stage/Utilty/Geometry.hpp"
#include"CarrotFlag.hpp"
#include"Stage/Utilty/State/DeathTimerState.hpp"

namespace Stage
{
	namespace CarrotState
	{
		Active::Active(GameLib::DrawAnimation* anim)
			:StateBase<>{}
			, mAnim{ anim }
			, mWeakness{"CarrotWeakness"}
			, mStrength{"CarrotStrength"}
			, mPhysicsModel{}
		{

			mWeakness.SetWidthAndHeith(CarrotParam::WIDTH, CarrotParam::HEIGHT* CarrotParam::WEAKNESS_RATE);
			mWeakness.SetScale(CarrotParam::SCALE);
			mWeakness.SetColor({ 0,255,0,255 });

			mStrength.SetWidthAndHeith(CarrotParam::WIDTH, CarrotParam::HEIGHT* CarrotParam::STREANGTH_RATE);
			mStrength.SetScale(CarrotParam::SCALE);
			mStrength.SetColor({ 0,0,255,255 });

			mAnim->SetChannel(1);

			mPhysicsModel.mPosition = mAnim->GetPosition();
			mPhysicsModel.mScale = CarrotParam::SCALE;

			auto hitGround = [this](const GameLib::Collider& c)
			{
				auto adjustVec = GetParallelRectAdjustVec(mStrength, c);
				if (GetDir4DirectionSize(adjustVec, Dir4::Up) > 0.f) 
					mPhysicsModel.mVelocity = GetDirSizeSetVector2(mPhysicsModel.mVelocity, Dir4::Up, 0.f);

				mPhysicsModel.mPosition += adjustVec;

				AdjustAnim();
				AdjustColliders();
			};

			auto hitPlayer = [this](const GameLib::Collider& c)
			{
				UpFlag(CarrotFlag::FLATDETH_FLAG);
			};

			mStrength.AddHitFunction("Ground",std::move(hitGround));

			mWeakness.AddHitFunction("Player", std::move(hitPlayer));

			AdjustAnim();
			AdjustColliders();

			//std::cout << "a";
		}

		StateBase<>* Active::Update()
		{
			//std::cout << mPhysicsModel.mVelocity.x << "," << mPhysicsModel.mVelocity.y << "\n";
			
			auto power = GetPowerPerFrame();
			UpdatePhysicsModelWithGravity(mPhysicsModel, power, CarrotParam::MAX_SPEED, -1);

			if (GetDir4DirectionSize(power, Dir4::Right) > 0.f)
				mAnim->SetHorizontalFlip(true);
			if (GetDir4DirectionSize(power, Dir4::Left) > 0.f)
				mAnim->SetHorizontalFlip(false);
			
			AdjustAnim();
			AdjustColliders();

			if (CheckFlag(CarrotFlag::FLATDETH_FLAG)) {
				auto pos = mAnim->GetPosition() + GetVector2(Dir4::Down, CarrotParam::FLATDEATH_ADJUST_DOWN);
				return new DeathTimerState<>{ mAnim,2, std::move(pos),CarrotParam::FLATDEATH_TIME,CarrotFlag::DEATH_MOTION_FNISH_FLAG };
			}
			if ((Player::GetPosition() - mPhysicsModel.mPosition).Length() >= CarrotParam::ACTIVE_RANGE)
				return new Stay{ mAnim };


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

		GameLib::Vector2 Active::GetPowerPerFrame()
		{
			GameLib::Vector2 result{};

			auto playerPos = Player::GetPosition();
			auto myPos = mPhysicsModel.mPosition;
			auto dirVec = playerPos - myPos;

			if (GetDir4DirectionSize(dirVec, Dir4::Right) > 0.f)
				result += GetVector2(Dir4::Right, CarrotParam::RUN_POWER);
			else
				result += GetVector2(Dir4::Left, CarrotParam::RUN_POWER);

			return result + Gravity::GetVector2();
		}

		void Active::AdjustAnim()
		{
			mAnim->Set(mPhysicsModel.mPosition, mPhysicsModel.mScale, mPhysicsModel.mRotation);
		}

		void Active::AdjustColliders()
		{
			using namespace CarrotParam;

			mWeakness.SetPosition(mPhysicsModel.mPosition + GetVector2(Dir4::Up, HEIGHT * WEAKNESS_RATE * SCALE / 2.f));
			mWeakness.SetRotation(mPhysicsModel.mRotation);
		
			mStrength.SetPosition(mPhysicsModel.mPosition + GetVector2(Dir4::Down, HEIGHT * STREANGTH_RATE * SCALE / 2.f));
			mStrength.SetRotation(mPhysicsModel.mRotation);
		}
	}
}