#include"Pause.hpp"
#include"Stage.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"SceneManager/StageSceneManager.hpp"

namespace Stage
{
	Pause::Pause(GameLib::Actor* stage, SceneManager* sceneManager)
		:GameLib::Actor{stage}
		, mSceneManager{sceneManager}
	{
		mSceneManager->SetState(GameLib::Actor::State::Pause);
	}
	void Pause::CustomizeUpdate()
	{
		//‰¼
		if (GameLib::InputState::GetState(GameLib::Key::P) == GameLib::ButtonState::Pressed) {
			mSceneManager->SetState(GameLib::Actor::State::Active);
			SetState(GameLib::Actor::State::Dead);
		}

		if (GameLib::InputState::GetState(GameLib::Key::T) == GameLib::ButtonState::Pressed) {
			auto stagePtr = static_cast<Stage*>(mOwner);
			stagePtr->ReturnToTitle();
			SetState(GameLib::Actor::State::Dead);
		}
			
	}
}