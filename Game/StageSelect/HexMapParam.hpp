#pragma once
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Math/Numbers.hpp"
#include"Stage/WindowSize.hpp"

namespace Game::StageSelect
{
	namespace HexMapParam
	{
		constexpr float HEX_LENGTH = 700.f;
		constexpr float TEXTURE_SCALE = 0.15f;
		constexpr float ICON_SCALE = 0.15f;

		constexpr float ICON_TEXTURE_ADJUST_Y = 35.f;
		constexpr float ICON_MOVE_LENGHT = 8.f;

		const auto UNIT_X = GameLib::Vector2{ HexMapParam::HEX_LENGTH * HexMapParam::TEXTURE_SCALE,0.f };
		const auto UNIT_Y = GameLib::Vector2::Rotation(UNIT_X, GameLib::PI / 3.f);

		const GameLib::Vector2 LIFE_NUM_POSITION = { Stage::WindowSize::WIDTH / 2.f - 70.f,Stage::WindowSize::HEIGHT / 2.f - 25.f };
		const GameLib::Vector2 GEM_NUM_POSITION = LIFE_NUM_POSITION + GameLib::Vector2{ 0.f,-35.f };
		
	}
}