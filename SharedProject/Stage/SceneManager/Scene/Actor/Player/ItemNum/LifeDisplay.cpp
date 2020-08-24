#include"LifeDisplay.hpp"
#include"ItemNumParam.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Stage/Utilty/AdjustRot.hpp"

namespace Stage
{
	LifeDisplay::LifeDisplay(const GameLib::Vector2& pos,int num)
		:mTexture{ "../Assets/Player/icon.png" }
		, mNum{ "../Assets/Font/mplus-1c-black.ttf" }
		, mKakeru{ "../Assets/Font/mplus-1c-black.ttf" }
		, mAdjustPos{pos}
	{
		mTexture.SetScale(ItemNumParam::LIFE_ICON_SCALE);
		mTexture.SetDrawOrder(ItemNumParam::DRAWORDER);

		mNum.SetText(std::to_string(num));
		mNum.SetSize(ItemNumParam::FONT_SIZE);
		mNum.SetDrawOrder(ItemNumParam::DRAWORDER);

		mKakeru.SetText("Å~");
		mKakeru.SetSize(ItemNumParam::FONT_SIZE);
		mKakeru.SetDrawOrder(ItemNumParam::DRAWORDER);

		AdjustPos();
	}

	void LifeDisplay::SetNum(int num)
	{
		mNum.SetText(std::to_string(num));
	}

	void LifeDisplay::AdjustPos()
	{
		/*
		auto center = GameLib::Viewport::GetPos();
		float rot = GameLib::Viewport::GetRotation();
		mTexture.SetPosition(GameLib::Vector2::Rotation(center + mAdjustPos + GameLib::Vector2{ ItemNumParam::LIFE_ICON_ADJUST_X,0.f }, -rot));
		mNum.SetPosition(GameLib::Vector2::Rotation(center + mAdjustPos + GameLib::Vector2{ ItemNumParam::LIFE_NUM_ADJUST_X,0.f }, -rot));
		mKakeru.SetPosition(GameLib::Vector2::Rotation(center + mAdjustPos, -rot));
		*/

		//mTexture.SetRotation(rot);

		float viewRot = AdjustRot(GameLib::Viewport::GetRotation());
		int i = 0;
		for (; i < 4; i++)
		{
			if (std::abs(GameLib::PI / 2.f * static_cast<float>(i) - viewRot) < 0.01f)
			{
				GameLib::Vector2 pos = GameLib::Viewport::GetPos();
				float rot = GameLib::Viewport::GetRotation();

				float dir = 1.f;
				if (i == 1 || i == 3)
					dir = -1.f;

				mTexture.SetIsAutoDrawing(true);
				mNum.SetIsAutoDrawing(true);
				mKakeru.SetIsAutoDrawing(true);

				mTexture.SetPosition(GameLib::Vector2::Rotation(pos + mAdjustPos + GameLib::Vector2{ ItemNumParam::LIFE_ICON_ADJUST_X,0.f }, -rot * dir));
				mNum.SetPosition(GameLib::Vector2::Rotation(pos + mAdjustPos + GameLib::Vector2{ ItemNumParam::LIFE_NUM_ADJUST_X,0.f }, -rot * dir));
				mKakeru.SetPosition(GameLib::Vector2::Rotation(pos + mAdjustPos, -rot * dir));

				mTexture.SetRotation(rot);

				break;
			}
		}

		if (i == 4)
		{
			mTexture.SetIsAutoDrawing(false);
			mNum.SetIsAutoDrawing(false);
			mKakeru.SetIsAutoDrawing(false);
		}

	}
}