#include"DiamondEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/Diamond/DiamondParam.hpp"

namespace StageEditor
{
	DiamondEditor::DiamondEditor(GameLib::Actor* actor)
		:ActorEditorBase{ actor,"Diamond",1,0 }
		, mTexture{ "../Assets/Item/Diamond/002.png" }
	{
		mTexture.SetScale(Stage::DiamondParam::SCALE);

		mCollider.SetWidthAndHeith(Stage::DiamondParam::WIDTH, Stage::DiamondParam::HEIGHT);
		mCollider.SetScale(Stage::DiamondParam::SCALE);
	}

	void DiamondEditor::Update()
	{
		mCollider.SetPosition(mPosData[0]);
		mTexture.SetPosition(mPosData[0]);
	}

	void DiamondEditor::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
	}

	void DiamondEditor::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
	}
}