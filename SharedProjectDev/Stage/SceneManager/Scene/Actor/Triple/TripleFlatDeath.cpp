#include"TripleFlatDeath.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"TripleParam.hpp"
#include"TripleFlag.hpp"

namespace Stage
{
	namespace TripleState
	{

		FlatDeath::FlatDeath(GameLib::DrawAnimation* anim)
			:StateBase{}
			, mCnt{ 0 }
		{
			int c = anim->GetChannel();
			anim->SetChannel(c + 2);
			auto aniPos = anim->GetPosition();
			anim->SetPosition(aniPos + GetVector2(Dir4::Down, 20.f));
		}

		StateBase<>* FlatDeath::Update()
		{
			mCnt++;
			if (mCnt > TripleRaram::FLAT_DEATH_TIME)
				UpFlag(TripleFlag::DEATH_MOTION_FINISH_FLAG);

			return this;
		}
	}
}