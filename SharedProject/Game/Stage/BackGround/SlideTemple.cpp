#include"SlideTemple.hpp"

namespace Game::Stage::BackGround
{
	SlideTemple230::SlideTemple230(GameLib::Actor* actor, GameLib::Vector2&& pos)
		:SlideObjectBase{ actor,"../Assets/BackGround/temple-230.png",pos,0.39f,150.f,-1.f,0.9f,0.9f,-210 }
	{
	}
	SlideTemple180::SlideTemple180(GameLib::Actor* actor, GameLib::Vector2&& pos)
		: SlideObjectBase{ actor,"../Assets/BackGround/temple-180.png",pos,0.38f,150.f,-1.f,0.7f,0.7f,-160 }
	{
	}
	SlideTemple130::SlideTemple130(GameLib::Actor* actor, GameLib::Vector2&& pos)
		: SlideObjectBase{ actor,"../Assets/BackGround/temple-130.png",pos,0.37f,150.f,-1.f,0.5f,0.5f,-110 }
	{
	}
}