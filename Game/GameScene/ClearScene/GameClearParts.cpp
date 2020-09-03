#include"GameClearParts.hpp"
#include"GameClearPartsParam.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"ClearSceneFlag.hpp"
#include"Stage/WindowSize.hpp"

namespace Game
{
	GameClearParts::GameClearParts(GameLib::Actor* actor)
		:ClearScenePartsBase{actor}
		, mRect{}
		, mThank{ "../Assets/Font/mplus-1c-black.ttf" }
		, mGameClear{ "../Assets/Font/mplus-1c-black.ttf" }
	{
		mGameClear.SetText("GAME CLEAR!!");
		mGameClear.SetSize(GameLib::Font::Size::Size_72);
		mGameClear.SetPosition(GameClearPartsParam::GAMECLAER_TEXT_POSITION);
		mGameClear.SetColor({ 255,255,255,255 });
		mGameClear.SetDrawOrder(1);

		mThank.SetText("Thank You For Playing !!");
		mThank.SetSize(GameLib::Font::Size::Size_24);
		mThank.SetPosition(GameClearPartsParam::THANK_TEXT_POSITION);
		mThank.SetColor({ 255,255,255,255 });
		mThank.SetDrawOrder(1);

		mRect.SetWidthAndHeight(Stage::WindowSize::WIDTH, Stage::WindowSize::HEIGHT);
		mRect.SetColor({ 0,0,0,255 });
		mRect.SetPosition({});
	}

	void GameClearParts::CustomizeUpdate()
	{
		if (GameLib::InputState::GetState(GameLib::Key::Space) == GameLib::ButtonState::Pressed)
			UpFlag(ClearSceneFlag::GO_IS_SAVE_FLAG);
	}
}