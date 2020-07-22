#include"CreateSlideObject.hpp"
#include"SlideTree.hpp"
#include"Game/Stage/Stage.hpp"
#include"Game/Window.hpp"
#include"SlideTotemPole.hpp"

namespace Game::Stage::BackGround
{
	std::vector<SlideObjectBase*> CreateSlideSharpTree(GameLib::Actor* stage)
	{
		std::vector<SlideObjectBase*> slideObjects;

		float w;
		int num;

		num = 5;
		w = (WINDOW_WIDTH + 200.f) / num;
		for (int i = 0; i < num; i++)
			slideObjects.emplace_back(new SlideSharpTree230{ stage,GameLib::Vector2{ w / 2.f + w * i,200.f } });

		num = 4;
		w = (WINDOW_WIDTH + 200.f) / num;
		for (int i = 0; i < num; i++)
			slideObjects.emplace_back(new SlideSharpTree180{ stage,GameLib::Vector2{ w / 2.f + w * i,140.f } });

		num = 4;
		w = (WINDOW_WIDTH + 300.f) / num;
		for (int i = 0; i < num; i++)
			slideObjects.emplace_back(new SlideSharpTree130{ stage,GameLib::Vector2{ w / 2.f + w * i,90.f } });

		return slideObjects;
	}
	std::vector<SlideObjectBase*> CreateSlideRoundTree(GameLib::Actor* stage)
	{
		std::vector<SlideObjectBase*> slideObject;

		float w;
		int num;

		num = 5;
		w = (WINDOW_WIDTH + 200.f) / num;
		for (int i = 0; i < num; i++)
			slideObject.emplace_back(new SlideRoundTree230{ stage,GameLib::Vector2{ w / 2.f + w * i,200.f } });

		num = 3;
		w = (WINDOW_WIDTH + 300.f) / num;
		for (int i = 0; i < num; i++)
			slideObject.emplace_back(new SlideRoundTree180{ stage,GameLib::Vector2{ w / 2.f + w * i,140.f } });

		num = 3;
		w = (WINDOW_WIDTH + 400.f) / num;
		for (int i = 0; i < num; i++)
			slideObject.emplace_back(new SlideRoundTree130{ stage,GameLib::Vector2{ w / 2.f + w * i,90.f } });
			
	
		//new SlideRoundTree130{ stage,GameLib::Vector2{ -200.f,90.f } };

		return slideObject;
	}
	std::vector<SlideObjectBase*> CreateSlideTotemPole(GameLib::Actor* stage)
	{
		std::vector<SlideObjectBase*> slideObjects;

		float w;
		int num;

		num = 5;
		w = (WINDOW_WIDTH + 200.f) / num;
		for (int i = 0; i < num; i++)
			slideObjects.emplace_back(new SlideTotemPole230{ stage,GameLib::Vector2{ w / 2.f + w * i,180.f } });

		num = 4;
		w = (WINDOW_WIDTH + 200.f) / num;
		for (int i = 0; i < num; i++)
			slideObjects.emplace_back(new SlideTotemPole180{ stage,GameLib::Vector2{ w / 2.f + w * i,120.f } });

		num = 4;
		w = (WINDOW_WIDTH + 300.f) / num;
		for (int i = 0; i < num; i++)
			slideObjects.emplace_back(new SlideTotemPole130{ stage,GameLib::Vector2{ w / 2.f + w * i,70.f } });

		return slideObjects;
	}
}