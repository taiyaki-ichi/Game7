#pragma once
#include"GameSceneBase.hpp"
#include"TitleScene/SelectButton.hpp"
#include"TitleScene/CursorPos.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"
#include"TitleScene/TitleLogo.hpp"

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

	public:
		TitleScene(GameLib::Actor*,const GameData&);

		void CustomizeUpdate() override;
	};
}