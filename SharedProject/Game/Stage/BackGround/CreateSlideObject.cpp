#include"CreateSlideObject.hpp"
#include"SlideTree.hpp"
#include"Game/Stage/Stage.hpp"
#include"Game/Window.hpp"

namespace Game::Stage::BackGround
{
	void CreateSlideTree(Stage* stage)
	{
		float w;
		int num;

		num = 5;
		w = (WINDOW_WIDTH + 200.f) / num;
		for (int i = 0; i < num; i++)
			new SlideTree230{ stage,GameLib::Vector2{ w / 2.f + w * i,200.f } };

		num = 4;
		w = (WINDOW_WIDTH + 200.f) / num;
		for (int i = 0; i < num; i++)
			new SlideTree180{ stage,GameLib::Vector2{ w / 2.f + w * i,140.f } };

		num = 4;
		w = (WINDOW_WIDTH + 300.f) / num;
		for (int i = 0; i < num; i++)
			new SlideTree130{ stage,GameLib::Vector2{ w / 2.f + w * i,90.f } };
	}
}