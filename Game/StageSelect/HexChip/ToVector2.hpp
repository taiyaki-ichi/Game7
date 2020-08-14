#pragma once
#include"GameLib/include/Math/Vector2.hpp"
#include<utility>
#include"HexChipParam.hpp"

namespace Game
{
	inline GameLib::Vector2 ToVector2(const std::pair<int, int>& pairVec)
	{
		return static_cast<float>(pairVec.first) * HexChipParam::UNIT_X + static_cast<float>(pairVec.second) * HexChipParam::UNIT_Y;
	}
}