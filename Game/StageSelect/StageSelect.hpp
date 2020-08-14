#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<map>
#include<vector>
#include<string>
#include"DataDisplay/StringDisplay.hpp"
#include"DataDisplay/TearGemDisplay.hpp"
#include"Stage/SceneManager/Scene/Actor/Player/ItemNum/GemDisplay.hpp"
#include"Stage/SceneManager/Scene/Actor/Player/ItemNum/LifeDisplay.hpp"

namespace Game
{
	class ChoiceIcon;

	class StageSelect : GameLib::Actor
	{
		//座標からステージのデータであるstringとクリア状況を示すchar
		std::map<std::pair<int, int>, std::pair<std::vector<std::string>, unsigned char>> mStageData;

		//現在位置を表現
		ChoiceIcon* mChoiceIcon;

		StringDisplay mStageNameDisplay;
		StringDisplay mStageLevelDisplay;
		TearGemDisplay mTearGemDisplay;

		Stage::GemDisplay mGemDisplay;
		Stage::LifeDisplay mLifeDisplay;


	public:
		//2つのmapからmStageDataを作成しながらマップを描写していく
		StageSelect(GameLib::Actor*, 
			const std::map<std::pair<int, int>, unsigned char>&,
			const std::map<std::pair<int, int>, std::vector<std::string>>&,
			std::pair<int, int>&& nowPos,int lifeNum, int gemNum);

		void CustomizeUpdate() override;

		//Spaceが押されたときGameから呼び出される
		const std::pair<int,int>& GetChoicePos();


	private:
		const std::pair<int,int>& GetPairVecPerFrame();

		//posをチェックし有効な値の場合choiceIconの位置を変更、Displayの値を書きカエル
		void CheckposAndUpdateDisplay(std::pair<int,int>&& pos);

		//DisplayたちのAdjustPosを呼び出す
		void AdjustDisplayPos();

	};
}