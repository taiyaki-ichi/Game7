#include"GoalText.hpp"
#include"GoalTextParam.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"Stage/Utilty/GetScreenPos.hpp"

namespace Stage
{
	GoalText::GoalText(GameLib::Actor* actor)
		:GameLib::Actor{ actor }
		, mTexture{ "../Assets/Object/Goal/Goal.png" }
		, mIsMove{true}
	{
		auto pos = GetScreenPos(GetVector2(Dir4::Up, GoalTextParam::START_Y));
		mTexture.SetPosition(pos);
		mTexture.SetScale(GoalTextParam::SCALE);
		mTexture.SetDrawOrder(20);
	}

	void GoalText::CustomizeUpdate()
	{
		if (mIsMove)
		{
			auto pos = mTexture.GetPosition();
			pos += GetVector2(Dir4::Down, GoalTextParam::SPEED);
			pos = GetDirSizeSetVector2(pos, Dir4::Right, GameLib::Viewport::GetPos().x);

			if (GetDir4DirectionSize(pos,Dir4::Up) < GoalTextParam::POS_Y)
			{
				pos = GetDirSizeSetVector2(pos, Dir4::Up, GoalTextParam::POS_Y);
				mIsMove = false;
			}

			mTexture.SetPosition(pos);
		}
	}
}