#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace StageEditor
{
	class GroundEditor : public ActorEditorBase
	{
		GameLib::DrawRect mRect;

	public:
		GroundEditor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;
	};
}