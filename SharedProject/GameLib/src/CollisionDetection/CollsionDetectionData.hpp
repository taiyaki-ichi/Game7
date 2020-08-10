#pragma once

namespace GameLib
{
	constexpr int TREE_LEVEL = 6;
	constexpr int POWER_OF_FOUR[11] = { 1,4,16,64,256,1024,4096,16384,65536,262144,1048576 };
	constexpr int MAX_SPACECELL_NUM = (POWER_OF_FOUR[TREE_LEVEL + 1] - 1) / 3;
}