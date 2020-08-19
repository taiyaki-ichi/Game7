#include"CarrotStay.hpp"
#include"CarrotParam.hpp"
#include"Stage/Utilty/Geometry.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/SceneManager/Scene/Actor/Player.hpp"
#include"CarrotActive.hpp"
#include"Stage/Gravity/Gravity.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"Stage/Utilty/IsInScope.hpp"
#include"Stage/WindowSize.hpp"


namespace Stage
{
	namespace CarrotState
	{
		Stay::Stay(GameLib::DrawAnimation* anim)
			:StateBase<>{}
			, mAnim{ anim }
			, mCollider{}
			, mPower{}
		{
			mCollider.SetScale(CarrotParam::SCALE);
			mCollider.SetWidthAndHeith(CarrotParam::WIDTH, CarrotParam::HEIGHT);

			auto hitGround = [this](const GameLib::Collider& c)
			{
				auto adjustVec = GetParallelRectAdjustVec(mCollider, c);

				if (GetDir4DirectionSize(adjustVec, Dir4::Up) > 0.f)
					mPower = GetDirSizeSetVector2(mPower, Dir4::Up, 0.f);

				auto pos = mCollider.GetPosition();
				pos += adjustVec;

				mCollider.SetPosition(pos);
				mAnim->SetPosition(std::move(pos));
			};

			mCollider.AddHitFunction("Ground", std::move(hitGround));
			mCollider.SetPosition(mAnim->GetPosition());

			mAnim->SetChannel(0);

		}


		bool Stay::UpdateOrNot()
		{
			auto pos = mAnim->GetPosition();
			return IsInScope(pos, WindowSize::WIDTH, WindowSize::WIDTH);
		}


		StateBase<>* Stay::Update()
		{
			auto myPos = mCollider.GetPosition();
			auto playerPos = Player::GetPosition();
			if ((playerPos - myPos).Length() < CarrotParam::ACTIVE_RANGE)
				return new Active{ mAnim };

			mPower += Gravity::GetVector2();

			myPos += mPower;
			mCollider.SetPosition(myPos);
			mAnim->SetPosition(myPos);

			mCollider.SetRotation(Gravity::GetRotation());
			mAnim->SetRotation(Gravity::GetRotation());

			return this;
		}

		void Stay::BeginWorking()
		{
			mCollider.Active();
		}

		void Stay::BeginToRest()
		{
			mCollider.Pause();
		}

	}
}