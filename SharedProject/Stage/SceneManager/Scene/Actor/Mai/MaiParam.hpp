#pragma once

namespace Stage
{
	namespace MaiParam
	{
		constexpr float WIDTH = 600.f;
		constexpr float HEIGHT = 600.f;
		constexpr float SCALE = 0.1f;

		constexpr float STRENGTH_RATE = 1.f / 2.f;
		constexpr float WEAKNESS_RATE = 1.f / 2.f;

		constexpr int STAY_TIME = 100;
		constexpr int LAUNCH_TIME = 40;

		constexpr float ADJUST_COLLIDER_DOWN = 5.f;

		constexpr float FALL_DEATH_SPEED = 2.5f;
		constexpr float FALL_DEATH_DELTAROT = -0.1f;

		constexpr float ACTIVE_LINE = 300.f;
	}
}