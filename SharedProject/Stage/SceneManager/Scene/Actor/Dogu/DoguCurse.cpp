#include"DoguCurse.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"DoguParam.hpp"
#include"DoguFlag.hpp"
#include"DoguActive.hpp"

namespace Stage
{
	namespace DoguState
	{
		Curse::Curse(GameLib::DrawAnimation* anim)
			:StateBase<>{}
			, mAnim{anim}
			, mCnt{0}
			, mCurseCollider{"DoguCurse"}
		{
			mCurseCollider.SetWidthAndHeith(DoguParam::CURSE_WIDTH, DoguParam::HEIGHT);
			mCurseCollider.SetScale(DoguParam::CURSE_SCALE);
			mCurseCollider.SetColor({ 0,0,255,255 });

			mCurseCollider.SetPosition(mAnim->GetPosition());

			mAnim->SetScale(DoguParam::CURSE_SCALE);
			mAnim->SetChannel(2);
		}

		StateBase<>* Curse::Update()
		{
			
			mCnt++;
			if (mCnt > DoguParam::CURSE_TIME)
				return new Active{ mAnim };

			return this;
		}

		void Curse::BeginWorking()
		{
			mCurseCollider.Active();
		}

		void Curse::BeginToRest()
		{
			mCurseCollider.Pause();
		}
	}
}