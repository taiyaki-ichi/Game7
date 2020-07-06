#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace StageEditor
{
	class GroundEditor : public ActorEditorBase
	{
		GameLib::DrawRect mRect;

	public:
		GroundEditor(SceneEditor* owner);
		virtual ~GroundEditor() = default;

		virtual void ActorEditorUpdate() override;

		void Active();
		void Pause();

		virtual ActorData GetDateObject() override;
	};
}