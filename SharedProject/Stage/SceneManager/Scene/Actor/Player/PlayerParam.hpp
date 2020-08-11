#pragma once


namespace Stage
{

	namespace PlayerParam
	{
		//Active
		constexpr float MAX_HORIZON_SPEED = 7.f;
		constexpr float MAX_VERTICAL_SPEED = 21.f;
		constexpr float JUMP_POWER_MAX = 17.f;
		constexpr float JUMP_POWER_MIN = 14.f;
		constexpr float RUN_POWER = 0.3f;
		constexpr float JUMPING_GRAVITY_RATE = 0.85f;
		constexpr float COLLIDER_ADJUST_DOWN_SIZE = 12.f;
		constexpr float FALL_DEATH_LINE = 100.f;

		//Death
		constexpr static int DEATH_CNT = 180;

		//èâä˙íl
		constexpr float WIDTH = 250.f;
		constexpr float HEIGHT = 500.f;
		constexpr float SCALE = 0.1f;
	}
}