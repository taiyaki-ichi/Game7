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
		mPlayer->ResetPotentialPower();
		mPrevWarp->GetOwner()->SetState(GameLib::Actor::State::Pause);

		mCircleCurtain.TurnDark(mPrevWarp->GetPosition());

		mNextWarp->PlayerWarpHere();

	}
	void SceneChanger::CustomizeUpdate()
	{

		if (mCircleCurtain.IsDark())
		{
			mCnt++;

			//1フレームだけ動かしてそれぞれの位置を更新
			if (mCnt == 1)
			{
				auto prevScenePtr = static_cast<Scene*>(mPrevWarp->GetOwner());
				prevScenePtr->BeginToRest();

				auto nextScenePtr = static_cast<Scene*>(mNextWarp->GetOwner());
				nextScenePtr->BeginWorking();

				//位置、カメラ、Itemの表示の順で更新
				mPlayer->SetPosition(mNextWarp->GetPosition());
				nextScenePtr->AdjustCameraPosiotion();
				mPlayer->AdjustItemDisplay();
			}
			else if (mCnt == 2)
			{
				auto nextScenePtr = static_cast<Scene*>(mNextWarp->GetOwner());
				nextScenePtr->SetState(GameLib::Actor::State::Pause);

				mPlayer->SetState(GameLib::Actor::State::Pause);
			}
			else if (mCnt > BLACK_TIME)
			{
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