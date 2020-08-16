#pragma once
#include"GameLib/include/Math/Vector2.hpp"
#include<utility>
#include"HexChipParam.hpp"

namespace Game
{
	inline GameLib::Vector2 ToVector2(int x,int y)
	{
		return static_cast<float>(x) * HexChipParam::UNIT_X + static_cast<float>(y) * HexChipParam::UNIT_Y;
	}
}