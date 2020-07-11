#pragma once
#include"GameLib/include/Math/Vector2.hpp"
#include"Game/Window.hpp"
#include<utility>
#include"GameLib/include/Viewport/Viewport.hpp"

namespace Game::Stage::BackGround
{
	constexpr static float RANGE_LEFT = -WINDOW_WIDTH / 2.f - 50.f;
	constexpr static float RANGE_RIGHT = WINDOW_WIDTH / 2.f + 50.f;
	constexpr static float RANGE_BOTTOM = -WINDOW_HEIGHT / 2.f - 50.f;
	constexpr static float RANGE_TOP = WINDOW_HEIGHT / 2.f + 50.f;

	//rateはViewPortの移動量から加算する割合
	inline GameLib::Vector2 AdjustPos(GameLib::Vector2&& vec) {

		while (vec.x < RANGE_LEFT)
			vec.x += (RANGE_RIGHT - RANGE_LEFT);
		while (vec.x >= RANGE_RIGHT)
			vec.x -= (RANGE_RIGHT - RANGE_LEFT);
		while (vec.y < RANGE_BOTTOM)
			vec.y += (RANGE_TOP - RANGE_BOTTOM);
		while (vec.y >= RANGE_TOP)
			vec.y -= (RANGE_TOP - RANGE_BOTTOM);

		return std::move(vec);
	}

	//ViewPortの影響を考慮するバージョン
	inline GameLib::Vector2 AdjustPos(const GameLib::Vector2& vec, float rate) {

		auto result = vec + GameLib::Viewport::GetPos() * rate;
		result -= GameLib::Viewport::GetPos();
		result = AdjustPos(std::move(result));
		result += GameLib::Viewport::GetPos();

		return result;
	}

}