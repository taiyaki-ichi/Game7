#include"Pause.hpp"
#include"Stage.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"SceneManager/StageSceneManager.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Utilty/CursorButton.hpp"

namespace Stage
{
	Pause::Pause(GameLib::Actor* stage, SceneManager* sceneManager)
		:GameLib::Actor{stage}
		, mSceneManager{sceneManager}
		, mFlameRect{50}
		, mText{ "../Assets/Font/mplus-1c-black.ttf" }
	{
		mSceneManager->SetState(GameLib::Actor::State::Pause);
		mFlameRect.SetWidthAndHeight(500.f, 400.f);
		mFlameRect.SetPosition(GameLib::Viewport::GetPos());
		mFlameRect.SetFlameWidth(20.f);

		mText.SetText("aaa\naaaa\naaaaa\n");
		mText.SetPosition(GameLib::Viewport::GetPos());
		mText.SetDrawOrder(51);

		auto ptr = new CursorButton{ this,60 };
		ptr->SetWidthAndHeight(50.f, 50.f);
		ptr->SetPosition(GameLib::Viewport::GetPos());
	}
	void Pause::CustomizeUpdate()
	{
		//‰¼
		if( (GameLib::InputState::GetState(GameLib::Key::Q) == GameLib::ButtonState::Pressed)||
			(GameLib::InputState::GetState(GameLib::Key::P) == GameLib::ButtonState::Pressed) ){
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