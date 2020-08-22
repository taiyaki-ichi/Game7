#include"BeeFallDeath.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"BeeParam.hpp"
#include"Stage/Utilty/IsInScope.hpp"
#include"Stage/WindowSize.hpp"
#include"BeeFlag.hpp"

namespace Stage
{
	namespace BeeState
	{
		FallDeath::FallDeath(GameLib::DrawAnimation* anim)
			:mAnim{anim}
		{
			mAnim->SetChannel(1);
		}

		StateBase<>* FallDeath::Update()
		{
			auto pos = mAnim->GetPosition();

			if (!IsInScope(pos, WindowSize::WIDTH + BeeParam::FALL_MOTION_FINISH_LINE, WindowSize::WIDTH + BeeParam::FALL_MOTION_FINISH_LINE))
				UpFlag(BeeFlag::DEATH_MOTION_FNISH_FLAG);

			pos += GetVector2(Dir4::Down, BeeParam::FALL_SPEED);
			mAnim->SetPosition(std::move(pos));

			float rot = mAnim->GetRotation();
			rot += BeeParam::FALL_ROT;
			mAnim->SetRotation(rot);

			return this;

		}

		
	}
}