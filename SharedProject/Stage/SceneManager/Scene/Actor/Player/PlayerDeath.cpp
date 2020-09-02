#include"PlayerDeath.hpp"
#include"PlayerParam.hpp"
#include"PlayerFlag.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"

namespace Stage::PlayerState
{
	Death::Death(GameLib::DrawAnimation* anim)
		:StateBase{}
		, mAnimation{ anim }
	{
		mAnimation->SetChannel(8);

		UpFlag(PlayerFlag::DEATH_FLAG);
	}
	Stage::StateBase<char>* Death::Update()
	{
		mCnt++;
		if (mCnt > PlayerParam::DEATH_CNT)
			UpFlag(PlayerFlag::DEATH_MOTION_FINISH_FLAG);

		auto pos = mAnimation->GetPosition();
		pos += GetVector2(Dir4::Up, 4.f);

		float scale = mAnimation->GetScale();
		scale *= 0.99f;

		float rot = mAnimation->GetRotation();
		rot += 0.3f;

		mAnimation->Set(std::move(pos), scale, rot);

		return this;

	}
	void Death::SetPosition(const GameLib::Vector2& pos)
	{
		mAnimation->SetPosition(pos);
	}
}