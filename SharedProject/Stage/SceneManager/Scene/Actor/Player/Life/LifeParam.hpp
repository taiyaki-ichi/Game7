#pragma once
#include"GameLib/include/Draw/DrawFontText.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"Stage/WindowSize.hpp"

namespace Stage
{
	namespace LifeParam
	{
		const GameLib::Vector2 ADJUST_POSITION = { -WindowSize::WIDTH / 2.f + 50.f,WindowSize::HEIGHT / 2.f - 50 };
		constexpr float SCALE = 0.1f;

		constexpr GameLib::Font::Size NUM_SIZE = GameLib::Font::Size::Size_36;

		constexpr int LIFE_BOARD_DRAWORDER = 50;
		const GameLib::Vector2 ADJUST_NUM_POS = { 0.f,-3.f };
	}
}