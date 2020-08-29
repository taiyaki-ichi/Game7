#pragma once
#include"GameSceneBase.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"

namespace Game
{
	class GameOverScene : public SceneBase
	{
		GameLib::DrawRect mRect;
		GameLib::DrawFontText mText;

	public:
		GameOverScene(GameLib::Actor*, const GameData&);

		void CustomizeUpdate() override;
	};
}