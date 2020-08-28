#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Game
{
	class ChoiceIcon : public GameLib::Actor
	{
		GameLib::DrawTexture mTexture;

		int mPosX;
		int mPosY;

		int mCnt;

	public:
		ChoiceIcon(GameLib::Actor*);

		void CustomizeUpdate() override;

		void SetPosision(int x,int y);
	};

}