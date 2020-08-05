#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"StageSceneChanger/CircleCurtain.hpp"

namespace Stage
{
	class WarpBase; 
	class Player;

	class SceneChanger : public GameLib::Actor
	{
		WarpBase* mPrevWarp;
		WarpBase* mNextWarp;

		Player* mPlayer;

		CircleCurtain mCircleCurtain;

		constexpr static int CHANGE_TIME = 60;
		constexpr static int BLACK_TIME = 30;
		int mCnt;

	public:
		SceneChanger(GameLib::Actor* stageSceneManager,Player* player, WarpBase* prev,WarpBase* next);
		virtual ~SceneChanger() = default;

		void CustomizeUpdate() override;

	};
}