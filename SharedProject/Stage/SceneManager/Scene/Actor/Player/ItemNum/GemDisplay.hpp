#pragma once
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"

namespace Stage
{
	class GemDisplay
	{
		GameLib::DrawTexture mTexture;
		GameLib::DrawFontText mNum;
		GameLib::DrawFontText mKakeru;

		GameLib::Vector2 mAdjustPos;

	public:
		GemDisplay(const GameLib::Vector2&,int);
		virtual ~GemDisplay() = default;

		void SetNum(int);

		void AdjustPos();
	};
}