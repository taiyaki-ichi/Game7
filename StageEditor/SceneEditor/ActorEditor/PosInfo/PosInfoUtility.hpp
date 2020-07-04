#pragma once
#include"PosInfo.hpp"

namespace StageEditor
{
	//a,bの距離
	float GetLength(PosInfo* a, PosInfo* b);

	//直線abcが時計回りかどうか
	bool IsClockwise(PosInfo* a, PosInfo* b, PosInfo* c);
}