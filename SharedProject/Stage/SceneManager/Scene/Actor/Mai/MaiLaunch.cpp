#include"MaiLaunch.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"MaiParam.hpp"
#include"MaiFlag.hpp"
#include"MaiStay.hpp"
#include"MaiColliderSetting.hpp"
#include"Stage/Utilty/State/FallState.hpp"

namespace Stage
{
	namespace MaiState
	{
		Launch::Launch(GameLib::DrawAnimation* anim,const Dir4& dir)
			:StateBase{}
			,mAnim{anim}
			, mGroundDir4{ dir }
			, mCnt{ 0 }
			, mStrength{}
			, mWeakness{}
		{
			mAnim->SetChannel(1);
			ColliderSetting(mStrength, mWeakness, mAnim->GetPosition(), mGroundDir4);

			auto hitPlayerW = [this](const GameLib::Collider& c) {
				UpFlag(MaiFlag::FALL_DEATH);
			};

			mWeakness.AddHitFunction("Player", std::move(hitPlayerW));
		}

		StateBase<>* Launch::Update()
		{

			if (CheckFlag(MaiFlag::FALL_DEATH))
				return new FallState<>{ mAnim,MaiParam::FALL_DEATH_SPEED,MaiParam::FALL_DEATH_DELTAROT,50.f,MaiFlag::DEATH_MOTION_FNISH_FLAG ,2 };


			if (mCnt == MaiParam::LAUNCH_TIME)
			{
				UpFlag(MaiFlag::LAUNCH_NAIL_FLAG);
			}
			else if (mCnt > MaiParam::LAUNCH_TIME)
			{
				return new Stay{ mAnim,mGroundDir4 };
			}

			mCnt++;


			return this;
		}

		void Launch::BeginWorking()
		{
			mStrength.Active();
			mWeakness.Active();
		}

		void Launch::BeginToRest()
		{
			mStrength.Pause();
			mWeakness.Pause();
		}
	}
}