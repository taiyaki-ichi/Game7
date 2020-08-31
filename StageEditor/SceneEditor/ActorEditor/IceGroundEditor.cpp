#include"IceGroundEditor.hpp"


namespace StageEditor
{
	IceGroundEditor::IceGroundEditor(GameLib::Actor* actor)
		:ActorEditorBase{ actor,"IceGround",2,0 }
		, mRect{}
	{
		mRect.SetColor({ 20,20,20,255 });
	}

	void IceGroundEditor::Update()
	{
		if (mPosData.GetDataNum() == 2)
		{
			auto pos = GameLib::GetCenter(mPosData[0], mPosData[1]);
			float w = GameLib::GetDistanceX(mPosData[0], mPosData[1]);
			float h = GameLib::GetDistanceY(mPosData[0], mPosData[1]);

			mRect.SetWidthAndHeight(w, h);
			mRect.SetPosition(pos);

			mCollider.SetWidthAndHeith(w, h);
			mCollider.SetPosition(pos);
		}
	}

	void IceGroundEditor::BeginWorking()
	{
		mRect.SetIsAutoDrawing(true);
	}

	void IceGroundEditor::BeginToRest()
	{
		mRect.SetIsAutoDrawing(false);
	}
}