#include"FromZeroTitleScene.hpp"
#include"TitleScene/FromZeroTitleSceneParam.hpp"
#include"Stage/Utilty/Kakko.hpp"
#include"TitleScene/TitleSceneParam.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameSceneFlag.hpp"

namespace Game
{
	FromZeroTitleScene::FromZeroTitleScene(GameLib::Actor* actor,const GameData& data)
		:SceneBase{actor,data}
		, mButton{FromZeroTitleSceneParam::BUTTON_POSITION}
		, mKakko{nullptr}
		, mPressSpace{ "../Assets/Font/mplus-1c-black.ttf" }
		, mTitleLogo{ TitleSceneParam::TITLELOGO_POS }
	{

		mButton.SetWidthAndHeightAndFlameWidth(TitleSceneParam::BUTTON_WIDTH, TitleSceneParam::BUTTON_HEIGHT, TitleSceneParam::BUTTON_FLAME_WIDTH);
		mButton.ChangeDark();
		mButton.SetText("‚Í‚¶‚ß‚©‚ç");
		mButton.SetLifeAndGemNum(START_GAMEDATA.mPlayerLifeNum, START_GAMEDATA.mPlayerGemNum);

		mKakko = new Stage::Kakko{ this };
		mKakko->SetWidthAndHeight(TitleSceneParam::BUTTON_WIDTH + TitleSceneParam::KAKKO_ADJUST, TitleSceneParam::BUTTON_HEIGHT + TitleSceneParam::KAKKO_ADJUST);
		mKakko->SetPosition(FromZeroTitleSceneParam::BUTTON_POSITION);
		mKakko->SetMoveLength(TitleSceneParam::KAKKO_MOVE_LENGTH);
		mKakko->SetTextureScale(TitleSceneParam::KAKKO_TEXTURE_SCALE);

		mPressSpace.SetText("Press Space");
		mPressSpace.SetSize(GameLib::Font::Size::Size_18);
		mPressSpace.SetPosition(FromZeroTitleSceneParam::PRESSSPACE_TEXT_POSITION);
	}

	void FromZeroTitleScene::CustomizeUpdate()
	{
		if (GameLib::InputState::GetState(GameLib::Key::Space) == GameLib::ButtonState::Pressed)
			UpFlag(SceneFlag::GO_STAGESELECT_FROM_TITLE_FLAG);
	}


}