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
			, mBodyCollider{}
		{
			mCurseCollider.SetWidthAndHeith(DoguParam::CURSE_WIDTH, DoguParam::HEIGHT);
			mCurseCollider.SetScale(DoguParam::CURSE_SCALE);
			mCurseCollider.SetColor({ 0,0,255,255 });

			mBodyCollider.SetWidthAndHeith(DoguParam::WIDTH* DoguParam::SCALE, DoguParam::HEIGHT* DoguParam::SCALE);
			mBodyCollider.SetColor({ 0,0,255,255 });

			auto hitPlayer = [this](const GameLib::Collider& c)
			{
				UpFlag(DoguFlag::CURSE_HIT_PLAYER_FLAG);
			};

			mBodyCollider.AddHitFunction("Player", std::move(hitPlayer));

			mBodyCollider.SetPosition(mAnim->GetPosition());
			mCurseCollider.SetPosition(mAnim->GetPosition());

			mAnim->SetScale(DoguParam::CURSE_SCALE);
			mAnim->SetChannel(2);
		}

		StateBase<>* Curse::Update()
		{
			if (!CheckFlag(DoguFlag::CURSE_HIT_PLAYER_FLAG))
				mCnt++;
			DownFlag(DoguFlag::CURSE_HIT_PLAYER_FLAG);

			if (mCnt > DoguParam::CURSE_TIME)
				return new Active{ mAnim };

			return this;
		}

		void Curse::BeginWorking()
		{
			mCurseCollider.Active();
			mBodyCollider.Active();
		}

		void Curse::BeginToRest()
		{
			mCurseCollider.Pause();
			mBodyCollider.Pause();
		}
	}
}