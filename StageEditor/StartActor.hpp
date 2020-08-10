#pragma once
#include"GameLib/include/Actor/RootActor.hpp"

namespace Stage
{
	class Stage;
}

namespace StageEditor
{
	class StageEditor;

	class StartActor :public GameLib::RootActor
	{

		StageEditor* mStageEditor;
		Stage::Stage* mStage;

	public:
		StartActor();

		void CustomizeUpdate() override;
	};
}