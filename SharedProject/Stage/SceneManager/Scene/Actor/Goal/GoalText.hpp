#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Stage
{
	class GoalText : public GameLib::Actor
	{
		GameLib::DrawTexture mTexture;

		bool mIsMove;

	public:
		GoalText(GameLib::Actor*);

		void CustomizeUpdate() override;
	};
}