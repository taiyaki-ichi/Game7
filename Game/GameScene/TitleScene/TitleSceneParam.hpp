#pragma once
#include"GameLib/include/Math/Vector2.hpp"

namespace Game
{
	namespace TitleSceneParam
	{
		constexpr float BUTTON_WIDTH = 200.f;
		constexpr float BUTTON_HEIGHT = 200.f;
		constexpr float BUTTON_FLAME_WIDTH = 10.f;

		const GameLib::Vector2 A_BUTTON_ADJUST = { -150.f,-120.f };
		const GameLib::Vector2 D_BUTTON_ADJUST = { 150.f,-120.f };

		//Button‚ÌˆÊ’u‚©‚ç‚Ì‹——£
		const GameLib::Vector2 BUTTON_STRING_TAG_ADJUST{ 0.f,120.f };

		constexpr float KAKKO_ADJUST = 20.f;

		const GameLib::Vector2 TITLELOGO_POS{ 0.f,150.f };

		constexpr float KAKKO_MOVE_LENGTH = 4.f;
		constexpr float KAKKO_TEXTURE_SCALE = 0.05f;

		const GameLib::Vector2 STAR_DISPLAY_ADJUST{ 0.f,-75.f };

	}
}