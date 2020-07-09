#pragma once
#include"Game/Window.hpp"

namespace Game::Stage
{
	namespace CollisionDetectionScope {

		//当たり判定を行う範囲をウィンドウのサイズより400.f余裕を持たす
		//対角線の長さが400.f以下の物体なら、画面内にあるとき確実に当たり判定が行われる
		//300.f×300.fが最大値のめやす、余裕をもって

		constexpr float MARGIN = 400.f;
		constexpr float WIDTH = WINDOW_WIDTH + MARGIN * 2.f;
		constexpr float HEIGHT = WINDOW_HEIGHT + MARGIN * 2.f;
	}
}