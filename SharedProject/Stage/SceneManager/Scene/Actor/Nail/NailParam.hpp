#pragma once

namespace Stage
{
	namespace NailParam
	{
		constexpr float WEAKNESS_WIDTH = 580.f;
		constexpr float WEAKNES_HEIGHT = 280.f;

		constexpr float STRENGTH_WIDTH = 70.f;
		constexpr float STRENGTH_HEIGHT = 80.f;

		constexpr float SCALE = 0.06f;

		constexpr float STRENGTH_ADJUST_LEFT = ((STRENGTH_WIDTH + WEAKNESS_WIDTH) / 2.f - STRENGTH_WIDTH / 2.f) * SCALE;
		constexpr float WEAKNESS_ADJUST_RIGHT = ((STRENGTH_WIDTH + WEAKNESS_WIDTH) / 2.f - WEAKNESS_WIDTH / 2.f) * SCALE;

		constexpr float SPEED = 6.f;

		constexpr float DEATH_LINE = 300.f;

		constexpr float FALL_SPEED = 3.f;
		constexpr float FALL_DELTAROT = 0.1f;

	}
}