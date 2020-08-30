#include"StandEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/Stand/StandParam.hpp"

namespace StageEditor
{
	StandEditor::StandEditor(GameLib::Actor* actor,std::string&& dir)
		:ActorEditorBase{ actor,dir + "Stand",1,0 }
		, mTexture{ "../Assets/Enemy/Stand/body-up.png" }
	{
		mTexture.SetScale(Stage::StandParam::BODY_SCALE);
		
		mCollider.SetWidthAndHeith(50.f, 50.f);

		if (dir == "Right")
			mTexture.SetRotation(GameLib::PI / 2.f);
		else if (dir == "Up")
			mTexture.SetRotation(GameLib::PI);
		else if (dir == "Left")
			mTexture.SetRotation(GameLib::PI / 2.f * 3.f);
	}

	void StandEditor::Update()
	{
		mTexture.SetPosition(mPosData[0]);
		mCollider.SetPosition(mPosData[0]);
	}

	void StandEditor::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
	}

	void StandEditor::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
	}
}