#include"CameraEditor.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"

namespace StageEditor
{
	CameraEditor::CameraEditor(GameLib::Actor* actor)
		:ActorEditorBase{ actor,"Camera",2,0 }
		, mRect{}
	{
		mRect.SetColor({ 0,0,255,255 });
		mRect.SetIsFill(false);

		mCollider.SetWidthAndHeith(10.f, 10.f);
	}

	void CameraEditor::Update()
	{
		int num = mPosData.GetDataNum();

		if (num == 1)
			mCollider.SetPosition(mPosData[0]);

		if (num == 2)
		{
			auto c = GameLib::GetCenter(mPosData[0], mPosData[1]);
			float w = GameLib::GetDistanceX(mPosData[0], mPosData[1]);
			float h = GameLib::GetDistanceY(mPosData[0], mPosData[1]);

			mRect.SetWidthAndHeight(w, h);
			mRect.SetPosition(std::move(c));
		}
	}

	void CameraEditor::BeginWorking()
	{
		mRect.SetIsAutoDrawing(true);
	}

	void CameraEditor::BeginToRest()
	{
		mRect.SetIsAutoDrawing(false);
	}


}