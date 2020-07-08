#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace StageEditor
{

	class CameraEditor: public ActorEditorBase
	{
		GameLib::DrawRect mRect;

	public:
		CameraEditor(SceneEditor* sceneEditor);
		virtual ~CameraEditor() = default;

		void ActorEditorUpdate() override;

		void Active() override;
		void Pause() override;

	};
}