#include"Button.hpp"

namespace Stage
{
	Button::Button(const GameLib::Vector2& pos, int drawOrder)
		:mInsideRect{ drawOrder }
		, mOutsiedeRect{ drawOrder - 1 }
	{
		mInsideRect.SetColor({ 255,255,255,255 });
		mInsideRect.SetIsFill(true);

		mOutsiedeRect.SetColor({ 0,0,0,255 });
		mOutsiedeRect.SetIsFill(true);

		mInsideRect.SetPosition(pos);
		mOutsiedeRect.SetPosition(pos);

	}

	void Button::SetWidthAndHeightAndFlameWidth(float w, float h, float flameW)
	{
		mOutsiedeRect.SetWidthAndHeight(w, h);
		mInsideRect.SetWidthAndHeight(w - flameW, h - flameW);
	}

	void Button::ChangeDark()
	{
		mInsideRect.SetColor({ 150,150,150, 255 });
	}

	void Button::ChangeWhite()
	{
		mInsideRect.SetColor({ 255,255,255,255 });
	}

	const GameLib::Vector2& Button::GetPosition() const
	{
		return mOutsiedeRect.GetPosition();
	}

}