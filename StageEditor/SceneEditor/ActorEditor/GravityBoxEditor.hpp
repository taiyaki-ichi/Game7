#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	class GravityBoxEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;

	public:
		GravityBoxEditor(SceneEditor* scene);
		virtual ~GravityBoxEditor() = default;

		void ActorEditorUpdate() override;

		void Active() override;
		void Pause() override;
	};
}