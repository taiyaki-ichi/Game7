#pragma once
#include"lib/src/Draw/DrawBase.hpp"

namespace GameLib
{

	struct DrawPolicy {
		void operator()(DrawBase* sprite) {
			sprite->Draw();
		}
	};

}