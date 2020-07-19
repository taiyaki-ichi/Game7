#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/Draw/DrawLine.hpp"
#include"GameLib/include/Draw/DrawCircle.hpp"

namespace StageEditor
{
	class StraightBeeEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;
		GameLib::DrawLine mLine;

	public:
		StraightBeeEditor(SceneEditor* scene);
		virtual ~StraightBeeEditor() = default;

		void ActorEditorUpdate() override;

		void Active() override;
		void Pause() override;

	};

	class CircleBeeEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;
		GameLib::DrawCircle mCircle;

	public:
		CircleBeeEditor(SceneEditor* scene);
		virtual ~CircleBeeEditor() = default;

		void ActorEditorUpdate() override;
		
		void Active() override;
		void Pause() override;
	};
}