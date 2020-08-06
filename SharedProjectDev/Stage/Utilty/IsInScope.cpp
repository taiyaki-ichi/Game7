#include"IsInScope.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"

namespace Stage
{
	bool IsInScope(const GameLib::Vector2& pos, float left, float right, float bottom, float top)
	{
		auto p = GameLib::Affine(pos, GameLib::Viewport::GetPos(), -GameLib::Viewport::GetRotation(), GameLib::Viewport::GetScale());

		if (p.x < left || right < p.x || p.y < bottom || top < p.y)
			return false;
		else
			return true;
	}

	bool IsInScope(const GameLib::Vector2& pos, float w, float h)
	{
		return IsInScope(pos, -w / 2.f, w / 2.f, -h / 2.f, h / 2.f);
	}

}