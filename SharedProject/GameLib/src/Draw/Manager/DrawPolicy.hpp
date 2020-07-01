#pragma once
#include"GameLib/include/Draw/DrawBase.hpp"

namespace GameLib
{

	struct DrawPolicy {
		void operator()(DrawBase* sprite) {
			if (sprite->GetIsDrawing())
				sprite->Draw();
		}
	};

}