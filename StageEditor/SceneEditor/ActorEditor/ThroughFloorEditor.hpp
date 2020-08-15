#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace StageEditor
{
	class ThroughFloorEditor : public ActorEditorBase
	{
		GameLib::DrawRect mRect;

	public:
		ThroughFloorEditor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;
	};
}