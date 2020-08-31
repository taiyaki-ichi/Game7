#include"StringDisplay.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

namespace Game
{

	StringDisplay::StringDisplay(const GameLib::Vector2& adjust, GameLib::Font::Size&& size)
		: mText{ "../Assets/Font/mplus-1c-black.ttf" }
		, mAdjustVec{ adjust }
	{
		mText.SetText("");
		mText.SetSize(std::move(size));
		mText.SetPosition(GameLib::Viewport::GetPos() + mAdjustVec);
		mText.SetDrawOrder(50);
	}

	void StringDisplay::SetText(const std::string& str)
	{
		mText.SetText(str);
	}

	void StringDisplay::AdjustPos()
	{
		mText.SetPosition(GameLib::Viewport::GetPos() + mAdjustVec);
	}

}