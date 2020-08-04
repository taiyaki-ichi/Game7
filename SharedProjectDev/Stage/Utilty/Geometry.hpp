#pragma once
#include<cmath>
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Math/Numbers.hpp"

namespace Stage
{
	//•½s‚È’·•ûŒ`“¯m‚Ì‚ß‚è‚İ•â³
	//round‚ÍˆÈ‰º‚Ì–ß‚è’lVector2‚Ìx‚Ü‚½‚Íy‚ÍØ‚èÌ‚Ä‚Ä–³‹‚·‚é
	GameLib::Vector2 GetParallelRectAdjustVec(const GameLib::Collider& character, const GameLib::Collider& ground, float roundXY = 0.f);
	GameLib::Vector2 GetParallelRectAdjustVec(const GameLib::Collider& character, const GameLib::Collider& ground, float roundX, float roundY);
}