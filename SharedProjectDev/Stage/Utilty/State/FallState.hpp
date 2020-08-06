#pragma once
#include"StageStateBase.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Stage/WindowSize.hpp"

namespace Stage
{
	template<typename T>
	class FallState : public StateBase<T>
	{
		GameLib::DrawAnimation* mAnim;
		float mSpeed;
		float mDeltaRot;

		//âÊñ äOÇÃïùÅAâzÇ¶ÇΩÇÁDeath
		float mDeathLine;

		//DeathLineâzÇ¶ÇΩÇÁóßÇƒÇÈ
		T mFlag;

	public:
		FallState(GameLib::DrawAnimation* anim,T fallFlag,float speed,float deltaRot,float deathLine,T flag,int channel=-1)
			:StateBase<T>{}
			, mAnim{anim}
			, mSpeed{ speed }
			, mDeltaRot{ deltaRot }
			, mDeathLine{deathLine}
			, mFlag{flag}
		{

			if (channel > 0)
				mAnim->SetChannel(channel);
		}
		virtual ~FallState() = default;

		StateBase<T>* Update()
		{
			auto pos = mAnim->GetPosition();
			pos += GetVector2(Dir4::Down, mSpeed);
			mAnim->SetPosition(pos);

			float rot = mAnim->GetRotation();
			rot += mDeltaRot;
			mAnim->SetRotation(rot);

			auto viewPos = pos - GameLib::Viewport::GetPos();
			float viewDownSize = GetDir4DirectionSize(viewPos, Dir4::Down);
			if (viewDownSize > WindowSize::HEIGHT / 2.f + mDeathLine)
				UpFlag(mFlag);
		}


	};
}