#include"GameOverScene.hpp"
#include"Stage/WindowSize.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameSceneFlag.hpp"

namespace Game
{
	GameOverScene::GameOverScene(GameLib::Actor* actor,const GameData& gameData)
		:SceneBase{actor,gameData}
		, mText{ "../Assets/Font/mplus-1c-black.ttf" }
		, mRect{}
	{
		mRect.SetWidthAndHeight(Stage::WindowSize::WIDTH, Stage::WindowSize::HEIGHT);
		mRect.SetColor({ 0,0,0,255 });
		mRect.SetPosition({ 0.f,0.f });

		mText.SetText("GAME OVER");
		mText.SetColor({ 255,255,255,255 });
		mText.SetDrawOrder(1);
		mText.SetPosition({ 0.f,0.f });
		mText.SetSize(GameLib::Font::Size::Size_72);
	}

	void GameOverScene::CustomizeUpdate()
	{
		if (GameLib::InputState::GetState(GameLib::Key::Space) == GameLib::ButtonState::Pressed)
			UpFlag(SceneFlag::GO_STAGESELECT_FLAG);
	}
}