#include"Game.hpp"
#include"GameScene/GameSceneFlag.hpp"
#include"RectCurtain/RectCurtain.hpp"
#include"GameScene/GameSceneBase.hpp"
#include"StageData.hpp"
#include"GameScene/StageDataParam.hpp"
#include"GameScene/GameStage.hpp"
#include"GameScene/StageSelect.hpp"
#include"GameScene/StageStateFlag.hpp"
#include"LoadSaveFunc.hpp"
#include"GameScene/TitleScene.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"TemporaryMessage/TemporaryMessage.hpp"
#include"GameParam.hpp"
#include"GameScene/GameOverScene.hpp"
#include"GameScene/GameClearScene.hpp"

namespace Game
{
	Game::Game()
		:RootActor{}
		, mNowScene{ nullptr }
		, mGameData{}
		, mRectCurtain{ nullptr }
	{
		mGameData = LoadGameData();

		mNowScene = new TitleScene{ this,mGameData };

		mRectCurtain = new RectCurtain{ this };
	}

	void Game::CustomizeUpdate()
	{
		if (mNowScene->CheckFlag(SceneFlag::SAVE_FLAG))
		{
			mGameData = mNowScene->GetGameData();
			SaveGameData(mGameData);

			auto ptr = new TemporaryMessage{ this,GameParam::SAVE_MESSAGE_TIME };
			ptr->SetPosition(GameParam::SAVE_MESSAGE_POS);
			ptr->SetSize(GameLib::Font::Size::Size_48);
			ptr->SetText("セーブかんりょう！");
		}
		//シーンを変更するフラグのどれかが立っており、カーテンが開いているなら
		//現在のシーンを止めて、カーテンを閉める
		else if (mNowScene->CheckFlag() && mRectCurtain->IsOpen())
		{
			mNowScene->SetState(GameLib::Actor::State::Pause);
			mRectCurtain->Close();
		}

		//カーテンが閉じられたときシーンを変えカーテンあける
		//GameDataの行進が必要な際はそうする
		if (mRectCurtain->IsClose())
		{
			GameLib::Viewport::SetPos({ 0.f,0.f });
			GameLib::Viewport::SetRotation(0.f);
			GameLib::Viewport::SetScale(1.f);

			mNowScene->SetState(GameLib::Actor::State::Dead);

			using namespace SceneFlag;
			if (mNowScene->CheckFlag(GO_STAGE_FLAG))
				GoStage();
			else if (mNowScene->CheckFlag(STAGE_CLAER_FLAG))
				StageClear();
			else if (mNowScene->CheckFlag(STAGE_MISS_FLAG))
				MissStage();
			else if (mNowScene->CheckFlag(GO_STAGESELECT_FLAG))
				GoStageSelect();
			else if (mNowScene->CheckFlag(GO_STAGESELECT_FROM_ZERO_FLAG))
				GoStageSelectFromZero();
			else if (mNowScene->CheckFlag(GO_STAGESELECT_FROM_TITLE_FLAG))
				GoStageSelectFromTitle();
			else if (mNowScene->CheckFlag(GO_GAME_CLEAR_FLAG))
				GoGameClear();
			else
				GoTitle();

			mRectCurtain->Open();
		}
	}

	void Game::GoStage()
	{
		mGameData.mNowPos = mNowScene->GetGameData().mNowPos;
		auto iter = gStageData.find(mGameData.mNowPos);
		//一応
		if (iter != gStageData.end() && iter->second.size() == StageDataParam::STAGE_STRING_NUM)
		{
			auto bgType = Stage::BackGroundType::None;
			auto bgIter = gStageBackGroundType.find(iter->second[0]);
			if (bgIter != gStageBackGroundType.end())
				bgType = bgIter->second;
			mNowScene = new GameStage{ this,mGameData,iter->second[0] ,std::move(bgType) };
		}

	}

	void Game::GoTitle()
	{
		mGameData = mNowScene->GetGameData();
		mNowScene = new TitleScene{ this,mGameData };
	}

	void Game::GoStageSelect()
	{
		mNowScene = new StageSelect{ this,mGameData,gStageData };
	}

	void Game::GoStageSelectFromTitle()
	{
		mGameData = mNowScene->GetGameData();
		mGameData.mNowPos = { 0,0 };
		mNowScene = new StageSelect{ this,mGameData,gStageData };
	}

	void Game::StageClear()
	{
		mGameData = mNowScene->GetGameData();
		//クリアした場合最大3方向へ行けるようになるようセーブデータを変更
		for (auto& adHexVec : { DIR_E,DIR_D,DIR_X })
		{
			auto pos = mGameData.mNowPos + adHexVec;
			auto iter = gStageData.find(pos);
			if (iter != gStageData.end())
				mGameData.mSaveData.insert({ pos, StageStateFlag::OPEN_FLAG });
		}

		mNowScene = new StageSelect{ this,mGameData,gStageData };
	}

	void Game::MissStage()
	{
		//残機を減らす作業はStageSceneでやる
		mGameData = mNowScene->GetGameData();

		//残機がなくなったらゲームおーば
		if (mGameData.mPlayerLifeNum == 0)
		{
			mGameData = START_GAMEDATA;

			mNowScene = new GameOverScene{ this,mGameData };
		}
		else 
			mNowScene = new StageSelect{ this,mGameData,gStageData };
		
	}

	void Game::GoStageSelectFromZero()
	{
		mGameData = START_GAMEDATA;
		mNowScene = new StageSelect{ this,mGameData,gStageData };
	}

	void Game::GoGameClear()
	{
		mNowScene = new ClearScene{ this,mGameData };
	}
	
}