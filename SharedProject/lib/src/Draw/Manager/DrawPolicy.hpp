#pragma once
#include"lib/include/Draw/DrawBase.hpp"

namespace GameLib
{

	struct DrawPolicy {
		void operator()(DrawBase* sprite) {
			sprite->Draw();
		}
	};

}