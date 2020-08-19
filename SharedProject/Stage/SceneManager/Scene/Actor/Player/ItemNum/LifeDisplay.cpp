#include"LifeDisplay.hpp"
#include"ItemNumParam.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

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
		auto center = GameLib::Viewport::GetPos();
		float rot = GameLib::Viewport::GetRotation();
		mTexture.SetPosition(GameLib::Vector2::Rotation(center + mAdjustPos + GameLib::Vector2{ ItemNumParam::LIFE_ICON_ADJUST_X,0.f }, -rot));
		mNum.SetPosition(GameLib::Vector2::Rotation(center + mAdjustPos + GameLib::Vector2{ ItemNumParam::LIFE_NUM_ADJUST_X,0.f }, -rot));
		mKakeru.SetPosition(GameLib::Vector2::Rotation(center + mAdjustPos, -rot));

		mTexture.SetRotation(rot);

	}
}