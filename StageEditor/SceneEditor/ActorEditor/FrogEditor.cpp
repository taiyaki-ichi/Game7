#include"FrogEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/Frog/FrogParam.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"

namespace StageEditor
{
	FrogEditor::FrogEditor(GameLib::Actor* actor)
		:ActorEditorBase{actor,"Frog",2,0}
		, mTexture{ "../Assets/Enemy/Frog/stay.png" }
		, mLine{}
	{
		using namespace Stage::FrogParam;

		mTexture.SetScale(SCALE);

		mCollider.SetWidthAndHeith(WIDTH, HEIGHT);
		mCollider.SetScale(SCALE);
	}

	void FrogEditor::Update()
	{
		mCollider.SetPosition(mPosData[0]);
		mTexture.SetPosition(mPosData[0]);

		if (mPosData.GetDataNum() == 2)
		{
			float y = GameLib::GetDistanceY(mPosData[0], mPosData[1]);
			mLine.SetPoints(mPosData[0], mPosData[0] + GameLib::Vector2{ 0.f,y });
		}
	}

	void FrogEditor::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
		mLine.SetIsAutoDrawing(true);
	}

	void FrogEditor::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
		mLine.SetIsAutoDrawing(false);
	}
}