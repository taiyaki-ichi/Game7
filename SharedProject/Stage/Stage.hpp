#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<string>
#include"SceneManager/Scene/Actor/Player/ItemNum/ItemNumData.hpp"
#include"GameLib/include/Math/Vector2.hpp"

namespace Stage
{
	class Pause;
	class SceneManager;

	class Stage : public GameLib::Actor
	{
		
		//ステージのObjectを一括で管理する
		//Pauseの時とか
		SceneManager* mSceneManager;

		char mFlags;

	public:

		Stage(GameLib::Actor* game, std::string&& stageDataFileName, int playerLifeNum = 5, int playerGemNum = 10);
		virtual ~Stage() = default;

		//Pauseの生成
		void CustomizeUpdate() override;

		//Pauseからの通知用,フラグを立てる
		void ReturnToTitle();

		bool CheckFlag(char);

		//クリア時に呼び出し集計
		ItemNumData GetItemNumData();
	};
}