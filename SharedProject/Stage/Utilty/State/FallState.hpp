#pragma once
#include"StageStateBase.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Stage/WindowSize.hpp"
#include"Stage/Utilty/IsInScope.hpp"

namespace Stage
{
	template<typename T=unsigned char>
	class FallState : public StateBase<T>
	{
		GameLib::DrawAnimation* mAnim;
		float mSpeed;
		float mDeltaRot;

		//‰æ–ÊŠO‚Ì•A‰z‚¦‚½‚çDeath
		float mDeathLine;

		//DeathLine‰z‚¦‚½‚ç—§‚Ä‚é
		T mFlag;

	public:
		FallState(GameLib::DrawAnimation* anim,float speed,float deltaRot,float deathLine,T flag,int channel=-1)
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
			
			if(!IsInScope(pos,WindowSize::WIDTH+mDeathLine,WindowSize::WIDTH+mDeathLine))
				this->UpFlag(mFlag);

			return this;
		}

		void BeginWorking() override {};
		void BeginToRest() override {};

	};
}