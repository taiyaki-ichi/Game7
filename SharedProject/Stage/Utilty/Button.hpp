#pragma once
#include"GameLib/include/Draw/DrawRect.hpp"

namespace Stage
{
	class Button
	{
		GameLib::DrawRect mInsideRect;
		GameLib::DrawRect mOutsiedeRect;

	public:
		Button(int drawOrder = 0);

		void SetWidthAndHeightAndFlameWidth(float, float, float);
		void SetPosition(const GameLib::Vector2&);
		void SetRotation(float);

		void ChangeDark();
		void ChangeWhite();

		const GameLib::Vector2& GetPosition() const;
	};
}