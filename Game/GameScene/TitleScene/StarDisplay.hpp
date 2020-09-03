#pragma once
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Game
{
	class StarDisplay
	{
		GameLib::DrawTexture mTexture1;
		GameLib::DrawTexture mTexture2;
		GameLib::DrawTexture mTexture3;

	public:
		StarDisplay(int drawOrder = 0);

		void SetPosition(const GameLib::Vector2& pos);
		void SetStarNum(int);
	};
}