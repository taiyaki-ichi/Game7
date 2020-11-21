#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace Stage
{
	class Stage;
}

namespace StageEditor
{
	class StageEditor;

	class StartActor :public GameLib::Actor
	{

		StageEditor* mStageEditor;
		Stage::Stage* mStage;

	public:
		StartActor(GameLib::Actor*);

		void CustomizeUpdate() override;
	};
}