#pragma once
#include"GameLib/include/Math/Vector2.hpp"
#include"Stage/WindowSize.hpp"
#include"HexChip/ToVector2.hpp"

namespace Game
{
	namespace StageSelectParam
	{
		constexpr float ICON_SCALE = 0.15f;
		constexpr float ICON_TEXTURE_ADJUST_Y = 35.f;
		constexpr float ICON_MOVE_LENGHT = 8.f;

		const GameLib::Vector2 STAGENAME_DISPLAY_POSITION = { 0.f,Stage::WindowSize::HEIGHT / 2.f - 25.f };
		const GameLib::Vector2 LEVEL_DISPLAY_POSITION = { 0.f,Stage::WindowSize::HEIGHT / 2.f - 70.f };
		const GameLib::Vector2 TEARGEM_DIPLAY_POSITION = { 0.f,-Stage::WindowSize::HEIGHT / 2.f + 50.f };

		const GameLib::Vector2 LIFE_NUM_POSITION = { Stage::WindowSize::WIDTH / 2.f - 70.f,Stage::WindowSize::HEIGHT / 2.f - 25.f };
		const GameLib::Vector2 GEM_NUM_POSITION = LIFE_NUM_POSITION + GameLib::Vector2{ 0.f,-35.f };

		const GameLib::Vector2 MOVEKEYASSIST_POSITION = { -Stage::WindowSize::WIDTH / 2.f + 100.f,-Stage::WindowSize::HEIGHT / 2.f + 100.f };

		const GameLib::Vector2 SAVE_POSITION = ToVector2(-1, 1) + GameLib::Vector2{ 0.f,80.f };
		const GameLib::Vector2 RETURN_TITLE_POSITION = ToVector2(0, -1) + GameLib::Vector2{ 0.f,-80.f };
	}
}