#pragma once

namespace Game
{
	namespace StageStateFlag
	{
		constexpr unsigned char OPEN_FLAG = 0b1;
		constexpr unsigned char CLEAR_FLAG = 0b10;
		//TearGem獲得したかどうか
		constexpr unsigned char TEARGEM1_FLAG = 0b100;
		constexpr unsigned char TEARGEM2_FLAG = 0b1000;
		constexpr unsigned char TEARGEM3_FLAG = 0b10000;

	}
}