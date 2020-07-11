#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace Game::Stage
{
	class Stage;
	class Scene;
	class WarpBase;
	class CurtainBase;

	class ChangeScene : public GameLib::Actor
	{
		Scene* mPrevScene;
		WarpBase* mNextWarpBase;

		std::unique_ptr<CurtainBase> mCurtain;

		constexpr static int BLACK_TINE = 30;
		int mCnt;

	public:
		ChangeScene(Stage* stage, Scene* prevScene, WarpBase* nextWapeGate);
		virtual ~ChangeScene() = default;

		void CustomizeUpdate();
	};

}