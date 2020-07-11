#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace Game::Stage::BackGround
{
	class Basis : public GameLib::Actor
	{
		GameLib::DrawRect mRect1;
		GameLib::DrawRect mRect2;
		GameLib::DrawRect mRect3;

	public:
		Basis(GameLib::Actor* owner);
		virtual ~Basis() = default;

		void CustomizeUpdate() override;
	};
}