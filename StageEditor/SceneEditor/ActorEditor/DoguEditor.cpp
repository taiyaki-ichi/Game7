#include"DoguEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/Dogu/DoguParam.hpp"

namespace StageEditor
{
	DoguEditor::DoguEditor(GameLib::Actor* actor)
		:ActorEditorBase{ actor,"Dogu",1,0 }
		, mTexture{ "../Assets/Enemy/Dogu/stay.png" }
	{
		mTexture.SetScale(Stage::DoguParam::SCALE);

		mCollider.SetWidthAndHeith(Stage::DoguParam::WIDTH, Stage::DoguParam::HEIGHT);
		mCollider.SetScale(Stage::DoguParam::SCALE);
	}

	void DoguEditor::Update()
	{
		mTexture.SetPosition(mPosData[0]);
		mCollider.SetPosition(mPosData[0]);
	}

	void DoguEditor::BeginWorking()
	{
		mCollider.Active();
	}

	void DoguEditor::BeginToRest()
	{
		mCollider.Pause();
	}
}