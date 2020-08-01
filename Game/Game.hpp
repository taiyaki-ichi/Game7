#pragma once
#include"GameLib/include/Actor/RootActor.hpp"

namespace Game
{
	class GameSceneBase;

	class Game : public GameLib::RootActor
	{
		GameSceneBase* mGameSceneBase;

	public:
		Game();
		virtual ~Game() = default;

		void CustomizeUpdate() override;
	};

}