#include"GemDisplay.hpp"
#include"ItemNumParam.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

namespace Stage
{
	GemDisplay::GemDisplay(const GameLib::Vector2& pos,int num)
		:mTexture{"../Assets/Item/Diamond/002.png"}
		, mNum{"../Assets/Font/mplus-1c-black.ttf"}
		, mKakeru{ "../Assets/Font/mplus-1c-black.ttf" }
		, mAdjustPos{pos}
	{
		mTexture.SetScale(ItemNumParam::GEM_ICON_SCALE);
		mTexture.SetDrawOrder(ItemNumParam::DRAWORDER);

		mNum.SetText(std::to_string(num));
		mNum.SetSize(ItemNumParam::FONT_SIZE);
		mNum.SetDrawOrder(ItemNumParam::DRAWORDER);

		mKakeru.SetText("Å~");
		mKakeru.SetSize(ItemNumParam::FONT_SIZE);
		mKakeru.SetDrawOrder(ItemNumParam::DRAWORDER);

		AdjustPos();
	}

	void GemDisplay::SetNum(int num)
	{
		mNum.SetText(std::to_string(num));
	}

	void GemDisplay::AdjustPos()
	{
		auto center = GameLib::Viewport::GetPos();
		mTexture.SetPosition(center + mAdjustPos + GameLib::Vector2{ ItemNumParam::GEM_ICON_ADJUST_X,0.f });
		mNum.SetPosition(center + mAdjustPos + GameLib::Vector2{ ItemNumParam::GEM_NUM_ADJUST_X,0.f });
		mKakeru.SetPosition(center + mAdjustPos);
	}
}