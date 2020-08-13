#pragma once
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"

namespace Stage
{
	class LifeDisplay
	{
		GameLib::DrawTexture mTexture;
		GameLib::DrawFontText mNum;
		GameLib::DrawFontText mKakeru;

		GameLib::Vector2 mAdjustPos;

	public:
		LifeDisplay(const GameLib::Vector2&,int);
		virtual ~LifeDisplay() = default;

		void SetNum(int);

		void AdjustPos();
	};
}