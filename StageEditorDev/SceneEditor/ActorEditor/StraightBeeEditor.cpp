#include"StraightBeeEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/Bee/BeeParam.hpp"

namespace StageEditor
{
	StraightBeeEditor::StraightBeeEditor(GameLib::Actor* actor)
		:ActorEditorBase{actor,"StraightBee",2,0}
		, mBee{ "../Assets/Enemy/Bee/active001.png" }
		, mLine{}
	{
		mCollider.SetScale(Stage::BeeParam::SCALE);
		mCollider.SetWidthAndHeith(Stage::BeeParam::WIDTH, Stage::BeeParam::HEIGHT);

		mBee.SetScale(Stage::BeeParam::SCALE);
	}

	void StraightBeeEditor::Update()
	{
		mCollider.SetPosition(mPosData[0]);
		mBee.SetPosition(mPosData[0]);

		if (mPosData.GetDataNum() == 2)
		{
			mLine.SetPoints(mPosData[0], mPosData[1]);

			mBee.SetPosition(mPosData[1]);
			mCollider.SetPosition(mPosData[1]);

			auto vec = mPosData[1] - mPosData[0];
			mBee.SetRotation(-std::atan2(vec.x, vec.y) - GameLib::PI / 2.f);
		}
	}

	void StraightBeeEditor::BeginWorking()
	{
		mBee.SetIsAutoDrawing(true);
		mLine.SetIsAutoDrawing(true);
	}

	void StraightBeeEditor::BeginToRest()
	{
		mBee.SetIsAutoDrawing(false);
		mLine.SetIsAutoDrawing(false);
	}
}