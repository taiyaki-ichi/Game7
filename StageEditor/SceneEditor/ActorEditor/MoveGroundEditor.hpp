#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"
#include"GameLib/include/Draw/DrawLine.hpp"

namespace StageEditor
{
	class MoveGroundEditor : public ActorEditorBase
	{
		GameLib::DrawRect mRect;
		GameLib::DrawLine mLine;

	public:
		MoveGroundEditor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;
	};
}