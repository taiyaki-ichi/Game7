#pragma once
#include"GameLib/include/Actor/RootActor.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

#include"StageSelect/StageSelect.hpp"
#include"StageData.hpp"

#include"Game.hpp"

namespace dev
{
	class StartActor : public GameLib::RootActor
	{
	public:
		StartActor()
			:GameLib::RootActor{}
		{
			//new Game::StageSelect::HexMap{ this };
			/*
			std::map<std::pair<int, int>, unsigned char> data{ {std::make_pair(1,0),0b11110},{std::make_pair(2,0),0b10110},{std::make_pair(3,0),0b1} };
			new Game::StageSelect{ this , data,Game::gStageData,std::make_pair(0,0) ,5,5 };
			GameLib::Collider::SetIsDebug(true);
			*/
			new Game::Game{ this };
		}

		virtual ~StartActor() = default;

		//void CustomizeUpdate() override;

	private:

	};
}