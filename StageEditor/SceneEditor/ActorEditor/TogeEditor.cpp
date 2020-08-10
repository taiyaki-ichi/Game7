#include"TogeEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/Toge/TogeParam.hpp"

namespace StageEditor
{

	TogeEditor::TogeEditor(GameLib::Actor* actor)
		:ActorEditorBase{actor,"Toge",1,0}
		, mTexture{"../Assets/Enemy/Toge/stay.png"}
	{
		mTexture.SetScale(Stage::TogeParam::SCALE_CENTER + Stage::TogeParam::SCALE_RADIUS);
		mCollider.SetScale(Stage::TogeParam::SCALE_CENTER + Stage::TogeParam::SCALE_RADIUS);
		mCollider.SetWidthAndHeith(Stage::TogeParam::WIDTH, Stage::TogeParam::HEIGHT);
	}

	void TogeEditor::Update()
	{
		int num = mPosData.GetDataNum();
		if (num == 1) {
			mTexture.SetPosition(mPosData[0]);
			mCollider.SetPosition(mPosData[0]);
		}
	}

	void TogeEditor::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
	}

	void TogeEditor::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
	}


}