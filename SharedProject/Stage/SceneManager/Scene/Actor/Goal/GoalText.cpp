#include"GoalText.hpp"
#include"GoalTextParam.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"Stage/Utilty/GetScreenPos.hpp"
#include"Stage/Gravity/Gravity.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"Stage/Utilty/AdjustRot.hpp"

namespace Stage
{
	GoalText::GoalText(GameLib::Actor* actor)
		:GameLib::Actor{ actor }
		, mTexture{ "../Assets/Object/Goal/goal.png" }
		, mIsMove{ true }
	{
		GameLib::Vector2 pos = GameLib::Viewport::GetPos();
		float rot = AdjustRot(GameLib::Viewport::GetRotation());

		auto adjust = GameLib::Vector2::Rotation(pos + GameLib::Vector2{ 0.f, GoalTextParam::START_Y }, rot);
		mTexture.SetPosition(adjust);
		mTexture.SetScale(GoalTextParam::SCALE);
		mTexture.SetDrawOrder(20);
		mTexture.SetRotation(rot);
	}

	void GoalText::CustomizeUpdate()
	{
		
		if (mIsMove)
		{

			GameLib::Vector2 pos = GameLib::Viewport::GetPos();
			float rot = AdjustRot(GameLib::Viewport::GetRotation());

			auto myPos = GameLib::Vector2::Rotation(mTexture.GetPosition(), -rot);
			myPos -= pos;

			myPos.y -= GoalTextParam::SPEED;
			myPos.x = 0.f;

			if (myPos.y < GoalTextParam::POS_Y)
			{
				myPos.y = GoalTextParam::POS_Y;
				mIsMove = false;
			}

			myPos = GameLib::Vector2::Rotation(myPos + pos, rot);

			mTexture.SetPosition(myPos);
		}
		
		
	}
}