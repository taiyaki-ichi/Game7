#pragma once
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Math/Numbers.hpp"

namespace Game
{
	namespace HexChipParam
	{
		constexpr float HEX_LENGTH = 700.f;
		constexpr float TEXTURE_SCALE = 0.15f;

		const auto UNIT_X = GameLib::Vector2{ HEX_LENGTH * TEXTURE_SCALE,0.f };
		const auto UNIT_Y = GameLib::Vector2::Rotation(UNIT_X, GameLib::PI / 3.f);
	}
}