#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	class TogeEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;

	public:
		TogeEditor(SceneEditor* scene)
			:ActorEditorBase{ scene,"Toge",1 }
			, mTexture{ "../Assets/Enemy/Toge/stay.png" }
		{
			mDefaultCollider.SetWidthAndHeith(550.f, 550.f);
			mDefaultCollider.SetScale(0.1f);

			mTexture.SetScale(0.1f);
		}
		virtual ~TogeEditor() = default;

		void ActorEditorUpdate() override {
			auto pos = GetPosInfos();
			mDefaultCollider.SetPosition(pos[0]->GetPosition());
			mTexture.SetPosition(pos[0]->GetPosition());
		}

		void Active() override {
			mDefaultCollider.Active();
			mTexture.SetIsAutoDrawing(true);
		}
		void Pause() override {
			mDefaultCollider.Pause();
			mTexture.SetIsAutoDrawing(false);
		}
	};
}

