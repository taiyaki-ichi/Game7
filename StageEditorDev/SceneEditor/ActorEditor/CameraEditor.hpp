#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace StageEditor
{
	class CameraEditor : public ActorEditorBase
	{
		GameLib::DrawRect mRect;
	public:
		CameraEditor(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

	};
}