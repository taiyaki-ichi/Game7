#pragma once
#include"StageStateBase.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"

namespace Stage
{
	template<typename T=char>
	class DeathTimerState : public StateBase<T>
	{
		const int mDeatTime;
		int mCnt;

		GameLib::DrawAnimation* mAnim;

		const T mTimeOverFlag;

	public:
		DeathTimerState(GameLib::DrawAnimation* anim,int animChannel,const GameLib::Vector2& animPos,int deathTime,T timeOrverFlag)
			:StateBase<T>{}
			, mAnim{anim}
			, mDeatTime{ deathTime }
			, mTimeOverFlag{ timeOrverFlag }
			, mCnt{0}
		{
			mAnim->SetChannel(animChannel);
			mAnim->SetPosition(animPos);
		}

		StateBase<T>* Update() override
		{
			mCnt++;
			if (mCnt > mDeatTime)
				this->UpFlag(mTimeOverFlag);
			
			return this;
		}

		virtual void BeginWorking() override
		{
			mAnim->SetIsAutoDrawing(true);
		}

		virtual void BeginToRest() override
		{
			mAnim->SetIsAutoDrawing(false);
		}
	};
}