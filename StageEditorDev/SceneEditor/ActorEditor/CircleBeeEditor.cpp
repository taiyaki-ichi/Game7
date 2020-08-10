#include"CircleBeeEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/Bee/BeeParam.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"

namespace StageEditor
{
	CircleBeeEditor::CircleBeeEditor(GameLib::Actor* actor)
		:ActorEditorBase{actor,"Bee",3,0}
		, mBee{ "../Assets/Enemy/Bee/active001.png" }
		, mCircle{}
	{
		mCollider.SetScale(Stage::BeeParam::SCALE);
		mCollider.SetWidthAndHeith(Stage::BeeParam::WIDTH, Stage::BeeParam::HEIGHT);

		mBee.SetScale(Stage::BeeParam::SCALE);

		mCircle.SetIsFill(false);
	}

	void CircleBeeEditor::Update()
	{
		mBee.SetPosition(mPosData[0]);
		mCircle.SetPosition(mPosData[0]);
		mCollider.SetPosition(mPosData[0]);

		if (mPosData.GetDataNum() > 1)
		{
			mBee.SetPosition(mPosData[1]);
			mCollider.SetPosition(mPosData[1]);
			auto vec = mPosData[1] - mPosData[0];
			mBee.SetRotation(-std::atan2(vec.x, vec.y));
			mCircle.SetRadius(GameLib::GetLength(mPosData[0], mPosData[1]));
		}

		if (mPosData.GetDataNum() == 3)
		{
			auto vec1 = mPosData[1] - mPosData[0];
			auto vec2 = mPosData[2] - mPosData[1];

			float rot;
			if (GameLib::Vector2::Cross(vec1, vec2) < 0.f)
				rot = -std::atan2(vec1.x, vec1.y) - GameLib::PI;
			else
				rot = -std::atan2(vec1.x, vec1.y);

			auto vec = GameLib::Vector2::Rotation(GameLib::Vector2{ 20.f,0.f }, rot);

			mBee.SetPosition(mPosData[1] - vec);
			mBee.SetRotation(rot);

			mCollider.SetPosition(mPosData[1] - vec);
		}
	}

	void CircleBeeEditor::BeginWorking()
	{
		mBee.SetIsAutoDrawing(true);
		mCircle.SetIsAutoDrawing(true);
	}

	void CircleBeeEditor::BeginToRest()
	{
		mBee.SetIsAutoDrawing(false);
		mCircle.SetIsAutoDrawing(false);
	}
}