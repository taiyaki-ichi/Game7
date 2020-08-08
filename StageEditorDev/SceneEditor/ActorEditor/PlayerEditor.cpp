#include"PlayerEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/Player/PlayerParam.hpp"

namespace StageEditor
{
	PlayerEditor::PlayerEditor(GameLib::Actor* actor)
		:ActorEditorBase{ actor ,"Player",1,0}
		, mTexture{"../Assets/Player/stay001.png"}
	{
		mTexture.SetScale(Stage::PlayerParam::SCALE);
		mCollider.SetWidthAndHeith(Stage::PlayerParam::WIDTH, Stage::PlayerParam::HEIGHT);
	}


	void PlayerEditor::Update()
	{
		int posNum = mPosData.GetDataNum();
		if (posNum == 1)
			mTexture.SetPosition(mPosData[0]);
	}

	void PlayerEditor::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
	}
	
	void PlayerEditor::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
	}
}