#pragma once
#include"GameLib/include/Actor/RootActor.hpp"
#include"Stage/Ground.hpp"
#include"Stage/Player.hpp"

namespace Game
{
	class StartActor : public GameLib::RootActor
	{
	public:
		StartActor()
			:RootActor()
		{
			new Stage::Ground(this,{ 0.f,-200.f }, 600.f, 100.f);
			new Stage::Player(this);
		}

		virtual ~StartActor() = default;
	};
}