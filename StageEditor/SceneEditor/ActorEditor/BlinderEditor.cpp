#include"BlinderEditor.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"

namespace StageEditor
{
	BlinderEditor::BlinderEditor(GameLib::Actor* actor)
		:ActorEditorBase{ actor,"Blinder",2,0 }
		, mRect{}
	{
		mRect.SetColor({ 50,50,50,128 });
	}

	void BlinderEditor::Update()
	{
		if (mPosData.GetDataNum() == 2)
		{
			auto c = GameLib::GetCenter(mPosData[0], mPosData[1]);
			float w = GameLib::GetDistanceX(mPosData[0], mPosData[1]);
			float h = GameLib::GetDistanceY(mPosData[0], mPosData[1]);

			mCollider.SetPosition(c);
			mCollider.SetWidthAndHeith(w, h);

			mRect.SetPosition(std::move(c));
			mRect.SetWidthAndHeight(w, h);
		}
	}

	void BlinderEditor::BeginWorking()
	{
		mRect.SetIsAutoDrawing(true);
	}

	void BlinderEditor::BeginToRest()
	{
		mRect.SetIsAutoDrawing(false);
	}
}

