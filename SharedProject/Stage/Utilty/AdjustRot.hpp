#pragma once
#include"GameLib/include/Math/Numbers.hpp"

namespace Stage
{
	inline float AdjustRot(float rot)
	{
		while (rot < 0.f)
			rot += GameLib::PI * 2.f;
		while (rot >= GameLib::PI * 2.f)
			rot -= GameLib::PI * 2.f;

		return rot;
	}
}
