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

	int Pause::mNum = 0;

	Pause::Pause(GameLib::Actor* stage, SceneManager* sceneManager)
		:GameLib::Actor{stage}
		, mSceneManager{sceneManager}
		, mFlameRect{250}
		, mResumeButton{260}
		, mResumeText{ "../Assets/Font/mplus-1c-black.ttf" }
		, mReturnStageSelectButton{260}
		, mReturnStageSelectText{ "../Assets/Font/mplus-1c-black.ttf" }
		, mPosition{Position::Resume}
		, mKakko{nullptr}
		, mPauseText{ "../Assets/Font/mplus-1c-black.ttf" }
		, mA{ "../Assets/Font/mplus-1c-black.ttf" }
		, mD{ "../Assets/Font/mplus-1c-black.ttf" }
	{
		mSceneManager->SetState(GameLib::Actor::State::Pause);

		using namespace PauseParam;

		float rot = GameLib::Viewport::GetRotation();

		using GameLib::Vector2;

		mFlameRect.SetWidthAndHeight(WINDOW_WIDTH, WINDOW_HEIGHT);
		mFlameRect.SetPosition(Vector2::Rotation(GameLib::Viewport::GetPos(),rot));
		mFlameRect.SetFlameWidth(WINDOW_FLAME_WIDTH);
		mFlameRect.SetRotation(rot);

		mResumeButton.SetWidthAndHeightAndFlameWidth(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_FLAMEWIDTH);
		mResumeButton.ChangeDark();
		mResumeButton.SetPosition(Vector2::Rotation(PauseParam::RESUME_BUTTON_ADJUST + GameLib::Viewport::GetPos(), rot));
		mResumeButton.SetRotation(rot);

		mResumeText.SetText("ゲームに戻る");
		mResumeText.SetPosition(Vector2::Rotation(GameLib::Viewport::GetPos() + PauseParam::RESUME_BUTTON_ADJUST, rot));
		mResumeText.SetDrawOrder(262);

		mReturnStageSelectButton.SetWidthAndHeightAndFlameWidth(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_FLAMEWIDTH);
		mReturnStageSelectButton.ChangeWhite();
		mReturnStageSelectButton.SetPosition(Vector2::Rotation(PauseParam::RETURN_TITLE_BUTTON_ADJUST + GameLib::Viewport::GetPos(), rot));
		mReturnStageSelectButton.SetRotation(rot);

		mReturnStageSelectText.SetText("セレクトに戻る");
		mReturnStageSelectText.SetPosition(Vector2::Rotation(GameLib::Viewport::GetPos() + PauseParam::RETURN_TITLE_BUTTON_ADJUST, rot));
		mReturnStageSelectText.SetDrawOrder(262);

		mKakko = new Kakko{ this ,265};
		mKakko->SetTextureScale(KAKKO_TEXTURE_SCALE);
		mKakko->SetMoveLength(KAKKO_MOVE_LENGTH);
		mKakko->SetWidthAndHeight(KAKKO_WIDTH, KAKKO_HEIGHT);
		mKakko->SetPosition(mResumeButton.GetPosition());
		mKakko->SetRotation(rot);

		mPauseText.SetText("ポーズ");
		mPauseText.SetSize(GameLib::Font::Size::Size_36);
		mPauseText.SetPosition(Vector2::Rotation(PauseParam::PAUSE_TEXT_ADJUST + GameLib::Viewport::GetPos(), rot));
		mPauseText.SetDrawOrder(265);

		mA.SetText("A");
		mA.SetDrawOrder(265);
		mA.SetPosition(mResumeButton.GetPosition() + Vector2::Rotation(BUTTON_KEY_TEXT_ADJUST, rot));

		mD.SetText("D");
		mD.SetDrawOrder(265);
		mD.SetPosition(mReturnStageSelectButton.GetPosition() + Vector2::Rotation(BUTTON_KEY_TEXT_ADJUST, rot));

		mNum++;

	}

	Pause::~Pause()
	{
		mNum--;
	}

	void Pause::CustomizeUpdate()
	{

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

	}

	int Pause::GetNum()
	{
		return mNum;
	}
}