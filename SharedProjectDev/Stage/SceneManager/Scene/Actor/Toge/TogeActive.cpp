#include"TogeActive.hpp"
#include"TogeParam.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/Utilty/Geometry.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"Stage/Utilty/IsInScope.hpp"
#include"Stage/WindowSize.hpp"
#include"Stage/Gravity/Gravity.hpp"

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

			auto hitGround = [this](const GameLib::Collider& c) {
				auto adjust = GetParallelRectAdjustVec(mCollider, c);
				//std::cout << "adjust: " << adjust.x << "," << adjust.y << "\n";
				mPhysicsModel.mPosition += adjust;

				auto adjustDir4Vec = GetDir4Vec(adjust);

				if (adjustDir4Vec.mDir4 == Dir4::Up)
					mPhysicsModel.mVelocity = GameLib::Vector2{};

				ReflectAnimation();
				ReflectCollider();
			};

			mCollider.AddHitFunction("Ground", std::move(hitGround));

			ReflectAnimation();
			ReflectCollider();
		}

		bool Active::UpdateOrNot()
		{
			auto pos = mPhysicsModel.mPosition;
			return IsInScope(pos, WindowSize::WIDTH + 200.f, WindowSize::WIDTH + 200.f);
		}
		
		StateBase<>* Active::Update()
		{
			mPhysicsModel.mScale = TogeParam::SCALE_CENTER + TogeParam::SCALE_RADIUS * std::sin(mCnt / 100.f);
			mPhysicsModel.Update(Gravity::GetVector2());

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