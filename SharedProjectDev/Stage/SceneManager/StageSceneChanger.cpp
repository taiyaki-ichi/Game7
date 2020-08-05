#include"StageSceneChanger.hpp"
#include"Scene/Actor/Player.hpp"
#include"Scene/Actor/WarpBase.hpp"
#include"Scene/StageScene.hpp"

namespace Stage
{
	SceneChanger::SceneChanger(GameLib::Actor* stageSceneManager, Player* player, WarpBase* prev, WarpBase* next)
		:GameLib::Actor{stageSceneManager}
		, mPlayer{player}
		, mPrevWarp{prev}
		, mNextWarp{next}
		, mCircleCurtain{}
		, mCnt{0}
	{
		mPlayer->SetState(GameLib::Actor::State::Pause);
		mPrevWarp->GetOwner()->SetState(GameLib::Actor::State::Pause);

		mCircleCurtain.TurnDark(mPrevWarp->GetPosition());

		mNextWarp->PlayerWarpHere();

	}
	void SceneChanger::CustomizeUpdate()
	{

		if (mCircleCurtain.IsDark())
		{
			mCnt++;

			if (mCnt > BLACK_TIME)
			{

				auto prevScenePtr = static_cast<Scene*>(mPrevWarp->GetOwner());
				prevScenePtr->BeginToRest();

				auto nextScenePtr = static_cast<Scene*>(mNextWarp->GetOwner());
				nextScenePtr->BeginWorking();
				nextScenePtr->SetState(GameLib::Actor::State::Pause);

				mPlayer->SetPosition(mNextWarp->GetPosition());
				mPlayer->SetState(GameLib::Actor::State::Pause);

				nextScenePtr->AdjustCameraPosiotion();

				mCircleCurtain.TurnBright(mNextWarp->GetPosition());
			}
		}

		if (mCircleCurtain.IsBright())
		{
			auto nextScenePtr = static_cast<Scene*>(mNextWarp->GetOwner());
			nextScenePtr->SetState(GameLib::Actor::State::Active);

			mPlayer->SetState(GameLib::Actor::State::Active);

			SetState(GameLib::Actor::State::Dead);
		}

		mCircleCurtain.Update();
	}
}