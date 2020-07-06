#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	class PlayerEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;

	public:
		PlayerEditor(SceneEditor* scene);
		virtual ~PlayerEditor();

		void ActorEditorUpdate() override;

		void Active() override;
		void Pause() override;

	};
}