#pragma once
#include"PosInfo.hpp"

namespace StageEditor
{
	//a,bの距離
	float GetLength(PosInfo* a, PosInfo* b);

	//直線abcが時計回りかどうか
	bool IsClockwise(PosInfo* a, PosInfo* b, PosInfo* c);

	//a,bの真ん中
	GameLib::Vector2 GetCenter(PosInfo* a, PosInfo* b);

	//a,bのx方向の距離
	float GetWidth(PosInfo* a, PosInfo* b);
	float GetHeight(PosInfo* a, PosInfo* b);
}