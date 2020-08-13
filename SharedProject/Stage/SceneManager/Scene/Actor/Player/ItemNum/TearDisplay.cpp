#include"TearDisplay.hpp"
#include"ItemNumParam.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

namespace Stage
{
	TearDisplay::TearDisplay(const GameLib::Vector2& pos)
		:mTexture1{ "../Assets/Item/Gem/tear_frame.png" }
		, mTexture2{ "../Assets/Item/Gem/tear_frame.png" }
		, mTexture3{ "../Assets/Item/Gem/tear_frame.png" }
		, mAdjustPos{pos}
	{
		mTexture2.SetScale(ItemNumParam::TEAR_SCALE);
		mTexture1.SetScale(ItemNumParam::TEAR_SCALE);
		mTexture3.SetScale(ItemNumParam::TEAR_SCALE);

		mTexture1.SetDrawOrder(ItemNumParam::DRAWORDER);
		mTexture2.SetDrawOrder(ItemNumParam::DRAWORDER);
		mTexture3.SetDrawOrder(ItemNumParam::DRAWORDER);

		AdjustPos();
	}

	void TearDisplay::Get(int num)
	{
		if (num == 1)
			mTexture1.SetTexture("../Assets/Item/Gem/tear.png");
		else if (num == 2)
			mTexture2.SetTexture("../Assets/Item/Gem/tear.png");
		else if (num == 3)
			mTexture3.SetTexture("../Assets/Item/Gem/tear.png");
	}

	void TearDisplay::AdjustPos()
	{
		auto center = GameLib::Viewport::GetPos();
		mTexture2.SetPosition(center + mAdjustPos);
		mTexture1.SetPosition(center + mAdjustPos + GameLib::Vector2{ -ItemNumParam::TEAR_DISPLAY_LENGTH_X,0.f });
		mTexture3.SetPosition(center + mAdjustPos + GameLib::Vector2{ ItemNumParam::TEAR_DISPLAY_LENGTH_X,0.f });

	}
}