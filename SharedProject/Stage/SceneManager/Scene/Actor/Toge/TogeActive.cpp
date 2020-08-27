#include"TogeActive.hpp"
#include"TogeParam.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/Utilty/Geometry.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"Stage/Utilty/IsInScope.hpp"
#include"Stage/WindowSize.hpp"
#include"Stage/Gravity/Gravity.hpp"
#include"Stage/SceneManager/Scene/Actor/Trampoline/HitTrampoline.hpp"
#include"Stage/SceneManager/Scene/Actor/Trampoline/TrampolineParam.hpp"

namespace Stage
{
	namespace TogeState
	{
		Active::Active(GameLib::DrawAnimation* anim)
			:StateBase{}
			, mAnim{anim}
			, mCollider{"TogeBody"}
			, mPhysicsModel{}
			, mCnt{ 0 }
		{
			mCollider.SetWidthAndHeith(TogeParam::WIDTH, TogeParam::HEIGHT);
			mCollider.SetColor({ 0,0,255,255 });

			mPhysicsModel.mPosition = mAnim->GetPosition();
			mPhysicsModel.mScale = TogeParam::SCALE_CENTER;

			auto hitGround = [this](const GameLib::Collider& c) {
				auto adjust = GetParallelRectAdjustVec(mCollider, c);
				//std::cout << "adjust: " << adjust.x << "," << adjust.y << "\n";

				auto adjustDir4Vec = GetDir4Vec(adjust);

				if (adjustDir4Vec.mDir4 == Dir4::Up) {
					mPhysicsModel.mVelocity = GameLib::Vector2{};
					adjust += c.GetRerativePos();
				}

				mPhysicsModel.mPosition += adjust;

				ReflectAnimation();
				ReflectCollider();
			};

			auto hitT = [this, hitGround](Dir4&& dir, const GameLib::Collider& c) {
				auto v = hitTrampoline(mPhysicsModel.mVelocity, mCollider, std::move(dir), c, TrampolineParam::ENEMY_POWER);
				hitGround(c);
				mPhysicsModel.mVelocity = v;
			};
			auto hitUpT = [this, hitT](const GameLib::Collider& c) {
				hitT(Dir4::Up, c);
			};
			auto hitDonwT = [this, hitT](const GameLib::Collider& c) {
				hitT(Dir4::Down, c);
			};
			auto hitRightT = [this, hitT](const GameLib::Collider& c) {
				hitT(Dir4::Right, c);
			};
			auto hitLeftT = [this, hitT](const GameLib::Collider& c) {
				hitT(Dir4::Left, c);
			};

			auto hitThrough = [this, hitGround](const GameLib::Collider& c) {
				auto ad = GetParallelRectAdjustVec(mCollider, c);
				if (GetDir4DirectionSize(ad, Dir4::Up))
					hitGround(c);
			};

			mCollider.AddHitFunction("ThroughFloor", std::move(hitThrough));

			mCollider.AddHitFunction("TogeBlock", hitGround);
			mCollider.AddHitFunction("Ground", std::move(hitGround));
			mCollider.AddHitFunction("UpTrampoline", std::move(hitUpT));
			mCollider.AddHitFunction("DonwTrampoline",std::move(hitDonwT));
			mCollider.AddHitFunction("RightTrampoline", std::move(hitRightT));
			mCollider.AddHitFunction("LeftTrampoline", std::move(hitLeftT));

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
			//std::cout << mPhysicsModel.mPosition.x << "," << mPhysicsModel.mPosition.y << "\n";

			mPhysicsModel.mScale = TogeParam::SCALE_CENTER + TogeParam::SCALE_RADIUS * std::sin(mCnt * TogeParam::ROT_PER_FRAME);

			//kari
			UpdatePhysicsModelWithGravity(mPhysicsModel, Gravity::GetVector2(), 20. - 1.f, false);

			ReflectAnimation();
			ReflectCollider();

			mCnt++;
			return this;
		}

		void Active::BeginWorking()
		{
			mCollider.Active();
		}

		void Active::BeginToRest()
		{
			mCollider.Pause();
		}

		void Active::ReflectAnimation()
		{
			mAnim->Set(mPhysicsModel.mPosition, mPhysicsModel.mScale, mPhysicsModel.mRotation);
		}

		void Active::ReflectCollider()
		{
			mCollider.Set(mPhysicsModel.mPosition, mPhysicsModel.mScale, mPhysicsModel.mRotation);
		}

	}
}