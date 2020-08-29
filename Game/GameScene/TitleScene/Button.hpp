#pragma once
#include"GameLib/include/Draw/DrawRect.hpp"

namespace Game
{
	class Button
	{
		GameLib::DrawRect mInsideRect;
		GameLib::DrawRect mOutsiedeRect;

	public:
		Button(int drawOrder = 0);

		void SetWidthAndHeightAndFlameWidth(float, float, float);
		void SetPosition(const GameLib::Vector2&);

		void ChangeDark();
		void ChangeWhite();
	};
}