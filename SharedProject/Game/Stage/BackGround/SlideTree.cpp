#include"SlideTree.hpp"

namespace Game::Stage::BackGround
{
	
	SlideSharpTree230::SlideSharpTree230(GameLib::Actor* actor, GameLib::Vector2&& pos)
		:SlideObjectBase{actor,"../Assets/BackGround/tree-230.png",pos,0.3f,100.f,-1.f,0.9f,0.9f,-210}
	{
	}
	
	SlideSharpTree180::SlideSharpTree180(GameLib::Actor* actor, GameLib::Vector2&& pos)
		: SlideObjectBase{ actor,"../Assets/BackGround/tree-180.png",pos,0.4f,100.f,-1.f,0.7f,0.7f,-160 }
	{
	}

	SlideSharpTree130::SlideSharpTree130(GameLib::Actor* actor, GameLib::Vector2&& pos)
		: SlideObjectBase{ actor,"../Assets/BackGround/tree-130.png",pos,0.5f,150.f,-1.f,0.5f,0.5f,-110 }
	{
	}

	SlideRoundTree230::SlideRoundTree230(GameLib::Actor* actor, GameLib::Vector2&& pos)
		: SlideObjectBase{ actor,"../Assets/BackGround/tree2-230.png",pos,0.3f,100.f,-1.f,0.9f,0.9f,-210 }
	{
	}

	SlideRoundTree180::SlideRoundTree180(GameLib::Actor* actor, GameLib::Vector2&& pos)
		: SlideObjectBase{ actor,"../Assets/BackGround/tree2-180.png",pos,0.4f,150.f,-1.f,0.7f,0.7f,-160 }
	{
	}

	SlideRoundTree130::SlideRoundTree130(GameLib::Actor* actor, GameLib::Vector2&& pos)
		: SlideObjectBase{ actor,"../Assets/BackGround/tree2-130.png",pos,0.5f,200.f,-1.f,0.5f,0.5f,-110 }
	{
	}

}