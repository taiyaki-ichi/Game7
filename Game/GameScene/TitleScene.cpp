#include"TitleScene.hpp"
#include"TitleScene/TitleSceneParam.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameSceneFlag.hpp"
#include"Stage/Utilty/Kakko.hpp"

namespace Game
{
	TitleScene::TitleScene(GameLib::Actor* actor,const GameData& gameData,int starNum)
		:SceneBase{actor,gameData}
		, mButtonA{TitleSceneParam::A_BUTTON_ADJUST}
		, mButtonD{TitleSceneParam::D_BUTTON_ADJUST}
		, mCursorPos{CursorPos::ButtonA}
		, mA{ "../Assets/Font/mplus-1c-black.ttf" }
		, mD{ "../Assets/Font/mplus-1c-black.ttf" }
		, mKakko{nullptr}
		, mTitleLogo{TitleSceneParam::TITLELOGO_POS}
		, mStarDisplay{1}
	{
		using namespace TitleSceneParam;

		//Cursor‚ÍÅ‰A‚ÌˆÊ’u

		mButtonA.SetWidthAndHeightAndFlameWidth(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_FLAME_WIDTH);
		mButtonA.ChangeDark();
		mButtonA.SetText("‚Â‚Ã‚«‚©‚ç");
		mButtonA.SetLifeAndGemNum(mGameData.mPlayerLifeNum, mGameData.mPlayerGemNum);

		mButtonD.SetWidthAndHeightAndFlameWidth(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_FLAME_WIDTH);
		mButtonD.ChangeWhite();
		mButtonD.SetText("‚Í‚¶‚ß‚©‚ç");
		mButtonD.SetLifeAndGemNum(START_GAMEDATA.mPlayerLifeNum, START_GAMEDATA.mPlayerGemNum);

		mA.SetPosition(A_BUTTON_ADJUST + BUTTON_STRING_TAG_ADJUST);
		mA.SetText("A");
		mA.SetSize(GameLib::Font::Size::Size_36);

		mD.SetPosition(D_BUTTON_ADJUST + BUTTON_STRING_TAG_ADJUST);
		mD.SetText("D");
		mD.SetSize(GameLib::Font::Size::Size_36);

		mKakko = new Stage::Kakko{ this };
		mKakko->SetWidthAndHeight(BUTTON_WIDTH + KAKKO_ADJUST, BUTTON_HEIGHT + KAKKO_ADJUST);
		mKakko->SetPosition(A_BUTTON_ADJUST);
		mKakko->SetMoveLength(KAKKO_MOVE_LENGTH);
		mKakko->SetTextureScale(KAKKO_TEXTURE_SCALE);

		mStarDisplay.SetPosition(A_BUTTON_ADJUST + STAR_DISPLAY_ADJUST);
		mStarDisplay.SetStarNum(starNum);

	}

	void TitleScene::CustomizeUpdate()
	{

		if (GameLib::InputState::GetState(GameLib::Key::Space) == GameLib::ButtonState::Pressed)
		{
			if (mCursorPos == CursorPos::ButtonA)
				UpFlag(SceneFlag::GO_STAGESELECT_FROM_TITLE_FLAG);
			else if (mCursorPos == CursorPos::ButtonD)
				UpFlag(SceneFlag::GO_STAGESELECT_FROM_ZERO_FLAG);
		}

		//D->A
		if ((GameLib::InputState::GetState(GameLib::Key::A) == GameLib::ButtonState::Pressed)&&
			(mCursorPos==CursorPos::ButtonD))
		{
			mCursorPos = CursorPos::ButtonA;
			mButtonD.ChangeWhite();
			mButtonA.ChangeDark();
			mKakko->SetPosition(TitleSceneParam::A_BUTTON_ADJUST);
		}

		//A->D
		if ((GameLib::InputState::GetState(GameLib::Key::D) == GameLib::ButtonState::Pressed) &&
			(mCursorPos == CursorPos::ButtonA))
		{
			mCursorPos = CursorPos::ButtonD;
			mButtonA.ChangeWhite();
			mButtonD.ChangeDark();
			mKakko->SetPosition(TitleSceneParam::D_BUTTON_ADJUST);
		}

		
	}

}