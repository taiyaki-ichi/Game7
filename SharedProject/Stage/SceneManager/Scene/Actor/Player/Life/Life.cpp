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
		
		float viewRot = AdjustRot(GameLib::Viewport::GetRotation());
		int i = 0;
		for (; i < 4; i++)
		{
			if (std::abs(GameLib::PI / 2.f * static_cast<float>(i) - viewRot) < 0.01f)
			{
				GameLib::Vector2 pos = GameLib::Viewport::GetPos();
				float dir = 1.f;
				if (i == 1 || i == 3)
					dir = -1.f;

				mTexture.SetIsAutoDrawing(true);
				mNumText.SetIsAutoDrawing(true);

				mTexture.SetPosition(GameLib::Vector2::Rotation(pos + mAdjust, -GameLib::Viewport::GetRotation() * dir));
				mNumText.SetPosition(GameLib::Vector2::Rotation(pos + mAdjust + LifeParam::ADJUST_NUM_POS, -GameLib::Viewport::GetRotation() * dir));

				mTexture.SetRotation(GameLib::Viewport::GetRotation());

				break;
			}
		}

		if (i == 4)
		{
			mTexture.SetIsAutoDrawing(false);
			mNumText.SetIsAutoDrawing(false);
		}
		
	}
}