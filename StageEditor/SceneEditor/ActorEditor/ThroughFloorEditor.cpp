#include"ThroughFloorEditor.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"Stage/SceneManager/Scene/Actor/ThroughFloor/PoleParam.hpp"

namespace StageEditor
{
	ThroughFloorEditor::ThroughFloorEditor(GameLib::Actor* actor)
		:ActorEditorBase{ actor,"ThroughFloor",2,0 }
		, mRect{}
	{
		mRect.SetColor({ 100, 100, 100, 255 });
	}

	void ThroughFloorEditor::Update()
	{
		if (mPosData.GetDataNum() == 2)
		{
			float x = GameLib::GetDistanceX(mPosData[0], mPosData[1]);
			float y = GameLib::GetDistanceY(mPosData[0], mPosData[1]);

			if (x >= y)
			{
				int num = std::round(x / static_cast<float>(Stage::PoleParam::RADIUSE * 2.f));
				float w = num * Stage::PoleParam::RADIUSE * 2.f;
				float h = Stage::PoleParam::RADIUSE;

				GameLib::Vector2 c{};
				if (mPosData[0].x < mPosData[1].x)
					c = mPosData[0] + GameLib::Vector2{ w / 2.f,0.f };
				else
					c = mPosData[0] - GameLib::Vector2{ w / 2.f,0.f };

				mRect.SetWidthAndHeight(w, h);
				mCollider.SetWidthAndHeith(w, h);

				mRect.SetPosition(c);
				mCollider.SetPosition(c);
			}
			else
			{
				int num = std::round(y / static_cast<float>(Stage::PoleParam::RADIUSE * 2.f));
				float w = num * Stage::PoleParam::RADIUSE * 2.f;
				float h = Stage::PoleParam::RADIUSE;

				GameLib::Vector2 c{};
				if (mPosData[0].y < mPosData[1].y)
					c = mPosData[0] + GameLib::Vector2{ 0.f,w / 2.f };
				else
					c = mPosData[0] - GameLib::Vector2{ 0.f,w / 2.f };

				mRect.SetWidthAndHeight( h,w);
				mCollider.SetWidthAndHeith( h,w);

				mRect.SetPosition(c);
				mCollider.SetPosition(c);
			}

		}
	}

	void ThroughFloorEditor::BeginWorking()
	{
		mRect.SetIsAutoDrawing(true);
	}

	void ThroughFloorEditor::BeginToRest()
	{
		mRect.SetIsAutoDrawing(false);
	}
}