#include"Pause.hpp"
#include"Stage.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"SceneManager/StageSceneManager.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"


namespace Stage
{
	Pause::Pause(GameLib::Actor* stage, SceneManager* sceneManager)
		:GameLib::Actor{stage}
		, mSceneManager{sceneManager}
		, mFlameRect{50}
	{
		mSceneManager->SetState(GameLib::Actor::State::Pause);
		mFlameRect.SetWidthAndHeight(400.f, 300.f);
		mFlameRect.SetPosition(GameLib::Viewport::GetPos());
		mFlameRect.SetFlameWidth(10.f);
	}
	void Pause::CustomizeUpdate()
	{
		//‰¼
		if (GameLib::InputState::GetState(GameLib::Key::Q) == GameLib::ButtonState::Pressed) {
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