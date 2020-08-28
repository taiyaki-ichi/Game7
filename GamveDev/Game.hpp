#pragma once
#include"GameLib/include/Actor/RootActor.hpp"
#include"GameScene/GameData.hpp"

namespace Game
{
	class SceneBase;
	class RectCurtain;

	class Game : public GameLib::RootActor
	{
		//現在のシーン
		SceneBase* mNowScene;

		//記録
		GameData mGameData;

		//シーン遷移用
		RectCurtain* mRectCurtain;

	public:
		Game();

		void CustomizeUpdate() override;

	private:
		//セーブデータ
		//これメンバにする必要がない
		GameData Load();
		void Save(const GameData&);

		//StageChangeFlagが立った時の処理
		void GoStage();
		void GoTitle();
		void GoStageSelect();
		void StageClear();
		void MissStage();
		


	};
}