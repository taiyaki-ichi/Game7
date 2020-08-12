#include"LevelDisplay.hpp"
#include"Stage/WindowSize.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

namespace Game::StageSelect
{

	LevelDisplay::LevelDisplay(GameLib::Actor* actor)
		:GameLib::Actor{ actor }
		, mText{ "../Assets/Font/mplus-1c-black.ttf" }
	{
		mText.SetText("Level : -");
		mText.SetSize(GameLib::Font::Size::Size_36);
		mText.SetPosition({ 0.f,Stage::WindowSize::HEIGHT / 2.f - 50.f });
	}

	void LevelDisplay::SetLevelString(const std::string& str)
	{
		mText.SetText("Level : " + str);
	}

	void LevelDisplay::AdjustPos()
	{
		mText.SetPosition({ GameLib::Viewport::GetPos().x,Stage::WindowSize::HEIGHT / 2.f - 50.f });
	}

}