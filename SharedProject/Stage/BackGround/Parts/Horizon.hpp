#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace Stage::BackGround
{
	class Horizon : public GameLib::Actor
	{
		GameLib::DrawRect mRect1;
		GameLib::DrawRect mRect2;
		GameLib::DrawRect mRect3;

	public:
		Horizon(GameLib::Actor* owner);
		virtual ~Horizon() = default;

		void CustomizeUpdate() override;
	};
}