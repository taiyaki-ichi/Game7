#pragma once
#include"GameLib/include/Math/Vector2.hpp"

namespace Stage
{
	namespace PauseParam
	{
		constexpr float WINDOW_WIDTH = 400.f;
		constexpr float WINDOW_HEIGHT = 180.f;
		constexpr float WINDOW_FLAME_WIDTH = 10.f;

		const GameLib::Vector2 RESUME_BUTTON_ADJUST = { -100.f,-30.f };
		const GameLib::Vector2 RETURN_TITLE_BUTTON_ADJUST = { 100.f,-30.f };

		constexpr float BUTTON_WIDTH = 160.f;
		constexpr float BUTTON_HEIGHT = 50.f;
		constexpr float BUTTON_FLAMEWIDTH = 10.f;

		constexpr float KAKKO_MOVE_LENGTH = 2.f;
		constexpr float KAKKO_TEXTURE_SCALE = 0.03f;
		constexpr float KAKKO_WIDTH = BUTTON_WIDTH + 5.f;
		constexpr float KAKKO_HEIGHT = BUTTON_HEIGHT + 5.f;

		const GameLib::Vector2 PAUSE_TEXT_ADJUST{ 0.f,40.f };

		//A,DÇÃà íuÇÃÇªÇÍÇºÇÍÇÃÉ{É^ÉìÇ©ÇÁÇÃï‚ê≥
		const GameLib::Vector2 BUTTON_KEY_TEXT_ADJUST{ 0.f,40.f };

	}
}