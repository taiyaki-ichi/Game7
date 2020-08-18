#include"DoguStay.hpp"
#include"DoguParam.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/SceneManager/Scene/Actor/Player.hpp"
#include"DoguActive.hpp"
#include"Stage/Gravity/Gravity.hpp"
#include"Stage/Gravity/GravityFunc.hpp"

namespace Stage
{
	namespace DoguState
	{
		Stay::Stay(GameLib::DrawAnimation* anim)
			:StateBase<>{}
			, mAnim{ anim }
			, mCnt{ 0 }
			, mPos{ anim->GetPosition()}
		{
			mAnim->SetChannel(0);
			mAnim->SetScale(DoguParam::SCALE);
		}

		StateBase<>* Stay::Update()
		{
			if (mCnt!=0&&(mPos - Player::GetPosition()).Length() < DoguParam::ACTIVE_RANGE)
				return new Active{ mAnim };

			mAnim->SetPosition(mPos + GetVector2(Dir4::Up, std::sin(mCnt / DoguParam::CNT_PER_ROT) * DoguParam::MOVE_LENGTH_Y));
			mAnim->SetRotation(Gravity::GetRotation());
			mCnt++;

			return this;
		}

	}
}