#include"TogeBlockEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/TogeBlock/TogeBlockParam.hpp"

namespace StageEditor
{
	TogeBlockEditor::TogeBlockEditor(GameLib::Actor* actor)
		:ActorEditorBase{ actor,"TogeBlock",1,0 }
		, mTexture{ "../Assets/Object/TogeBlock/001.png" }
	{
		using namespace Stage::TogeBlockParam;

		mTexture.SetScale(SCALE);

		mCollider.SetWidthAndHeith(WIDTH, HEIGHT);
		mCollider.SetScale(SCALE);
	}

	void TogeBlockEditor::Update()
	{
		mTexture.SetPosition(mPosData[0]);
		mCollider.SetPosition(mPosData[0]);
	}

	void TogeBlockEditor::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
	}

	void TogeBlockEditor::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
	}
}