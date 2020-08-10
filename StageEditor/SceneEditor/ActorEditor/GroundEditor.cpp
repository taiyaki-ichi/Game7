#include"GroundEditor.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"

namespace StageEditor
{
	GroundEditor::GroundEditor(GameLib::Actor* actor)
		:ActorEditorBase{ actor ,"Ground",2,0}
		, mRect{}
	{
		mRect.SetColor({ 50,50,50,255 });
	}

	void GroundEditor::Update()
	{
		int num = mPosData.GetDataNum();
		if (num == 2)
		{
			auto pos = GameLib::GetCenter(mPosData[0], mPosData[1]);
			float w = GameLib::GetDistanceX(mPosData[0], mPosData[1]);
			float h = GameLib::GetDistanceY(mPosData[0], mPosData[1]);

			mCollider.SetPosition(pos);
			mRect.SetPosition(std::move(pos));

			mCollider.SetWidthAndHeith(w, h);
			mRect.SetWidthAndHeight(w, h);
		}
	}

	void GroundEditor::BeginWorking()
	{
		mRect.SetIsAutoDrawing(true);
	}

	void GroundEditor::BeginToRest()
	{
		mRect.SetIsAutoDrawing(false);
	}
}