#include"MaiStay.hpp"
#include"MaiAdjustCollider.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/SceneManager/Scene/Actor/Player.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"MaiLaunch.hpp"
#include"MaiFlag.hpp"
#include"Stage/Utilty/State/FallState.hpp"
#include"Stage/Utilty/IsInScope.hpp"

namespace Stage
{
	namespace MaiState
	{
		Stay::Stay(GameLib::DrawAnimation* anim,const Dir4& dir)
			:StateBase{}
			, mAnim{anim}
			, mStrength{}
			, mWeakness{}
			, mGroundDir4{}
			, mCnt{0}
		{
			AdjustCollider(mStrength, mWeakness, mAnim->GetPosition());
			mAnim->SetChannel(0);

			auto hitPlayerW = [this](const GameLib::Collider& c) {
				UpFlag(MaiFlag::FALL_DEATH);
			};

			mWeakness.AddHitFunction("Player", std::move(hitPlayerW));
			
		}

		bool Stay::UpdateOrNot()
		{
			return IsInScope(mAnim->GetPosition(), WindowSize::WIDTH + MaiParam::ACTIVE_LINE, WindowSize::WIDTH + MaiParam::ACTIVE_LINE);
		}

		StateBase<>* Stay::Update()
		{
			if (CheckFlag(MaiFlag::FALL_DEATH))
				return new FallState<>{ mAnim,MaiParam::FALL_DEATH_SPEED,MaiParam::FALL_DEATH_DELTAROT,50.f,MaiFlag::DEATH_MOTION_FNISH_FLAG ,2 };
	

			if (mCnt >= MaiParam::STAY_TIME)
				return new Launch{ mAnim,mGroundDir4 };
			mCnt++;

			GameLib::Vector2 n{ 0.f,1.f };
			n = GameLib::Vector2::Rotation(n, mAnim->GetRotation());

			if (!GameLib::IsClockwise(mAnim->GetPosition() - n, mAnim->GetPosition(), Player::GetPosition()))
				mAnim->SetHorizontalFlip(true);
			else
				mAnim->SetHorizontalFlip(false);

			AdjustCollider(mStrength, mWeakness, mAnim->GetPosition());

			return this;
		}

		void Stay::BeginWorking()
		{
			mStrength.Active();
			mWeakness.Active();
		}

		void Stay::BeginToRest()
		{
			mStrength.Pause();
			mWeakness.Pause();
		}
	}
}