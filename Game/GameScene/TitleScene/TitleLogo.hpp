#pragma once
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"

namespace Game
{
	class TitleLogo
	{
		GameLib::DrawTexture mIcon;
		GameLib::DrawFontText mEngText;
		GameLib::DrawFontText mJpnText;

	public:
		TitleLogo(const GameLib::Vector2&);
	};
}