#include"CarrotEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/Carrot/CarrotParam.hpp"

namespace StageEditor
{
	CarrotEditor::CarrotEditor(GameLib::Actor* actor)
		:ActorEditorBase{ actor ,"Carrot",1,0}
		, mTexture{ "../Assets/Enemy/Carrot/stay.png" }
	{
		mTexture.SetScale(Stage::CarrotParam::SCALE);

		mCollider.SetWidthAndHeith(Stage::CarrotParam::WIDTH, Stage::CarrotParam::HEIGHT);
		mCollider.SetScale(Stage::CarrotParam::SCALE);
	}

	void CarrotEditor::Update()
	{
		mTexture.SetPosition(mPosData[0]);
		mCollider.SetPosition(mPosData[0]);
	}

	void CarrotEditor::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
	}

	void CarrotEditor::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
	}


}