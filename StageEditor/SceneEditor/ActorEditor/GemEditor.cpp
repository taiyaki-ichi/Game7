#include"GemEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/Gem/GemParam.hpp"

namespace StageEditor
{
	GemEditor::GemEditor(GameLib::Actor* actor)
		:ActorEditorBase{ actor,"Gem",1,0 }
		, mTexture{ "../Assets/Item/Diamond/002.png" }
	{
		mTexture.SetScale(Stage::GemParam::SCALE);

		mCollider.SetWidthAndHeith(Stage::GemParam::WIDTH, Stage::GemParam::HEIGHT);
		mCollider.SetScale(Stage::GemParam::SCALE);
	}

	void GemEditor::Update()
	{
		mCollider.SetPosition(mPosData[0]);
		mTexture.SetPosition(mPosData[0]);
	}
	
	void GemEditor::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
	}

	void GemEditor::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
	}
}