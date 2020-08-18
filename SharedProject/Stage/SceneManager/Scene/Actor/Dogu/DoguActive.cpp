#include"DoguActive.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"DoguParam.hpp"
#include"Stage/SceneManager/Scene/Actor/Player.hpp"
#include"Stage/Gravity/Gravity.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"DoguFlag.hpp"
#include"DoguCurse.hpp"
#include"DoguStay.hpp"

namespace Stage
{
	namespace DoguState
	{
		Active::Active(GameLib::DrawAnimation* anim)
			: StateBase<>{}
			, mAnim{anim}
			, mCnt{ 0 }
			, mCollider{}
			, mPos{anim->GetPosition()}
		{
			mAnim->SetChannel(1);
			mAnim->SetScale(DoguParam::SCALE);

			mCollider.SetScale(DoguParam::SCALE);
			mCollider.SetWidthAndHeith(DoguParam::WIDTH, DoguParam::HEIGHT);
			mCollider.SetColor({ 0,0,255,255 });

			mCollider.SetPosition(mAnim->GetPosition());

			auto hitPlayer = [this](const GameLib::Collider& c)
			{
				UpFlag(DoguFlag::CURSE_FLAG);
			};

			mCollider.AddHitFunction("Player", std::move(hitPlayer));
		}

		StateBase<>* Active::Update()
		{
			if (CheckFlag(DoguFlag::CURSE_FLAG))
				return new Curse{ mAnim };

			if ((mPos - Player::GetPosition()).Length() >= DoguParam::ACTIVE_RANGE)
				return new Stay{ mAnim };

			auto playerPos = Player::GetPosition();
			auto vec = playerPos - mPos;
			vec.Normalize();
			vec *= DoguParam::SPEED;

			mPos += vec;

			auto pos = mPos + GetVector2(Dir4::Up, std::sin(mCnt / DoguParam::CNT_PER_ROT) * DoguParam::MOVE_LENGTH_Y);
			mAnim->SetPosition(pos);
			mAnim->SetScale(DoguParam::SCALE);
			mAnim->SetRotation(Gravity::GetRotation());

			mCollider.SetPosition(pos);
			mCollider.SetRotation(Gravity::GetRotation());

			mCnt++;

			return this;
		}

		void Active::BeginWorking()
		{
			mCollider.Active();
		}

		void Active::BeginToRest()
		{
			mCollider.Pause();
		}


		
	}
}