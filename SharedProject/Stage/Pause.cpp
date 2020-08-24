#include"Pause.hpp"
#include"Stage.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"SceneManager/StageSceneManager.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Utilty/CursorButton.hpp"
#include"Pause/PauseParam.h"

namespace Stage
{
	Pause::Pause(GameLib::Actor* stage, SceneManager* sceneManager)
		:GameLib::Actor{stage}
		, mSceneManager{sceneManager}
		, mFlameRect{50}
		, mResumeButton{nullptr}
		, mResumeText{ "../Assets/Font/mplus-1c-black.ttf" }
		, mReturnStageSelectButton{nullptr}
		, mReturnStageSelectText{ "../Assets/Font/mplus-1c-black.ttf" }
	{
		mSceneManager->SetState(GameLib::Actor::State::Pause);


		mFlameRect.SetWidthAndHeight(PauseParam::WINDOW_WIDTH, PauseParam::WINDOW_HEIGHT);
		mFlameRect.SetPosition(GameLib::Viewport::GetPos());
		mFlameRect.SetFlameWidth(PauseParam::WINDOW_FLAME_WIDTH);

		mResumeButton = new CursorButton{ this,60 };
		mResumeButton->SetWidthAndHeight(PauseParam::BUTTON_WIDTH, PauseParam::BUTTON_HEIGHT);
		mResumeButton->SetPosition(GameLib::Viewport::GetPos() + PauseParam::RESUME_BUTTON_ADJUST);

		mResumeText.SetText("ゲームに戻る");
		mResumeText.SetPosition(GameLib::Viewport::GetPos() + PauseParam::RESUME_BUTTON_ADJUST);
		mResumeText.SetDrawOrder(62);

		mReturnStageSelectButton = new CursorButton{ this,60 };
		mReturnStageSelectButton->SetWidthAndHeight(PauseParam::BUTTON_WIDTH, PauseParam::BUTTON_HEIGHT);
		mReturnStageSelectButton->SetPosition(GameLib::Viewport::GetPos() + PauseParam::RETURN_TITLE_BUTTON_ADJUST);

		mReturnStageSelectText.SetText("セレクトに戻る");
		mReturnStageSelectText.SetPosition(GameLib::Viewport::GetPos() + PauseParam::RETURN_TITLE_BUTTON_ADJUST);
		mReturnStageSelectText.SetDrawOrder(62);

	}
	void Pause::CustomizeUpdate()
	{
		if (GameLib::InputState::GetState(GameLib::Key::P) == GameLib::ButtonState::Pressed) {
			mSceneManager->SetState(GameLib::Actor::State::Active);
			SetState(GameLib::Actor::State::Dead);
		}

		if (mResumeButton->IsClicked())
		{
			mSceneManager->SetState(GameLib::Actor::State::Active);
			SetState(GameLib::Actor::State::Dead);
		}

		if (mReturnStageSelectButton->IsClicked())
		{
			mSceneManager->ReturnStageSelect();
		}
	}
}