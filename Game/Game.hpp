#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameScene/GameData.hpp"

namespace Game
{
	class SceneBase;
	class RectCurtain;

	class Game : public GameLib::Actor
	{
		//現在のシーン
		SceneBase* mNowScene;

		//記録
		GameData mGameData;

		//シーン遷移用
		RectCurtain* mRectCurtain;

	public:
		Game(GameLib::Actor*);

		void CustomizeUpdate() override;

	private:

		//StageChangeFlagが立った時の処理
		//くそい
		void GoStage();
		void GoTitle();
		void GoStageSelect();
		void GoStageSelectFromTitle();
		void StageClear();
		void MissStage();
		void GoStageSelectFromZero();
		void GoGameClear();

		//TitleScene用
		int GetStarNum();


	};
}