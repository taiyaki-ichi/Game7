#pragma once
#include"Life.hpp"
#include"LifeParam.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

namespace Stage
{
	Life::Life(GameLib::Actor* actor)
		:GameLib::Actor{actor,200}
		, mTexture{"../Assets/Player/Life/board.png"}
		, mNumText{ "../Assets/Font/mplus-1c-black.ttf" }
		, mLifeNum{ 3 }
	{
		mTexture.SetScale(LifeParam::SCALE);
		mTexture.SetDrawOrder(LifeParam::LIFE_BOARD_DRAWORDER);

		mNumText.SetSize(LifeParam::NUM_SIZE);
		mNumText.SetText(std::to_string(mLifeNum));
		mNumText.SetDrawOrder(LifeParam::LIFE_BOARD_DRAWORDER + 1);
	}

	void Life::CustomizeUpdate()
	{
		auto pos = GameLib::Viewport::GetPos();
		mTexture.SetPosition(pos + LifeParam::ADJUST_POSITION);
		mNumText.SetPosition(pos + LifeParam::ADJUST_POSITION + LifeParam::ADJUST_NUM_POS);

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
}