#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"
#include<vector>
#include<array>
#include<string>

namespace Game::Stage
{
	namespace Player {
		class Actor;
	}
	namespace BackGround {
		class SlideObjectBase;
	}
}

namespace Game::StageSelect
{
	constexpr int STAGE_NUM = 3;
	constexpr int STAGE_CHANGE_TIME = 30;
	constexpr int COURCE_NUM = 5;
	
	class WarpBox;
	class StageNumChangeBox;

	using StageWarpBoxs = std::vector<WarpBox*>;
	using BackGrounds = std::vector<Stage::BackGround::SlideObjectBase*>;

	//ゲームの進捗をロードしたり
	class StageSelect : public GameLib::Actor
	{
		std::vector<BackGrounds> mBackGround;
		std::vector<StageWarpBoxs> mStageWarpBox;

		std::array<GameLib::DrawFontText, COURCE_NUM> mNums;

		StageNumChangeBox* mStageNumChangeBox;

		int mGoStageFlag;

		Stage::Player::Actor* mPlayer;


	public:
		StageSelect(GameLib::Actor* owner);
		virtual ~StageSelect() = default;

		//GoStageFlagが0以外の有効な値ならばそのStageへ移動
		void CustomizeUpdate() override;

		void GoStage(int stageNum);

		void ChangeStageNum(int num);
	};


}