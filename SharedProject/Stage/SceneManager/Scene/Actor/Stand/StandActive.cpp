#include"StandActive.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"StandParam.hpp"
#include"Stage/SceneManager/Scene/Actor/Player.hpp"
#include"GameLib/include/Math/Numbers.hpp"
#include"StandDown.hpp"
#include"StandFlag.hpp"

namespace Stage
{
	namespace StandState
	{
		Active::Active(GameLib::DrawAnimation* head,GameLib::DrawAnimation* body)
			:StateBase<>{}
			, mHeadAnim{head}
			, mBodyAnim{body}
			, mCnt{ 0 }
			, mCollider{ "Stand" }
		{
			using namespace StandParam;

			mCollider.SetWidthAndHeith(HEAD_WIDTH, HEAD_WIDTH);
			mCollider.SetScale(HEAD_SCALE);
			mCollider.SetColor({ 0,0,255,255 });

			mHeadAnim->SetChannel(0);
			mBodyAnim->SetChannel(0);

			auto headAdjust = GameLib::Vector2{ 0.f,UP_HEAD_ADJUST_UP };
			headAdjust = GameLib::Vector2::Rotation(headAdjust, mBodyAnim->GetRotation());
			mHeadAnim->SetPosition(headAdjust + mBodyAnim->GetPosition());

			mCollider.SetPosition(mHeadAnim->GetPosition());

			auto hitPlayer = [this](const GameLib::Collider& c) {
				UpFlag(StandFlag::DOWN_FLAG);
			};

			mCollider.AddHitFunction("Player", std::move(hitPlayer));
		}

		StateBase<>* Active::Update()
		{
			if (CheckFlag(StandFlag::DOWN_FLAG))
				return new Down{ mHeadAnim,mBodyAnim };

			using namespace StandParam;

			auto dir = Player::GetPosition() - mHeadAnim->GetPosition();
			float rot = std::atan2(dir.x, dir.y);
			
			if (0.f < rot && rot < GameLib::PI) {
				mHeadAnim->SetHorizontalFlip(true);
				mBodyAnim->SetHorizontalFlip(true);
			}
			else {
				mHeadAnim->SetHorizontalFlip(false);
				mBodyAnim->SetHorizontalFlip(false);
				rot += GameLib::PI;

			}
			
			mHeadAnim->SetRotation(-rot + GameLib::PI / 2.f);

			mCollider.SetRotation(mHeadAnim->GetRotation());

			if (mCnt <= COOLDOWN_TIME)
			{
				mHeadAnim->SetChannel(0);
			}
			else if (mCnt == COOLDOWN_TIME + 1)
			{
				mHeadAnim->SetChannel(1);
			}
			else if (mCnt <= COOLDOWN_TIME + BEAM_TIME)
			{
				//Spore¶¬
				if (mCnt % FLAME_PER_SPORE == 0)
				{
					UpFlag(StandFlag::SPORE_FLAG);
				}
			}
			else 
			{
				mCnt = 0;
				mHeadAnim->SetChannel(0);
			}

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