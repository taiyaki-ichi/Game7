#include"Pause.hpp"
#include"Stage.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"SceneManager/StageSceneManager.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Pause/PauseParam.hpp"
#include"SceneManager/SceneManagerFlag.hpp"
#include"Utilty/Kakko.hpp"

namespace Stage
{
	Pause::Pause(GameLib::Actor* stage, SceneManager* sceneManager)
		:GameLib::Actor{stage}
		, mSceneManager{sceneManager}
		, mFlameRect{50}
		, mResumeButton{PauseParam::RESUME_BUTTON_ADJUST+GameLib::Viewport::GetPos(),60}
		, mResumeText{ "../Assets/Font/mplus-1c-black.ttf" }
		, mReturnStageSelectButton{PauseParam::RETURN_TITLE_BUTTON_ADJUST+GameLib::Viewport::GetPos(),60}
		, mReturnStageSelectText{ "../Assets/Font/mplus-1c-black.ttf" }
		, mPosition{Position::Resume}
		, mKakko{nullptr}
		, mPauseText{ "../Assets/Font/mplus-1c-black.ttf" }
		, mA{ "../Assets/Font/mplus-1c-black.ttf" }
		, mD{ "../Assets/Font/mplus-1c-black.ttf" }
	{
		mSceneManager->SetState(GameLib::Actor::State::Pause);

		using namespace PauseParam;

		mFlameRect.SetWidthAndHeight(WINDOW_WIDTH, WINDOW_HEIGHT);
		mFlameRect.SetPosition(GameLib::Viewport::GetPos());
		mFlameRect.SetFlameWidth(WINDOW_FLAME_WIDTH);

		mResumeButton.SetWidthAndHeightAndFlameWidth(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_FLAMEWIDTH);
		mResumeButton.ChangeDark();

		mResumeText.SetText("ゲームに戻る");
		mResumeText.SetPosition(GameLib::Viewport::GetPos() + PauseParam::RESUME_BUTTON_ADJUST);
		mResumeText.SetDrawOrder(62);

		mReturnStageSelectButton.SetWidthAndHeightAndFlameWidth(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_FLAMEWIDTH);
		mReturnStageSelectButton.ChangeWhite();

		mReturnStageSelectText.SetText("セレクトに戻る");
		mReturnStageSelectText.SetPosition(GameLib::Viewport::GetPos() + PauseParam::RETURN_TITLE_BUTTON_ADJUST);
		mReturnStageSelectText.SetDrawOrder(62);

		mKakko = new Kakko{ this ,65};
		mKakko->SetTextureScale(KAKKO_TEXTURE_SCALE);
		mKakko->SetMoveLength(KAKKO_MOVE_LENGTH);
		mKakko->SetWidthAndHeight(KAKKO_WIDTH, KAKKO_HEIGHT);
		mKakko->SetPosition(mResumeButton.GetPosition());

		mPauseText.SetText("ポーズ");
		mPauseText.SetSize(GameLib::Font::Size::Size_36);
		mPauseText.SetPosition(PauseParam::PAUSE_TEXT_ADJUST + GameLib::Viewport::GetPos());
		mPauseText.SetDrawOrder(65);

		mA.SetText("A");
		mA.SetDrawOrder(65);
		mA.SetPosition(mResumeButton.GetPosition() + BUTTON_KEY_TEXT_ADJUST);

		mD.SetText("D");
		mD.SetDrawOrder(65);
		mD.SetPosition(mReturnStageSelectButton.GetPosition() + BUTTON_KEY_TEXT_ADJUST);

	}
	void Pause::CustomizeUpdate()
	{
		//Pが押されるとPauseが生成されるため、重複しないようにする処理
		if (GameLib::InputState::GetState(GameLib::Key::P) == GameLib::ButtonState::Pressed) {
			mSceneManager->SetState(GameLib::Actor::State::Active);
			SetState(GameLib::Actor::State::Dead);
		}

		if (!mSceneManager->CheckFlag(SceneManagerFlag::RETURN_STAGESELECT_FLAG) && mPosition==Position::Resume&&
			GameLib::InputState::GetState(GameLib::Key::Space)==GameLib::ButtonState::Pressed)
		{
			mSceneManager->SetState(GameLib::Actor::State::Active);
			SetState(GameLib::Actor::State::Dead);
		}

		if (mPosition==Position::ReturnSelect&&GameLib::InputState::GetState(GameLib::Key::Space)==GameLib::ButtonState::Pressed)
		{
			mSceneManager->ReturnStageSelect();
		}

		if (mPosition == Position::Resume && GameLib::InputState::GetState(GameLib::Key::D) == GameLib::ButtonState::Pressed)
		{
			mResumeButton.ChangeWhite();
			mReturnStageSelectButton.ChangeDark();
			mKakko->SetPosition(mReturnStageSelectButton.GetPosition());
			mPosition = Position::ReturnSelect;
		}

		if (mPosition == Position::ReturnSelect && GameLib::InputState::GetState(GameLib::Key::A) == GameLib::ButtonState::Pressed)
		{
			mReturnStageSelectButton.ChangeWhite();
			mResumeButton.ChangeDark();
			mKakko->SetPosition(mResumeButton.GetPosition());
			mPosition = Position::Resume;
		}

		/*
		if (!mSceneManager->CheckFlag(SceneManagerFlag::RETURN_STAGESELECT_FLAG) && mResumeButton->IsClicked())
		{
			mSceneManager->SetState(GameLib::Actor::State::Active);
			SetState(GameLib::Actor::State::Dead);
		}

		if (mReturnStageSelectButton->IsClicked())
		{
			mSceneManager->ReturnStageSelect();
		}
		*/
	}
}