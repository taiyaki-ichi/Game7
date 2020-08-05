#include"BackGroundTemple.hpp"

namespace Stage::BackGround
{
	Temple130::Temple130(GameLib::Actor* actor)
		:ObjectBase{ actor,"../Assets/BackGround/temple-130.png" ,-110 }
	{
		SetScale(0.39f);
		SetMoveRateXY(0.5f, 0.5f);
	}

	Temple180::Temple180(GameLib::Actor* actor)
		: ObjectBase{ actor,"../Assets/BackGround/temple-180.png" ,-160 }
	{
		SetScale(0.38f);
		SetMoveRateXY(0.7f, 0.7f);
	}

	Temple230::Temple230(GameLib::Actor* actor)
		: ObjectBase{ actor,"../Assets/BackGround/temple-230.png" ,-210 }
	{
		SetScale(0.39f);
		SetMoveRateXY(0.9f, 0.9f);
	}
}