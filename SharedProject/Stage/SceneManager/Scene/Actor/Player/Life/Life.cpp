#pragma once
#include"Life.hpp"
#include"LifeParam.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

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
		auto pos = GameLib::Viewport::GetPos();
		mTexture.SetPosition(pos + mAdjust);
		mNumText.SetPosition(pos + mAdjust + LifeParam::ADJUST_NUM_POS);
	}
}