#pragma once

namespace Stage
{
	namespace SceneManagerFlag
	{
		constexpr unsigned char CLEAR_FLAG = 0b1;
		constexpr unsigned char MISS_FLAG = 0b10;
		constexpr unsigned char RETURN_STAGESELECT_FLAG = 0b100;

		constexpr unsigned char PLAYER_DEATH_MOTION_FLAG = 0b1000;
		constexpr unsigned char PLAYER_CLEAR_MOTION_FLAG = 0b10000;
	}
}