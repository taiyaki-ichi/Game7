#include"TearGemDisplay.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"TearGemDisplayParam.hpp"

namespace Game
{
	TearGemDisplay::TearGemDisplay(const GameLib::Vector2& pos)
		:mAdjustPos{ pos }
		, mTexture1{ "../Assets/Item/Gem/tear_frame.png" }
		, mTexture2{ "../Assets/Item/Gem/tear_frame.png" }
		, mTexture3{ "../Assets/Item/Gem/tear_frame.png" }
	{
		mTexture1.SetScale(TearGemDisplayParam::SCALE);
		mTexture2.SetScale(TearGemDisplayParam::SCALE);
		mTexture3.SetScale(TearGemDisplayParam::SCALE);

		mTexture1.SetDrawOrder(50);
		mTexture2.SetDrawOrder(50);
		mTexture3.SetDrawOrder(50);
	}

	void TearGemDisplay::NotDrawing()
	{
		mTexture1.SetIsAutoDrawing(false);
		mTexture2.SetIsAutoDrawing(false);
		mTexture3.SetIsAutoDrawing(false);
	}

	void TearGemDisplay::SetFrame()
	{
		mTexture1.SetIsAutoDrawing(true);
		mTexture2.SetIsAutoDrawing(true);
		mTexture3.SetIsAutoDrawing(true);

		mTexture1.SetTexture("../Assets/Item/Gem/tear_frame.png");
		mTexture2.SetTexture("../Assets/Item/Gem/tear_frame.png");
		mTexture3.SetTexture("../Assets/Item/Gem/tear_frame.png");
	}

	void TearGemDisplay::SetTearGem(int num)
	{
		if (num == 1)
			mTexture1.SetTexture("../Assets/Item/Gem/tear.png");
		else if (num == 2)
			mTexture2.SetTexture("../Assets/Item/Gem/tear.png");
		else if (num == 3)
			mTexture3.SetTexture("../Assets/Item/Gem/tear.png");
	}

	void TearGemDisplay::AdjustPos()
	{
		auto c = GameLib::Viewport::GetPos();
		mTexture1.SetPosition(c + mAdjustPos + GameLib::Vector2{ TearGemDisplayParam::DISTANCE,0.f });
		mTexture2.SetPosition(c + mAdjustPos);
		mTexture3.SetPosition(c + mAdjustPos + GameLib::Vector2{ -TearGemDisplayParam::DISTANCE,0.f });
	}
}