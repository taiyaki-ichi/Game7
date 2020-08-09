#include"TripleEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/Triple/TripleParam.hpp"

namespace StageEditor
{
	TripleEditor::TripleEditor(GameLib::Actor* actor)
		:ActorEditorBase{actor,"Triple",1,0}
		, mTexture{"../Assets/Enemy/Triple/left001.png"}
	{
		mTexture.SetScale(Stage::TripleRaram::SCALE);
		mCollider.SetScale(Stage::TripleRaram::SCALE);
		mCollider.SetWidthAndHeith(Stage::TripleRaram::WIDTH, Stage::TripleRaram::HEIGHT);
	}

	void TripleEditor::Update()
	{
		int num = mPosData.GetDataNum();
		if (num == 1)
		{
			mTexture.SetPosition(mPosData[0]);
			mCollider.SetPosition(mPosData[0]);
		}
	}

	void TripleEditor::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
	}

	void TripleEditor::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
	}
}