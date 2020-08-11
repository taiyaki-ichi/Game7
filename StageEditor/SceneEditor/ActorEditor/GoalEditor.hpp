#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	class GoalEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;

	public:
		GoalEditor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void PrintStringDataInfo() override;
	};
}