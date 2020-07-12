#include"CreateSlideObject.hpp"
#include"SlideTree.hpp"
#include"Game/Stage/Stage.hpp"
#include"Game/Window.hpp"

namespace Game::Stage::BackGround
{
	void CreateSlideSharpTree(Stage* stage)
	{
		float w;
		int num;

		num = 5;
		w = (WINDOW_WIDTH + 200.f) / num;
		for (int i = 0; i < num; i++)
			new SlideSharpTree230{ stage,GameLib::Vector2{ w / 2.f + w * i,200.f } };

		num = 4;
		w = (WINDOW_WIDTH + 200.f) / num;
		for (int i = 0; i < num; i++)
			new SlideSharpTree180{ stage,GameLib::Vector2{ w / 2.f + w * i,140.f } };

		num = 4;
		w = (WINDOW_WIDTH + 300.f) / num;
		for (int i = 0; i < num; i++)
			new SlideSharpTree130{ stage,GameLib::Vector2{ w / 2.f + w * i,90.f } };
	}
	void CreateSlideRoundTree(Stage* stage)
	{
		float w;
		int num;

		num = 5;
		w = (WINDOW_WIDTH + 200.f) / num;
		for (int i = 0; i < num; i++)
			new SlideRoundTree230{ stage,GameLib::Vector2{ w / 2.f + w * i,200.f } };

		num = 3;
		w = (WINDOW_WIDTH + 300.f) / num;
		for (int i = 0; i < num; i++)
			new SlideRoundTree180{ stage,GameLib::Vector2{ w / 2.f + w * i,140.f } };

		num = 3;
		w = (WINDOW_WIDTH + 400.f) / num;
		for (int i = 0; i < num; i++)
			new SlideRoundTree130{ stage,GameLib::Vector2{ w / 2.f + w * i,90.f } };
	}
}