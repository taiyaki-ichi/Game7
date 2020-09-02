#pragma once
#include"GameSceneBase.hpp"
#include"Stage/BackGroundType.hpp"

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
		GameStage(GameLib::Actor*, const GameData&, const std::string& fileName,Stage::BackGroundType&&);

		void CustomizeUpdate() override;
	};
}