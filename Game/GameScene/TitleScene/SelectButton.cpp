#include"SelectButton.hpp"
#include"ButtonParam.hpp"
namespace Game
{
	Button::Button(const GameLib::Vector2& pos,int drawOrder)
		:mInsideRect{ drawOrder }
		, mOutsiedeRect{ drawOrder-1 }
		, mText{ "../Assets/Font/mplus-1c-black.ttf" }
		, mGemDisplay{pos+ButtonParam::GEM_NUM_ADJUST,0}
		, mLifeDisplay{pos+ButtonParam::LIFE_NUM_ADJUST,0}
	{
		mInsideRect.SetColor({ 255,255,255,255 });
		mInsideRect.SetIsFill(true);

		mOutsiedeRect.SetColor({ 0,0,0,255 });
		mOutsiedeRect.SetIsFill(true);

		mText.SetDrawOrder(drawOrder + 1);
		mText.SetSize(GameLib::Font::Size::Size_36);

		mOutsiedeRect.SetPosition(pos);
		mInsideRect.SetPosition(pos);
		mText.SetPosition(pos + ButtonParam::STRING_ADJUST);
	}

	void Button::SetWidthAndHeightAndFlameWidth(float w, float h, float flameW)
	{
		mOutsiedeRect.SetWidthAndHeight(w, h);
		mInsideRect.SetWidthAndHeight(w - flameW, h - flameW);
	}

	void Button::SetText(std::string&& str)
	{
		mText.SetText(std::move(str));
	}

	void Button::SetLifeAndGemNum(int life, int gem)
	{
		mLifeDisplay.SetNum(life);
		mGemDisplay.SetNum(gem);
	}

	void Button::ChangeDark()
	{
		mInsideRect.SetColor({ 150,150,150, 255 });
	}

	void Button::ChangeWhite()
	{
		mInsideRect.SetColor({ 255,255,255,255 });
	}
}