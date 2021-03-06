#pragma once
#include<cmath>
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Math/Numbers.hpp"

namespace Stage
{
	//平行な長方形同士のめり込み補正
	//roundは以下の戻り値Vector2のxまたはyは切り捨てて無視する
	GameLib::Vector2 GetParallelRectAdjustVec(const GameLib::Collider& character, const GameLib::Collider& ground, float roundXY = 0.f);
	GameLib::Vector2 GetParallelRectAdjustVec(const GameLib::Collider& character, const GameLib::Collider& ground, float roundX, float roundY);
}