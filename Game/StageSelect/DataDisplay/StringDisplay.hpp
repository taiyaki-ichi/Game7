#pragma once
#include"GameLib/include/Draw/DrawFontText.hpp"

namespace Game
{
	class StringDisplay
	{
		GameLib::DrawFontText mText;
		GameLib::Vector2 mAdjustVec;

	public:
		StringDisplay(const GameLib::Vector2&, GameLib::Font::Size&&);
		virtual ~StringDisplay() = default;

		void SetText(const std::string& level);
		void AdjustPos();
	};
}