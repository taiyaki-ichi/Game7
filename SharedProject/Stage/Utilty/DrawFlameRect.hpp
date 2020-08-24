#pragma once
#include"GameLib/include/Draw/CustomizeDrawBase.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace Stage
{
	class DrawFlameRect : public GameLib::CustomizeDrawBase
	{
		GameLib::DrawRect mRect;
		GameLib::DrawRect mFlame;

		GameLib::DrawRect mBlank;

		float mFlameWidth;

	public:
		DrawFlameRect(int drawOrder = 0);

		void Draw() override;

		void SetFlameWidth(float);
		void SetWidthAndHeight(float, float);
		void SetRectColor(GameLib::Color&&);
		void SetFlameColor(GameLib::Color&&);

		void SetPosition(const GameLib::Vector2&);
		const GameLib::Vector2& GetPosition() const;
	};
}