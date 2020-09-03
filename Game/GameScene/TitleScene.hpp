#pragma once
#include"GameSceneBase.hpp"
#include"TitleScene/SelectButton.hpp"
#include"TitleScene/CursorPos.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"
#include"TitleScene/TitleLogo.hpp"
#include"TitleScene/StarDisplay.hpp"

namespace Stage
{
	class Kakko;
}

namespace Game
{
	//class Kakko;

	class TitleScene : public SceneBase
	{
		Button mButtonA;
		Button mButtonD;

		CursorPos mCursorPos;

		GameLib::DrawFontText mA;
		GameLib::DrawFontText mD;

		Stage::Kakko* mKakko;

		TitleLogo mTitleLogo;

		StarDisplay mStarDisplay;

	public:
		TitleScene(GameLib::Actor*, const GameData&, int starNum);

		void CustomizeUpdate() override;
	};
}