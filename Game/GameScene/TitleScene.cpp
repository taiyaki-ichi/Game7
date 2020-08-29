#include"TitleScene.hpp"
#include"TitleScene/TitleSceneParam.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameSceneFlag.hpp"

namespace Game
{
	TitleScene::TitleScene(GameLib::Actor* actor,const GameData& gameData)
		:SceneBase{actor,gameData}
		, mButtonA{}
		, mButtonD{}
		, mCursorPos{CursorPos::ButtonA}
	{
		using namespace TitleSceneParam;

		//Cursor‚ÍÅ‰A‚ÌˆÊ’u

		mButtonA.SetWidthAndHeightAndFlameWidth(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_FLAME_WIDTH);
		mButtonA.SetPosition(A_BUTTON_ADJUST);
		mButtonA.ChangeDark();

		mButtonD.SetWidthAndHeightAndFlameWidth(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_FLAME_WIDTH);
		mButtonD.SetPosition(D_BUTTON_ADJUST);
		mButtonD.ChangeWhite();
	}

	void TitleScene::CustomizeUpdate()
	{

		if (GameLib::InputState::GetState(GameLib::Key::Space) == GameLib::ButtonState::Pressed)
		{
			if (mCursorPos == CursorPos::ButtonA)
				UpFlag(SceneFlag::GO_STAGESELECT_FLAG);
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
		}

		//A->D
		if ((GameLib::InputState::GetState(GameLib::Key::D) == GameLib::ButtonState::Pressed) &&
			(mCursorPos == CursorPos::ButtonA))
		{
			mCursorPos = CursorPos::ButtonD;
			mButtonA.ChangeWhite();
			mButtonD.ChangeDark();
		}

	}

}