#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace Stage
{
	class WarpBase; 
	class Player;

	class SceneChanger : public GameLib::Actor
	{
		WarpBase* mPrevWarp;
		WarpBase* mNextWarp;

		Player* mPlayer;

		int mCnt;

		constexpr static int CHANGE_TIME = 60;

	public:
		SceneChanger(GameLib::Actor* stageSceneManager,Player* player, WarpBase* prev,WarpBase* next);
		virtual ~SceneChanger() = default;

		void CustomizeUpdate() override;

	};
}