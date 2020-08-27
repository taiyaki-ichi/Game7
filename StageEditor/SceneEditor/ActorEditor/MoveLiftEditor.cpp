#include"MoveLiftEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/Lift/LiftParam.hpp"

namespace StageEditor
{
	MoveLiftEditor::MoveLiftEditor(GameLib::Actor* actor)
		:ActorEditorBase{actor,"MoveLift",2,0}
		, mTexture{ "../Assets/Object/Lift/001.png" }
		, mLine{}
	{
		mTexture.SetScale(Stage::LiftParam::SCLAE);

		mCollider.SetWidthAndHeith(Stage::LiftParam::WIDTH, Stage::LiftParam::HEIGHT);
		mCollider.SetScale(Stage::LiftParam::SCLAE);
	}

	void MoveLiftEditor::Update()
	{
		mTexture.SetPosition(mPosData[0]);
		mCollider.SetPosition(mPosData[0]);

		if (mPosData.GetDataNum() == 2)
		{
			mLine.SetPoints(mPosData[0], mPosData[1]);
		}
	}

	void MoveLiftEditor::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
		mLine.SetIsAutoDrawing(true);
	}

	void MoveLiftEditor::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
		mLine.SetIsAutoDrawing(false);
	}
}