#pragma once
#include"GameLib/include/Math/Vector2.hpp"

namespace Stage
{
	//画面の中心からこの範囲内にposがあるかどうか
	bool IsInScope(const GameLib::Vector2& pos, float left, float right, float bottom, float top);
	//画面の位置を中心として、横wタテhの長方形の内側かどうか
	bool IsInScope(const GameLib::Vector2& pos, float w, float h);
}