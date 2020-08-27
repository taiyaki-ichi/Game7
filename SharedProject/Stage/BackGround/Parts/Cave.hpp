#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace Stage
{
	class Cave : public GameLib::Actor
	{
		GameLib::DrawRect mRect1;
		GameLib::DrawRect mRect2;
		GameLib::DrawRect mRect3;

		GameLib::DrawRect mRect4;
		GameLib::DrawRect mRect5;
		GameLib::DrawRect mRect6;

		GameLib::DrawRect mRectCenter;

	public:
		Cave(GameLib::Actor*);

		void CustomizeUpdate() override;

	private:
		void AdjustPos();

	};
}