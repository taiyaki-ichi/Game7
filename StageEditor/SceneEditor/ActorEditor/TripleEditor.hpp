#pragma once
#include"ActorEditorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace StageEditor
{
	class TripleEditor : public ActorEditorBase
	{
		GameLib::DrawTexture mTexture;

	public:
		TripleEditor(SceneEditor* scene)
			:ActorEditorBase{scene,"Triple",1}
			, mTexture{ "../Assets/Enemy/Triple/left001.png" }
		{
			mDefaultCollider.SetWidthAndHeith(350.f, 600.f);
			mDefaultCollider.SetScale(0.1f);

			mTexture.SetScale(0.1f);
		}
		virtual ~TripleEditor() = default;

		void ActorEditorUpdate() override {
			auto pos = GetPosInfos();
			mDefaultCollider.ResetPosition(pos[0]->GetPosition() + GameLib::Vector2{ 0.f,-6.f });
			mTexture.ResetPosition(pos[0]->GetPosition());
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

