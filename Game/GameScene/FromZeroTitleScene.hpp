#pragma once
#include"GameSceneBase.hpp"
#include"TitleScene/SelectButton.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"
#include"TitleScene/TitleLogo.hpp"

namespace Stage
{
	class Kakko;
}

namespace Game
{
	//class Kakko;

	class FromZeroTitleScene : public SceneBase
	{
		Button mButton;

		Stage::Kakko* mKakko;

		GameLib::DrawFontText mPressSpace;

		TitleLogo mTitleLogo;

	public:
		FromZeroTitleScene(GameLib::Actor*, const GameData&);

		void CustomizeUpdate() override;
	};
}