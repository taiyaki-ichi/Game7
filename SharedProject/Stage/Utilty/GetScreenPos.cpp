#include"GetScreenPos.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"Stage/WindowSize.hpp"

namespace Stage
{
	GameLib::Vector2 GetScreenPos(const GameLib::Vector2& pos)
	{
		using namespace GameLib;
		auto result = pos;//Vector2::Rotation(pos, -Viewport::GetRotation());
		result = GameLib::Vector2::Rotation(result, Viewport::GetRotation());
		result = Affine(result , Viewport::GetPos(), -Viewport::GetRotation(), Viewport::GetScale());

		return result;
	}
}