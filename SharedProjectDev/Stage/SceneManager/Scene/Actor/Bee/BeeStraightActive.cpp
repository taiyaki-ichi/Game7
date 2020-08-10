#include"BeeStraightActive.hpp"
#include"BeeParam.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"Stage/Utilty/AdjustRot.hpp"
#include"Stage/Gravity/Gravity.hpp"

namespace Stage
{
	namespace BeeState
	{

		StraightActive::StraightActive(GameLib::DrawAnimation* anim,GameLib::Vector2&& c,GameLib::Vector2&& r)
			:StateBase<>{}
			, mAnim{anim}
			, mWeakness{"BeeWeakness"}
			, mStrength{"BeeStrength"}
			, mCenter{std::move(c)}
			, mRadiusVec{ std::move(r) }
			, mCnt{ 0 }
		{
			using namespace BeeParam;

			mWeakness.SetScale(SCALE);
			mWeakness.SetWidthAndHeith(WIDTH, HEIGHT* WEAKNESS_RATE);
			mWeakness.SetColor({ 0,255,0,255 });

			mStrength.SetScale(SCALE);
			mStrength.SetWidthAndHeith(WIDTH, HEIGHT* STRENGTH_RATE);
			mWeakness.SetColor({ 0,0,255,255 });
		}

		StateBase<>* StraightActive::Update()
		{

			float rot = mCnt / 50.f;
			auto pos = mCenter + std::cos(rot) * mRadiusVec;
			mAnim->SetPosition(pos);

			using namespace BeeParam;
			mWeakness.SetPosition(pos + GetVector2(Dir4::Up, HEIGHT * WEAKNESS_RATE * SCALE));
			mWeakness.SetRotation(Gravity::GetRotation());
			mStrength.SetPosition(pos + GetVector2(Dir4::Down, HEIGHT * STRENGTH_RATE * SCALE));
			mStrength.SetRotation(Gravity::GetRotation());

			rot = AdjustRot(rot);
			if (rot < GameLib::PI)
				mAnim->SetRotation(-std::atan2(mRadiusVec.x, mRadiusVec.y) + GameLib::PI / 2.f);
			else
				mAnim->SetRotation(-std::atan2(mRadiusVec.x, mRadiusVec.y) - GameLib::PI / 2.f);

			mCnt++;

			return this;
		}

		void StraightActive::BeginWorking()
		{
			mWeakness.Active();
			mStrength.Active();
		}

		void StraightActive::BeginToRest()
		{
			mWeakness.Pause();
			mStrength.Pause();
		}

	}
}