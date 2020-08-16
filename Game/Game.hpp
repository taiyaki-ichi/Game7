#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<unordered_map>
#include"StageSelect/HexVec.hpp"

namespace Stage
{
	class Stage;
}

namespace Game
{
	class Title;
	class StageSelect;
	class RectCurtain;

	class Game : public GameLib::Actor
	{
		Title* mTitle;
		StageSelect* mStageSelect;
		Stage::Stage* mStage;

		//nullptrじゃあないやつを呼び出す
		//あんまりよくなさげ
		void UpdateTitle();
		void UpdateStageSelect();
		void UpdateStage();

		RectCurtain* mRectCurtain;

		//ゲームのデータたち
		std::unordered_map<HexVec, unsigned char> mSaveData;
		int mPlayerLifeNum;
		int mPlayerGemNum;
		//StageSelectでSpaceが押されたとき更新
		HexVec mPosition;

		//ファイルに書き込み、基本的にStageSelectから呼ばれると思う
		bool Save();

		//Gameが生成されたときに呼び出されるかな
		bool Load();

	public:
		Game(GameLib::Actor*);
		virtual ~Game() = default;

		void CustomizeUpdate() override;
	};
}