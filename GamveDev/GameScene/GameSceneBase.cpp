#include"GameSceneBase.hpp"

namespace Game
{
	SceneBase::SceneBase(GameLib::Actor* actor,const GameData& gameData)
		:GameLib::Actor{ actor }
		, mGameData{ gameData }
		, mFlag{0}
	{

	}

	void SceneBase::UpFlag(unsigned int flag)
	{
		mFlag |= flag;
	}

	void SceneBase::DownFlag(unsigned int flag)
	{
		mFlag &= ~flag;
	}

	const GameData& SceneBase::GetGameData() const
	{
		return mGameData;
	}

	bool SceneBase::CheckFlag(unsigned int flag)
	{
		return mFlag & flag;
	}

	bool SceneBase::CheckFlag()
	{
		return mFlag;
	}
}