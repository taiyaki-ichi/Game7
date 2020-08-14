#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<map>

namespace Game
{
	class Title;
	class StageSelect;
	class Stage;

	class Game : public GameLib::Actor
	{
		Title* mTitle;
		StageSelect* mStageSelect;
		Stage* mStage;

		//nullptrじゃあないやつを呼び出す
		//あんまりよくなさそう
		void UpdateTitle();
		void UpdateStageSelect();
		void UpdateStage();

		//ゲームのデータたち
		std::map<std::pair<int, int>, unsigned char> mSaveData;
		int mPlayerLifeNum;
		int mPlayerGemNum;
		//StageSelectでSpaceが押されたとき更新
		std::pair<int, int> mPosition;

		//ファイルに書き込み、基本的にStageSelectから呼ばれると思う
		bool Save();

		//Gameが生成されたときに呼び出されるかな
		bool Load();




	};
}