#include"GroundEditor.hpp"
#include"PosInfo/PosInfo.hpp"
#include"PosInfo/PosInfoUtility.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

namespace StageEditor
{
	GroundEditor::GroundEditor(SceneEditor* owner)
		:ActorEditorBase{ owner,std::string{"Ground"},2 }
		, mRect{}
	{
		mRect.SetColor({ 50,50,50,255 });
	}

	void GroundEditor::ActorEditorUpdate()
	{
		auto pos = GetPosInfos();
		if (pos.size() >= 2) {
			auto center = GetCenter(pos[0], pos[1]);
			float w = GetWidth(pos[0], pos[1]);
			float h = GetHeight(pos[0], pos[1]);
			mDefaultCollider.Set(center, w, h, 1.f, 0.f);
			mRect.Set(center, 1.f, 0.f);
			mRect.SetWidthAndHeight(w, h);
		}
	}

	void GroundEditor::Active()
	{
		mDefaultCollider.Active();
		mRect.SetIsAutoDrawing(true);
	}

	void GroundEditor::Pause()
	{
		mDefaultCollider.Pause();
		mRect.SetIsAutoDrawing(false);
	}


}