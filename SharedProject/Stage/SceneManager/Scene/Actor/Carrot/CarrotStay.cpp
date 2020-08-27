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
#include"Stage/SceneManager/Scene/Actor/Trampoline/HitTrampoline.hpp"
#include"Stage/SceneManager/Scene/Actor/Trampoline/TrampolineParam.hpp"

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

			auto hitT = [this, hitGround](Dir4&& dir, const GameLib::Collider& c) {
				auto v = hitTrampoline(mPower, mCollider, std::move(dir), c, TrampolineParam::ENEMY_POWER);
				hitGround(c);
				mPower = v;
			};
			auto hitUpT = [this, hitT](const GameLib::Collider& c) {
				hitT(Dir4::Up, c);
			};
			auto hitDownT = [this, hitT](const GameLib::Collider& c) {
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
			mCollider.AddHitFunction("Ground", std::move(hitGround));
			mCollider.SetPosition(mAnim->GetPosition());

			mCollider.AddHitFunction("UpTrampoline", std::move(hitUpT));
			mCollider.AddHitFunction("DownTrampoline", std::move(hitDownT));
			mCollider.AddHitFunction("RightTrampoline", std::move(hitRightT));
			mCollider.AddHitFunction("LeftTrampoline", std::move(hitLeftT));

			mAnim->SetChannel(0);

		}


		bool Stay::UpdateOrNot()
		{
			auto pos = mAnim->GetPosition();
			return IsInScope(pos, WindowSize::WIDTH + 50.f, WindowSize::WIDTH + 50.f);
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