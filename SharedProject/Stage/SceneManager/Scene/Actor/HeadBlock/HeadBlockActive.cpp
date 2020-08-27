#include"HeadBlockActive.hpp"
#include"HeadBlockParam.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/Utilty/Geometry.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"HeadBlockFlag.hpp"
#include"Stage/Utilty/State/FallState.hpp"

namespace Stage
{
	namespace HeadBlockState
	{
		Active::Active(GameLib::DrawAnimation* anim)
			:StateBase{}
			, mAnim{anim}
			, mRect{}
			, mCnt{}
			, mCollider{"Ground"}
		{
			using namespace HeadBlockParam;

			mRect.SetColor({ 100,100,100,255 });
			mRect.SetWidthAndHeight(WIDTH, 0.f);

			auto pos = mAnim->GetPosition() + GameLib::Vector2{ 0.f,-HEIGHT * SCALE / 2.f };
			mRect.SetPosition(std::move(pos));
			mRect.SetDrawOrder(BLACKRECT_DRAWORDER);

			mCollider.SetWidthAndHeith(WIDTH, HEIGHT);
			mCollider.SetScale(SCALE);
			mCollider.SetColor({ 0,255,0,255 });
			mCollider.SetPosition(mAnim->GetPosition());

			auto hitPlayer = [this](const GameLib::Collider& c) {
				auto ad = GetParallelRectAdjustVec(mCollider, c);
				if (GetDir4DirectionSize(ad, Dir4::Down) > 0.f)
					UpFlag(HeadBlockFlag::ON_PLAYER_FLAG);
			};

			mCollider.AddHitFunction("Player", std::move(hitPlayer));
		}

		StateBase<>* Active::Update()
		{
			using namespace HeadBlockParam;

			if (CheckFlag(HeadBlockFlag::ON_PLAYER_FLAG)) {
				mCnt++;
				mAnim->SetChannel(1);
			}
			else if (mCnt > 0) {
				mCnt--;
				mAnim->SetChannel(0);
			}
			else
				mAnim->SetChannel(0);

			if (mCnt >= PLAYER_RIDE_TIME)
				return new FallState<>{ mAnim,FALL_SPEED,FALL_ROT,FALL_DEATH_LINE,2 };

			float h = HEIGHT * SCALE * static_cast<float>(mCnt) / static_cast<float>(PLAYER_RIDE_TIME);
			mRect.SetWidthAndHeight(WIDTH * SCALE, h);
			mRect.SetPosition(mAnim->GetPosition() + GameLib::Vector2{ 0.f,-HEIGHT * SCALE / 2.f + h / 2.f });

			DownFlag(HeadBlockFlag::ON_PLAYER_FLAG);

			return this;
		}

		void Active::BeginWorking()
		{
			mRect.SetIsAutoDrawing(true);
			mCollider.Active();
		}

		void Active::BeginToRest()
		{
			mRect.SetIsAutoDrawing(false);
			mCollider.Pause();
		}

		
	}
}