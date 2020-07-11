#include"PlayerEditor.hpp"
#include"PosInfo/PosInfo.hpp"

namespace StageEditor
{
	PlayerEditor::PlayerEditor(SceneEditor* scene)
		:ActorEditorBase{scene,"Player",1}
		, mTexture{ "../Assets/Player/stay001.png" }
	{
		mTexture.SetScale(0.1f);

		mDefaultCollider.SetWidthAndHeith(25.f, 50.f);
	}
	PlayerEditor::~PlayerEditor()
	{
		//”
	}
	void PlayerEditor::ActorEditorUpdate()
	{
		auto pos = GetPosInfos();

		mTexture.SetPosition(pos[0]->GetPosition());
		mDefaultCollider.SetPosition(pos[0]->GetPosition() + GameLib::Vector2{ 0.f,-12.f });
	}
	void PlayerEditor::Active()
	{
		mTexture.SetIsAutoDrawing(true);
		mDefaultCollider.Active();
	}
	void PlayerEditor::Pause()
	{
		mTexture.SetIsAutoDrawing(false);
		mDefaultCollider.Pause();
	}
}