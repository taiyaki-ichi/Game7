#include"CameraEditor.hpp"

namespace StageEditor
{
	CameraEditor::CameraEditor(SceneEditor* sceneEditor)
		:ActorEditorBase{sceneEditor,"Camera",2}
		, mRect{}
	{
		mRect.SetColor({ 0,0,255,255 });
		mRect.SetIsFill(false);

		mDefaultCollider.SetWidthAndHeith(50.f, 50.f);
		
		
	}

	void CameraEditor::ActorEditorUpdate()
	{
		auto posInfo = GetPosInfos();
		mDefaultCollider.ResetPosition(posInfo[0]->GetPosition());
		if (posInfo.size() == 2) {

			auto center = GetCenter(posInfo[0], posInfo[1]);
			float w = GetWidth(posInfo[0], posInfo[1]);
			float h = GetHeight(posInfo[0], posInfo[1]);

			mRect.ResetPosition(std::move(center));
			mRect.SetWidthAndHeight(w, h);
		}
	}
	void CameraEditor::Active()
	{
		mRect.SetIsAutoDrawing(true);
		mDefaultCollider.Active();
	}
	void CameraEditor::Pause()
	{
		mRect.SetIsAutoDrawing(false);
		mDefaultCollider.Pause();


	}
}