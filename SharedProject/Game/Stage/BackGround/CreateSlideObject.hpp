#pragma once
#include<vector>

namespace GameLib {
	class Actor;
}

namespace Game::Stage::BackGround
{
	class SlideObjectBase;

	std::vector<SlideObjectBase*> CreateSlideSharpTree(GameLib::Actor* stage);
	std::vector<SlideObjectBase*> CreateSlideRoundTree(GameLib::Actor* stage);
	std::vector<SlideObjectBase*> CreateSlideTotemPole(GameLib::Actor* stage);
	std::vector<SlideObjectBase*> CreateSlideTemple(GameLib::Actor* stage);
}