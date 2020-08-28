#pragma once
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Game
{
	class TearGemDisplay
	{
		GameLib::DrawTexture mTexture1;
		GameLib::DrawTexture mTexture2;
		GameLib::DrawTexture mTexture3;

		GameLib::Vector2 mAdjustPos;

	public:
		TearGemDisplay(const GameLib::Vector2&);
		virtual ~TearGemDisplay() = default;

		//何も表示しない
		void NotDrawing();

		//すべてのてくすちゃをフレームにセット
		void SetFrame();

		void SetTearGem(int);

		void AdjustPos();
	};


}