#pragma once
#include"GameLib/include/Actor/RootActor.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

#include"StageSelect/StageSelect.hpp"

namespace dev
{
	class StartActor : public GameLib::RootActor
	{
	public:
		StartActor()
			:GameLib::RootActor{}
		{
			//new Game::StageSelect::HexMap{ this };
			new Game::StageSelect::StageSelect{ this };
			GameLib::Collider::SetIsDebug(true);
		}

		virtual ~StartActor() = default;

		//void CustomizeUpdate() override;

	private:

	};
}