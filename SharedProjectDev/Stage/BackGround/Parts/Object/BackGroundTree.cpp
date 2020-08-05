#include"BackGroundTree.hpp"

namespace Stage::BackGround
{

	SharpTree230::SharpTree230(GameLib::Actor* actor)
		:ObjectBase{ actor,"../Assets/BackGround/tree-230.png" ,-210 }
	{
		SetScale(0.3f);
		SetMoveRateXY(0.9f, 0.9f);
	}

	SharpTree180::SharpTree180(GameLib::Actor* actor)
		:ObjectBase{ actor,"../Assets/BackGround/tree-180.png",-160 }
	{
		SetScale(0.4f);
		SetMoveRateXY(0.7f, 0.7f);
	}

	SharpTree130::SharpTree130(GameLib::Actor* actor)
		:ObjectBase{ actor,"../Assets/BackGround/tree-130.png",-110 }
	{
		SetScale(0.5f);
		SetMoveRateXY(0.5f, 0.5f);

	}

	RoundTree230::RoundTree230(GameLib::Actor* actor)
		:ObjectBase{ actor,"../Assets/BackGround/tree2-230.png" ,-210 }
	{
		SetScale(0.3f);
		SetMoveRateXY(0.95f, 0.95f);
	}

	RoundTree180::RoundTree180(GameLib::Actor* actor)
		:ObjectBase{ actor,"../Assets/BackGround/tree2-180.png",-160 }
	{
		SetScale(0.4f);
		SetMoveRateXY(0.7f, 0.7f);
	}

	RoundTree130::RoundTree130(GameLib::Actor* actor)
		:ObjectBase{ actor,"../Assets/BackGround/tree2-130.png",-110 }
	{
		SetScale(0.5f);
		SetMoveRateXY(0.5f, 0.5f);

	}


}