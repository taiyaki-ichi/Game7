#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace StageEditor
{
	class BlinderEditor : public ActorEditorBase
	{
		GameLib::DrawRect mRect;

	public:
		BlinderEditor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;
	};
}