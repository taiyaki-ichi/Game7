#pragma once
#include"GameLib/include/Draw/DrawBase.hpp"
#include"GameLib/src/Windows/Graphics.hpp"

namespace GameLib
{

	struct DrawPolicy {
		void operator()(DrawBase* sprite) {
			if (sprite->GetIsAutoDrawing()) {
				ClearStencilBuffer(1);
				SetStanderdStencilBufferState();
				sprite->Draw();
			}
		}
	};

}