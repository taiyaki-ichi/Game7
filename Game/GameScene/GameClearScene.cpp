#include"GameClearScene.hpp"
#include"ClearScene/ClearSceneFlag.hpp"
#include"ClearScene/GameClearParts.hpp"
#include"GameSceneFlag.hpp"
#include"ClearScene/IsSaveParts.hpp"
#include"ClearScene/SavedParts.hpp"

namespace Game
{
	ClearScene::ClearScene(GameLib::Actor* actor,const GameData& gameData)
		:SceneBase{ actor,gameData }
		, mClearSceneBase{ nullptr }
	{
		mClearSceneBase = new GameClearParts{ this };
	}

	void ClearScene::CustomizeUpdate()
	{
		//ƒZ[ƒu‚Íˆê‰ñ
		if (CheckFlag(SceneFlag::SAVE_FLAG))
			DownFlag(SceneFlag::SAVE_FLAG);

		if (mClearSceneBase->CheckFlag(ClearSceneFlag::GO_IS_SAVE_FLAG))
		{
			mClearSceneBase->SetState(GameLib::Actor::State::Dead);
			mClearSceneBase = new IsSaveParts{ this };
		}
		else if (mClearSceneBase->CheckFlag(ClearSceneFlag::GO_SAVED_FLAG))
		{
			mClearSceneBase->SetState(GameLib::Actor::State::Dead);
			UpFlag(SceneFlag::SAVE_FLAG);
			mClearSceneBase = new SavedParts{ this };
		}
		else if (mClearSceneBase->CheckFlag(ClearSceneFlag::GO_TITLE_FLAG))
		{
			UpFlag(SceneFlag::GO_TITLE_FLAG);
		}
	}
}