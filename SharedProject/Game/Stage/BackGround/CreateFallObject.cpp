#include"CreateFallObject.hpp"
#include"FallLeaf.hpp"
#include"BackGroundAdjustPos.hpp"
#include<random>
#include"GameLib/include/Viewport/Viewport.hpp"
#include "CreateFallObject.hpp"
#include"GameLib/include/Math/Numbers.hpp"
#include"Game/Stage/Stage.hpp"

namespace Game::Stage::BackGround
{

	namespace {
		std::random_device seed_gen{};
		std::mt19937 engine(seed_gen());
		std::uniform_real_distribution<> generateX(RANGE_LEFT, RANGE_RIGHT);
		std::uniform_real_distribution<> generateY(RANGE_BOTTOM, RANGE_TOP);
		std::uniform_real_distribution<> rate(0.0, 1.0);
	}


	void CreateFallLeaf(Stage* stage)
	{
		auto viewPortPos = GameLib::Viewport::GetPos();

		for (int i = 0; i < 30; i++) {
			float x = generateX(engine);
			float y = generateY(engine);
			auto pos = GameLib::Vector2{ x,y } + viewPortPos;
			float rot = GameLib::PI * 2.f * rate(engine);
			new FallLeaf160{ stage,std::move(pos),rot };
		}

		for (int i = 0; i < 30; i++) {
			float x = generateX(engine);
			float y = generateY(engine);
			auto pos = GameLib::Vector2{ x,y } + viewPortPos;
			float rot = GameLib::PI * 2.f * rate(engine);
			new FallLeaf200{ stage,std::move(pos),rot};
		}
	}

}