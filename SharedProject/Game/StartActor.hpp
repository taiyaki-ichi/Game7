#pragma once
#include"GameLib/include/Actor/RootActor.hpp"
#include"Stage/Ground.hpp"
#include"Stage/Character/Player.hpp"

namespace Game
{
	class StartActor : public GameLib::RootActor
	{
	public:
		StartActor()
			:RootActor()
		{
			new Stage::Ground(this,{ 0.f,-200.f }, 500.f, 100.f);
			new Stage::Ground(this, { -200.f,0.f }, 100.f, 500.f);
			new Stage::Ground(this, { 0.f,200.f }, 500.f, 100.f);
			new Stage::Ground(this, { 200.f,0.f }, 100.f, 500.f);
			new Stage::Player(this);
		}

		virtual ~StartActor() = default;
	};
}