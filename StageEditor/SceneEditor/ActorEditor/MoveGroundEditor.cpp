#include"MoveGroundEditor.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"

namespace StageEditor
{
	MoveGroundEditor::MoveGroundEditor(GameLib::Actor* actor)
		:ActorEditorBase{actor,"MoveGround",3,0}
		, mRect{}
		, mLine{}
	{
		mRect.SetColor({ 50,50,50,255 });
		mLine.SetDrawOrder(-1);
	}

	void MoveGroundEditor::Update()
	{
		if (mPosData.GetDataNum() >= 2)
		{
			float w = GameLib::GetDistanceX(mPosData[0], mPosData[1]);
			float h = GameLib::GetDistanceY(mPosData[0], mPosData[1]);
			auto c = GameLib::GetCenter(mPosData[0], mPosData[1]);

			mRect.SetWidthAndHeight(w, h);
			mRect.SetPosition(c);

			mCollider.SetWidthAndHeith(w, h);
			mCollider.SetPosition(c);
		}

		if (mPosData.GetDataNum() == 3)
		{
			auto c = GameLib::GetCenter(mPosData[0], mPosData[1]);
			mLine.SetPoints(std::move(c), mPosData[2]);
		}
	}

	void MoveGroundEditor::BeginWorking()
	{
		mRect.SetIsAutoDrawing(true);
		mLine.SetIsAutoDrawing(true);
	}

	void MoveGroundEditor::BeginToRest()
	{
		mRect.SetIsAutoDrawing(false);
		mLine.SetIsAutoDrawing(false);
	}
}