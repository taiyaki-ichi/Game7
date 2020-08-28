#pragma once
#include"GameSceneBase.hpp"

namespace Stage
{
	class Stage;
}

namespace Game
{
	class GameStage : public SceneBase
	{
		Stage::Stage* mStage;

	public:
		GameStage(GameLib::Actor*, const GameData&, const std::string& fileName);

		void CustomizeUpdate() override;
	};
}