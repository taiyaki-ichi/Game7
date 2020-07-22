#include"SlideTotemPole.hpp"

namespace Game::Stage::BackGround
{
	SlideTotemPole130::SlideTotemPole130(GameLib::Actor* actor, GameLib::Vector2&& pos)
		: SlideObjectBase{ actor,"../Assets/BackGround/pole-130.png",pos,0.45f,150.f,-1.f,0.5f,0.5f,-110 }
	{
	}
	SlideTotemPole180::SlideTotemPole180(GameLib::Actor* actor, GameLib::Vector2&& pos)
		: SlideObjectBase{ actor,"../Assets/BackGround/pole-180.png",pos,0.35f,100.f,-1.f,0.7f,0.7f,-160 }
	{
	}
	SlideTotemPole230::SlideTotemPole230(GameLib::Actor* actor, GameLib::Vector2&& pos)
		:SlideObjectBase{ actor,"../Assets/BackGround/pole-230.png",pos,0.25f,100.f,-1.f,0.9f,0.9f,-210 }
	{
	}
}