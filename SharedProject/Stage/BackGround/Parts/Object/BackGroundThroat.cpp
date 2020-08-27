#include"BackGroundThroat.hpp"

namespace Stage::BackGround
{
	Throat140::Throat140(GameLib::Actor* actor, bool isUpsideDown)
		:ObjectBase{ actor,"../Assets/BackGround/throat-140.png" ,-40 }
	{
		SetScale(0.7f);
		SetMoveRateXY(0.1f, 1.f);

		mTexture.SetVerticalFlip(isUpsideDown);
	}

	Throat120::Throat120(GameLib::Actor* actor, bool isUpsideDown)
		:ObjectBase{ actor,"../Assets/BackGround/throat-120.png" ,-90 }
	{
		SetScale(0.5f);
		SetMoveRateXY(0.3f, 1.f);

		mTexture.SetVerticalFlip(isUpsideDown);
	}

	Throat100::Throat100(GameLib::Actor* actor, bool isUpsideDown)
		:ObjectBase{ actor,"../Assets/BackGround/throat-100.png" ,-140 }
	{
		SetScale(0.3f);
		SetMoveRateXY(0.5f, 1.f);

		mTexture.SetVerticalFlip(isUpsideDown);
	}

}