#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace StageEditor
{
	class IceGroundEditor : public ActorEditorBase
	{
		GameLib::DrawRect mRect;

	public:
		IceGroundEditor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;
	};
}