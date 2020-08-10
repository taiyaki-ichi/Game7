#include"BackGroundTotemPole.hpp"

namespace Stage::BackGround
{

	TotemPole130::TotemPole130(GameLib::Actor* actor)
		:ObjectBase{ actor,"../Assets/BackGround/pole-130.png" ,-110}
	{
		SetScale(0.45f);
		SetMoveRateXY(0.5f, 0.5f);
	}

	TotemPole180::TotemPole180(GameLib::Actor* actor)
		: ObjectBase{ actor,"../Assets/BackGround/pole-180.png" ,-160 }
	{
		SetScale(0.35f);
		SetMoveRateXY(0.7f, 0.7f);
	}

	TotemPole230::TotemPole230(GameLib::Actor* actor)
		: ObjectBase{ actor,"../Assets/BackGround/pole-230.png" ,-210 }
	{
		SetScale(0.25f);
		SetMoveRateXY(0.9f, 0.9f);
	}

}