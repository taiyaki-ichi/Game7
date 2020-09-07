#pragma once
#include"GameLib/include/Draw/DrawFontText.hpp"

namespace Stage
{
	namespace ItemNumParam
	{

		const GameLib::Vector2 GEM_DISPLAY_ADJUST = { 0.f,-35.f };
		const GameLib::Vector2 LIFE_DISPLAY_ADJUST = { 0.f,0.f };
		const GameLib::Vector2 TEAR_DISPLAY_ADJUST = { 0.f,-75.f };

		constexpr float TEAR_DISPLAY_LENGTH_X = 40.f;

		constexpr float TEAR_SCALE = 0.07f;

		constexpr GameLib::Font::Size FONT_SIZE = GameLib::Font::Size::Size_36;

		constexpr float GEM_ICON_SCALE = 0.05f;
		constexpr float GEM_ICON_ADJUST_X = -30.f;
		constexpr float GEM_NUM_ADJUST_X = 30.f;

		constexpr float LIFE_ICON_SCALE = 0.07f;
		constexpr float LIFE_ICON_ADJUST_X = -30.f;
		constexpr float LIFE_NUM_ADJUST_X = 30.f;

		constexpr int GEM_MAX_NUM = 50;
		constexpr int MAX_LIFE_NUM = 99;

		constexpr int DRAWORDER = 50;
	}
}