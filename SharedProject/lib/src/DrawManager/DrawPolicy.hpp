#pragma once
#include"lib/include/Component/Draw/SpriteCompoent.hpp"

namespace GameLib
{
	struct DrawPolicy {
		void operator()(SpriteComponent* sprite) {
			sprite->Draw();
		}
	};
}