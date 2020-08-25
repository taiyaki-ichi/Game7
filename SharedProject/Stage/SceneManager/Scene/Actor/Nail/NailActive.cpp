#include"NailActive.hpp"
#include"NailParam.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"NailFlag.hpp"
#include"Stage/Utilty/State/FallState.hpp"

namespace Stage
{
	namespace NailState
	{
		Active::Active(GameLib::DrawAnimation* anim,Dir4&& dir)
			:StateBase{}
			,mAnim{anim}
			,mDir{std::move(dir)}
			, mStrength{"NailStrength"}
			, mWeakness{"NailWeakness"}
		{
			using namespace NailParam;

			mStrength.SetWidthAndHeith(STRENGTH_WIDTH, STRENGTH_HEIGHT);
			mStrength.SetScale(SCALE);
			mStrength.SetColor({ 0,0,255,255 });

			mWeakness.SetWidthAndHeith(WEAKNESS_WIDTH, WEAKNES_HEIGHT);
			mWeakness.SetScale(SCALE);
			mWeakness.SetColor({ 0,255,0,255 });

			if (mDir == Dir4::Right)
				mAnim->SetRotation(GameLib::PI);
			else if (mDir == Dir4::Down)
				mAnim->SetRotation(GameLib::PI / 2.f);
			else if (mDir == Dir4::Up)
				mAnim->SetRotation(GameLib::PI / 2.f * 3.f);

			AdjustColiider();

			auto hitPlayerW = [this](const GameLib::Collider& c) {
				UpFlag(NailFlag::FALL_FLAG);
			};
			mWeakness.AddHitFunction("Player", std::move(hitPlayerW));
		}

		StateBase<>* Active::Update()
		{
			//std::cout << mAnim->GetPosition().x << "," << mAnim->GetPosition().y << "\n";

			if (CheckFlag(NailFlag::FALL_FLAG)) {
				mAnim->SetDrawOrder(1);
				return new FallState<>{ mAnim,NailParam::FALL_SPEED,NailParam::FALL_DELTAROT,20.f,NailFlag::DEATH_FLAG };
			}

			GameLib::Vector2 v{ -NailParam::SPEED,0.f };
			v = GameLib::Vector2::Rotation(v, mAnim->GetRotation());
			mAnim->SetPosition(mAnim->GetPosition() + v);

			AdjustColiider();

			return this;
		}

		void Active::BeginWorking()
		{
			mStrength.Active();
			mWeakness.Active();
		}

		void Active::BeginToRest()
		{
			mStrength.Pause();
			mWeakness.Pause();
		}

		void Active::AdjustColiider()
		{
			using namespace NailParam;

			auto pos = mAnim->GetPosition();
			float rot = mAnim->GetRotation();

			GameLib::Vector2 adjustS{ -STRENGTH_ADJUST_LEFT,0.f };
			adjustS = GameLib::Vector2::Rotation(adjustS, rot);
			mStrength.SetPosition(pos + adjustS);

			GameLib::Vector2 adjustW{ WEAKNESS_ADJUST_RIGHT,0.f };
			adjustW = GameLib::Vector2::Rotation(adjustW, rot);
			mWeakness.SetPosition(pos + adjustW);
		}
	}
}