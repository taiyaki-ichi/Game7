#include"SlideTree.hpp"

namespace Game::Stage::BackGround
{
	
	SlideTree230::SlideTree230(GameLib::Actor* actor, const GameLib::Vector2& pos)
		:SlideObjectBase{actor,"../Assets/BackGround/tree-230.png",pos,0.3f,100.f,-1.f,0.9f,0.9f,-210}
	{
	}
	
	SlideTree180::SlideTree180(GameLib::Actor* actor, const GameLib::Vector2& pos)
		: SlideObjectBase{ actor,"../Assets/BackGround/tree-180.png",pos,0.4f,100.f,-1.f,0.7f,0.7f,-160 }
	{
	}

	SlideTree130::SlideTree130(GameLib::Actor* actor, const GameLib::Vector2& pos)
		: SlideObjectBase{ actor,"../Assets/BackGround/tree-130.png",pos,0.5f,150.f,-1.f,0.5f,0.5f,-110 }
	{
	}

}