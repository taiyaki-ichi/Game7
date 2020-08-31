#pragma once
#include"GameLib/include/Draw/DrawRect.hpp"

namespace Stage
{
	class Button
	{
		GameLib::DrawRect mInsideRect;
		GameLib::DrawRect mOutsiedeRect;

	public:
		Button(const GameLib::Vector2&, int drawOrder = 0);

		void SetWidthAndHeightAndFlameWidth(float, float, float);

		void ChangeDark();
		void ChangeWhite();
	};
}