#pragma once
#include"Stage/Utilty/Dir4Vec.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Stage/Utilty/Geometry.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"Stage/Gravity/Gravity.hpp"

namespace Stage
{
	//ƒgƒ‰ƒ“ƒ|ƒŠƒ“‚É“–‚½‚Á‚½Žž‚Ì‘¬“x‚Ì•â³
	constexpr auto hitTrampoline = [](const GameLib::Vector2& myV,const GameLib::Collider& myC, Dir4&& dir, const GameLib::Collider& c,float trampolinePower)
		->GameLib::Vector2
	{
		GameLib::Vector2 result{ myV };

		auto adjust = GetParallelRectAdjustVec(myC, c);
		auto adjustDir4Vec = GetDir4Vec(adjust);
		auto adjustDir4VecDir4 = adjustDir4Vec.mDir4;

		int dirNum = static_cast<int>(dir) - static_cast<int>(Gravity::GetDir4());
		if (dirNum > 3)
			dirNum -= 4;
		if (dirNum < 0)
			dirNum += 4;

		auto adjustDir = static_cast<Dir4>(dirNum);
		if (adjustDir4VecDir4 == adjustDir) {
			result = GetDirSizeSetVector2(result, adjustDir, 0.f);
			result += GetVector2(adjustDir, trampolinePower);
		}

		return result;
	};

}