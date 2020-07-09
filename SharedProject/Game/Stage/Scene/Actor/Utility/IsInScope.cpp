#include"IsInScope.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

namespace Game::Stage
{



	bool IsInScope(const GameLib::Vector2& pos, float left, float right, float bottom, float top)
	{
		auto center = GameLib::Viewport::GetPos();
		auto p = pos - center;

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