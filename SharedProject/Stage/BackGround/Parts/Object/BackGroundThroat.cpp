#include"BackGroundThroat.hpp"

namespace Stage::BackGround
{

	Throat230::Throat230(GameLib::Actor* actor, bool isUpsideDown)
		:ObjectBase{ actor,"../Assets/BackGround/throat-230.png" ,-40 }
	{
		SetScale(0.7f);
		SetMoveRateXY(0.3f, 0.7f);

		mTexture.SetVerticalFlip(isUpsideDown);
	}

	Throat180::Throat180(GameLib::Actor* actor, bool isUpsideDown)
		:ObjectBase{ actor,"../Assets/BackGround/throat-180.png" ,-160 }
	{
		SetScale(0.5f);
		SetMoveRateXY(0.5f, 0.8f);

		mTexture.SetVerticalFlip(isUpsideDown);
	}

	Throat130::Throat130(GameLib::Actor* actor, bool isUpsideDown)
		:ObjectBase{ actor,"../Assets/BackGround/throat-130.png" ,-190 }
	{
		SetScale(0.3f);
		SetMoveRateXY(0.7f, 0.9f);

		mTexture.SetVerticalFlip(isUpsideDown);
	}

}