#pragma once
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Stage
{
	class TearDisplay
	{
		GameLib::DrawTexture mTexture1;
		GameLib::DrawTexture mTexture2;
		GameLib::DrawTexture mTexture3;

		GameLib::Vector2 mAdjustPos;

	public:
		TearDisplay(const GameLib::Vector2&);
		virtual ~TearDisplay() = default;

		void Get(int);

		void AdjustPos();
	};
}