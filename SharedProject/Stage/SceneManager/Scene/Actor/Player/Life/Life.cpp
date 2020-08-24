#pragma once
#include"Life.hpp"
#include"LifeParam.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Stage/Utilty/GetScreenPos.hpp"
#include"Stage/Utilty/AdjustRot.hpp"

namespace Stage
{
	Life::Life(GameLib::Actor* actor,const GameLib::Vector2& adjust)
		:GameLib::Actor{actor,200}
		, mTexture{"../Assets/Player/Life/board.png"}
		, mNumText{ "../Assets/Font/mplus-1c-black.ttf" }
		, mLifeNum{ 3 }
		, mAdjust{adjust}
	{
		mTexture.SetScale(LifeParam::SCALE);
		mTexture.SetDrawOrder(LifeParam::LIFE_BOARD_DRAWORDER);

		mNumText.SetSize(LifeParam::NUM_SIZE);
		mNumText.SetText(std::to_string(mLifeNum));
		mNumText.SetDrawOrder(LifeParam::LIFE_BOARD_DRAWORDER + 1);
	}

	void Life::CustomizeUpdate()
	{
		AdjustPos();
		mNumText.SetText(std::to_string(mLifeNum));
	}

	void Life::Damage()
	{
		if (mLifeNum > 0)
			mLifeNum--;
	}

	void Life::Heal()
	{
		mLifeNum++;
	}

	bool Life::IsLifeZero()
	{
		return mLifeNum == 0;
	}

	void Life::AdjustPos()
	{
		
		float rot = AdjustRot(GameLib::Viewport::GetRotation());
		GameLib::Vector2 pos = GameLib::Viewport::GetPos();

		mTexture.SetPosition(GameLib::Vector2::Rotation(pos + mAdjust, rot));
		mNumText.SetPosition(GameLib::Vector2::Rotation(pos + mAdjust + LifeParam::ADJUST_NUM_POS, rot));

		mTexture.SetRotation(rot);

		
	}
}