#pragma once
#include"GameLib/include/Math/Vector2.hpp"

namespace Stage
{
	namespace PauseParam
	{
		constexpr float WINDOW_WIDTH = 200.f;
		constexpr float WINDOW_HEIGHT = 170.f;
		constexpr float WINDOW_FLAME_WIDTH = 10.f;

		const GameLib::Vector2 RESUME_BUTTON_ADJUST = { 0.f,35.f };
		const GameLib::Vector2 RETURN_TITLE_BUTTON_ADJUST = { 0.f,-35.f };

		constexpr float BUTTON_WIDTH = 160.f;
		constexpr float BUTTON_HEIGHT = 50.f;
	}
}