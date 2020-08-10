#pragma once

namespace Stage
{
	namespace PlayerFlag
	{
		constexpr char ON_GROUND_FLAG = 0b1;
		constexpr char DEATH_FLAG = 0b10;
		constexpr char DEATH_MOTION_FINISH_FLAG = 0b100;
		constexpr char STAGE_CLEAR_FLAG = 0b1000;
	}
}