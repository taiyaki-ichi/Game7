#include"PlayerEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/Player/PlayerParam.hpp"

namespace StageEditor
{

	int PlayerEditor::mCnt = 0;

	PlayerEditor::PlayerEditor(GameLib::Actor* actor)
		:ActorEditorBase{ actor ,"Player",1,0}
		, mTexture{"../Assets/Player/stay001.png"}
	{
		mTexture.SetScale(Stage::PlayerParam::SCALE);
		mCollider.SetWidthAndHeith(Stage::PlayerParam::WIDTH, Stage::PlayerParam::HEIGHT);
		mCollider.SetScale(Stage::PlayerParam::SCALE);

		mCnt++;
	}

	PlayerEditor::~PlayerEditor()
	{
		mCnt--;
	}


	void PlayerEditor::Update()
	{
		int posNum = mPosData.GetDataNum();
		if (posNum == 1) {
			mTexture.SetPosition(mPosData[0]);
			mCollider.SetPosition(mPosData[0] + GameLib::Vector2{ 0.f,-Stage::PlayerParam::COLLIDER_ADJUST_DOWN_SIZE });
		}
	}

	void PlayerEditor::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
	}
	
	void PlayerEditor::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
	}

	int PlayerEditor::GetNum()
	{
		return mCnt;
	}
}