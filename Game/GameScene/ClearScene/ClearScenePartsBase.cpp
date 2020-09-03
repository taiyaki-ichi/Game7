#include"ClearScenePartsBase.hpp"

namespace Game
{
	ClearScenePartsBase::ClearScenePartsBase(GameLib::Actor* actor)
		:GameLib::Actor{actor}
		, mFlag{0}
	{}

	bool ClearScenePartsBase::CheckFlag(unsigned char flag)
	{
		return mFlag & flag;
	}

	void ClearScenePartsBase::UpFlag(unsigned char flag)
	{
		mFlag |= flag;
	}

	void ClearScenePartsBase::DownFlag(unsigned char flag)
	{
		mFlag &= ~flag;
	}
}