#include"CarrotStay.hpp"
#include"CarrotParam.hpp"
#include"Stage/Utilty/Geometry.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/SceneManager/Scene/Actor/Player.hpp"
#include"CarrotActive.hpp"
#include"Stage/Gravity/Gravity.hpp"

namespace Stage
{
	namespace CarrotState
	{
		Stay::Stay(GameLib::DrawAnimation* anim)
			:StateBase<>{}
			, mAnim{ anim }
			, mCollider{}
		{
			mCollider.SetScale(CarrotParam::SCALE);
			mCollider.SetWidthAndHeith(CarrotParam::WIDTH, CarrotParam::HEIGHT);

			auto hitGround = [this](const GameLib::Collider& c)
			{
				auto adjustVec = GetParallelRectAdjustVec(mCollider, c);
				auto pos = mCollider.GetPosition();
				pos += adjustVec;

				mCollider.SetPosition(pos);
				mAnim->SetPosition(std::move(pos));
			};

			mCollider.AddHitFunction("Ground", std::move(hitGround));
			mCollider.SetPosition(mAnim->GetPosition());

			mAnim->SetChannel(0);

		}

		StateBase<>* Stay::Update()
		{
			auto myPos = mCollider.GetPosition();
			auto playerPos = Player::GetPosition();
			if ((playerPos - myPos).Length() < CarrotParam::ACTIVE_RANGE)
				return new Active{ mAnim };

			myPos += Gravity::GetVector2();
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