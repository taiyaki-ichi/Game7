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
	{
		mPlayer->SetState(GameLib::Actor::State::Pause);
		mPrevWarp->GetOwner()->SetState(GameLib::Actor::State::Pause);

		mPrevWarp->SetBright();
		mPrevWarp->ChangeLight();
		mNextWarp->SetBright();
	}
	void SceneChanger::CustomizeUpdate()
	{
		if (mPrevWarp->GetLightState() == WarpBase::LightState::Dark&&mNextWarp->GetLightState()==WarpBase::LightState::Dark) {
			auto prevScenePtr = static_cast<Scene*>(mPrevWarp->GetOwner());
			prevScenePtr->SetState(GameLib::Actor::State::Active);
			prevScenePtr->Pause();

			auto nextScenePtr = static_cast<Scene*>(mNextWarp->GetOwner());
			nextScenePtr->Active();
			nextScenePtr->SetState(GameLib::Actor::State::Pause);

			mPrevWarp->SetBright();

			mPlayer->SetPosition(mNextWarp->GetPosiotion());
		}

		if (mPrevWarp->GetLightState() == WarpBase::LightState::Bright && mNextWarp->GetLightState() == WarpBase::LightState::Bright) {
			auto nextScenePtr = static_cast<Scene*>(mNextWarp->GetOwner());
			nextScenePtr->SetState(GameLib::Actor::State::Active);

			mPlayer->SetState(GameLib::Actor::State::Active);

			SetState(GameLib::Actor::State::Dead);

		}


	}
}