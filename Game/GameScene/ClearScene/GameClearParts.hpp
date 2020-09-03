#pragma once
#include"ClearScenePartsBase.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace Game
{
	class GameClearParts : public ClearScenePartsBase
	{
		GameLib::DrawRect mRect;
		GameLib::DrawFontText mGameClear;
		GameLib::DrawFontText mThank;

	public:
		GameClearParts(GameLib::Actor*);

		void CustomizeUpdate()override;
	};
}