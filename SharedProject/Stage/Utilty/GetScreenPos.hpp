#pragma once
#include"GameLib/include/Math/Vector2.hpp"

namespace Stage
{
	///画面の表示位置を考慮して座標変換
	GameLib::Vector2 GetScreenPos(const GameLib::Vector2&);
}