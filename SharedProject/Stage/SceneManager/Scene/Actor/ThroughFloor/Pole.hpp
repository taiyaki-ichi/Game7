#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawCircle.hpp"

namespace Stage
{
	class Pole : public GameLib::Actor
	{
		GameLib::DrawCircle mCircle;

	public:
		Pole(GameLib::Actor*, GameLib::Vector2&&);

		void BeginWorking();
		void BeginToRest();
	};
}