#include"GravityBoxEditor.hpp"

namespace StageEditor
{
	GravityBoxEditor::GravityBoxEditor(SceneEditor* scene)
		:ActorEditorBase{scene,"GravityBox",1}
		, mTexture{"../Assets/Box/001.png"}
	{
		mTexture.SetScale(0.1f);

		mDefaultCollider.SetWidthAndHeith(76.f, 76.f);
	}
	void GravityBoxEditor::ActorEditorUpdate()
	{
		auto pos = GetPosInfos();
		mTexture.SetPosition(pos[0]->GetPosition());
		mDefaultCollider.SetPosition(pos[0]->GetPosition());
	}
	void GravityBoxEditor::Active()
	{
		mTexture.SetIsAutoDrawing(true);
		mDefaultCollider.Active();
	}
	void GravityBoxEditor::Pause()
	{
		mTexture.SetIsAutoDrawing(false);
		mDefaultCollider.Pause();
	}
}