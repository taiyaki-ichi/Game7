#include"StarDisplay.hpp"
#include"StardisplayParam.hpp"

namespace Game
{
	StarDisplay::StarDisplay(int drawOrder)
		:mTexture1{"../Assets/TitleScene/star.png"}
		, mTexture2{ "../Assets/TitleScene/star.png" }
		, mTexture3{ "../Assets/TitleScene/star.png" }
	{
		mTexture1.SetScale(StarDisplayParam::TEXTURE_SCALE);
		mTexture2.SetScale(StarDisplayParam::TEXTURE_SCALE);
		mTexture3.SetScale(StarDisplayParam::TEXTURE_SCALE);

		mTexture1.SetIsAutoDrawing(false);
		mTexture2.SetIsAutoDrawing(false);
		mTexture3.SetIsAutoDrawing(false);

		mTexture1.SetDrawOrder(drawOrder);
		mTexture2.SetDrawOrder(drawOrder);
		mTexture3.SetDrawOrder(drawOrder);
	}

	void StarDisplay::SetPosition(const GameLib::Vector2& pos)
	{
		mTexture1.SetPosition(pos + GameLib::Vector2{ -StarDisplayParam::TEXTURE_DISTANCE,0.f });
		mTexture2.SetPosition(pos);
		mTexture3.SetPosition(pos + GameLib::Vector2{ StarDisplayParam::TEXTURE_DISTANCE,0.f });
	}

	void StarDisplay::SetStarNum(int num)
	{
		if (num >= 1)
			mTexture1.SetIsAutoDrawing(true);
		if (num >= 2)
			mTexture2.SetIsAutoDrawing(true);
		if (num >= 3)
			mTexture3.SetIsAutoDrawing(true);
	}
}