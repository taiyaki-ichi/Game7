#pragma once
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"

namespace Game
{
	namespace IsSaveParam
	{
		const GameLib::Vector2 BUTTON_A_POSITION{ -100.f,-30.f };
		const GameLib::Vector2 BUTTON_D_POSITION{ 100.f,-30.f };

		const GameLib::Vector2 ISSAVE_TEXT_POSITION{ 0.f,70.f };
		constexpr auto ISSAVE_FONT_SIZE = GameLib::Font::Size::Size_36;

		constexpr float BUTTON_WIDTH = 100.f;
		constexpr float BUTTON_HEIGHT = 80.f;
		constexpr float BUTTOB_FLAME_WIDTH = 10.f;

		constexpr auto HAI_IIE_FONT_SIZE = GameLib::Font::Size::Size_24;

		constexpr float KAKKO_WIDTH = BUTTON_WIDTH + 15.f;
		constexpr float KAKKO_HEIGHT = BUTTON_HEIGHT + 15.f;
		constexpr float KAKKO_MOVE_LENGTH = 3.f;
		constexpr float KAKKO_TEXTURE_SCALE = 0.03f;

		const GameLib::Vector2 BUTTON_TAG_ADJUST = { 0.f,BUTTON_HEIGHT / 2.f + 15.f };
		constexpr auto BUTTON_TAG_FONT_SIZE = GameLib::Font::Size::Size_24;
	}
}