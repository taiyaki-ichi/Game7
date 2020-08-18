#pragma once
#include"GameLib/include/Math/Vector2.hpp"

namespace Stage
{
	namespace CarrotParam
	{
		constexpr float ACTIVE_RANGE = 350.f;

		constexpr float MAX_SPEED = 6.f;
		constexpr float RUN_POWER = 0.2f;

		constexpr float SCALE = 0.12f;

		constexpr float WIDTH = 450.f;
		constexpr float HEIGHT = 350.f;

		constexpr float WEAKNESS_RATE = 1.f / 3.f;
		constexpr float STREANGTH_RATE = 2.f / 3.f;

		constexpr int FLATDEATH_TIME = 30;
		constexpr float FLATDEATH_ADJUST_DOWN = 5.f;

	}
}