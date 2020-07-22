#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<vector>
#include<array>
#include<string>

namespace Game::Stage::Player
{
	class Actor;
}

namespace Game::StageSelect
{
	class WarpBox;
	class StageNumChangeBox;

	using StageWarpBoxs = std::vector<WarpBox*>;

	//ゲームの進捗をロードしたり
	class StageSelect : public GameLib::Actor
	{
		//std::vector<BackGrounds> mBackGround;
		std::vector<StageWarpBoxs> mStageWarpBox;

		StageNumChangeBox* mStageNumChangeBox;

		int mGoStageFlag;

		Stage::Player::Actor* mPlayer;

	public:
		StageSelect(GameLib::Actor* owner);
		virtual ~StageSelect() = default;

		//GoStageFlagが0以外の有効な値ならばそのStageへ移動
		void CustomizeUpdate() override;

		void GoStage(int stageNum);
	};


}