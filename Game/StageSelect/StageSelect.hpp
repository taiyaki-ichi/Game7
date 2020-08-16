#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<unordered_map>
#include<vector>
#include<string>
#include"DataDisplay/StringDisplay.hpp"
#include"DataDisplay/TearGemDisplay.hpp"
#include"Stage/SceneManager/Scene/Actor/Player/ItemNum/GemDisplay.hpp"
#include"Stage/SceneManager/Scene/Actor/Player/ItemNum/LifeDisplay.hpp"
#include"HexVec.hpp"

namespace Stage
{
	class GemDisplay;
	class LifeDisplay;
}

namespace Game
{
	class ChoiceIcon;

	class StageSelect : public GameLib::Actor
	{
		//座標からステージのデータであるstringとクリア状況を示すchar
		std::unordered_map<HexVec, std::pair<std::vector<std::string>, unsigned char>> mStageData;

		//現在位置を表現
		ChoiceIcon* mChoiceIcon;

		StringDisplay mStageNameDisplay;
		StringDisplay mStageLevelDisplay;
		TearGemDisplay mTearGemDisplay;

		Stage::GemDisplay mGemDisplay;
		Stage::LifeDisplay mLifeDisplay;

		bool mChoiceIconStopFlag;

	public:
		//2つのmapからmStageDataを作成しながらマップを描写していく
		StageSelect(GameLib::Actor*, 
			const std::unordered_map<HexVec, unsigned char>&,
			const std::unordered_map<HexVec, std::vector<std::string>>&,
			const HexVec& nowPos,int lifeNum, int gemNum);

		void CustomizeUpdate() override;

		//Spaceが押されたときGameから呼び出される
		const HexVec& GetChoicePos()const;

		void ChoiceIconStop();


	private:
		const HexVec& GetPairVecPerFrame();

		//posをチェックし有効な値の場合choiceIconの位置を変更、Displayの値を書きカエル
		void CheckposAndUpdateDisplay(const HexVec& pos);

		//DisplayたちのAdjustPosを呼び出す
		void AdjustDisplayPos();

	};
}