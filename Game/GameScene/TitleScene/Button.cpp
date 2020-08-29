#include"Button.hpp"

namespace Game
{
	Button::Button(int drawOrder)
		:mInsideRect{ drawOrder }
		, mOutsiedeRect{ drawOrder-1 }
	{
		mInsideRect.SetColor({ 255,255,255,255 });
		mInsideRect.SetIsFill(true);

		mOutsiedeRect.SetColor({ 0,0,0,255 });
		mOutsiedeRect.SetIsFill(true);
	}

	void Button::SetWidthAndHeightAndFlameWidth(float w, float h, float flameW)
	{
		mOutsiedeRect.SetWidthAndHeight(w, h);
		mInsideRect.SetWidthAndHeight(w - flameW, h - flameW);
	}

	void Button::SetPosition(const GameLib::Vector2& pos)
	{
		mOutsiedeRect.SetPosition(pos);
		mInsideRect.SetPosition(pos);
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