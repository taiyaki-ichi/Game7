#pragma once
#include"GameSceneBase.hpp"
#include<unordered_map>
#include<vector>
#include<string>
#include"StageSelect/DataDisplay/StringDisplay.hpp"
#include"StageSelect/DataDisplay/TearGemDisplay.hpp"
#include"Stage/SceneManager/Scene/Actor/Player/ItemNum/GemDisplay.hpp"
#include"Stage/SceneManager/Scene/Actor/Player/ItemNum/LifeDisplay.hpp"
#include"Utility/HexVec.hpp"
#include"GameData.hpp"

namespace Game
{
	class ChoiceIcon;

	class StageSelect : public SceneBase
	{
		//ステージの情報、これをもとにマップを表示
		const std::unordered_map<HexVec, std::vector<std::string>> mStageData;

		//現在位置を表現
		ChoiceIcon* mChoiceIcon;

		StringDisplay mStageNameDisplay;
		StringDisplay mStageLevelDisplay;
		TearGemDisplay mTearGemDisplay;

		::Stage::GemDisplay mGemDisplay;
		::Stage::LifeDisplay mLifeDisplay;

	public:
		//GameDataのほかにStageDataをGameからもらう
		StageSelect(GameLib::Actor*,const GameData&,
			const std::unordered_map<HexVec, std::vector<std::string>>&);

		void CustomizeUpdate() override;


	private:
		const HexVec& GetPairVecPerFrame();

		//posをチェックし有効な値の場合choiceIconの位置を変更、Displayの値を書きカエル
		void CheckposAndUpdateDisplay(const HexVec&);

		//DisplayたちのAdjustPosを呼び出す
		void AdjustDisplayPos();

		//Stageに移動かSaveするかとかの処理
		void PressedSpace();

	};
}