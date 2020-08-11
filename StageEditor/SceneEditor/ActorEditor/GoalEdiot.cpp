#include"GoalEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/Goal/GoalParam.hpp"
#include"Utility/StringDataCheker.hpp"
#include"GameLib/include/Math/Numbers.hpp"

namespace StageEditor
{
	GoalEditor::GoalEditor(GameLib::Actor* actor)
		:ActorEditorBase{ actor,"Goal",1,1 }
		, mTexture{ "../Assets/Object/Goal/diamond.png" }
	{
		mCollider.SetWidthAndHeith(Stage::GoalParam::COLLIDER_WIDTH, Stage::GoalParam::COLLIDER_HEIGHT);
		mCollider.SetScale(Stage::GoalParam::SCALE);

		mTexture.SetScale(Stage::GoalParam::SCALE);

		auto stringDataChecker = [](int num, const std::string& str) {
			if (num == 0) {
				return IsDir4()(str);
			}
			return false;
		};

		mStringData.SetDataCecker(std::move(stringDataChecker));
	}

	void GoalEditor::Update()
	{
		mTexture.SetPosition(mPosData[0]);
		mCollider.SetPosition(mPosData[0] + GameLib::Vector2{ 0.f,-Stage::GoalParam::COLLIDER_ADJUST_DOWN_SIZE });

		if (mStringData.GetDataNum() == 1)
		{
			float rot;
			if (mStringData[0] == "right")
				rot = GameLib::PI / 2.f;
			else if (mStringData[0] == "up")
				rot = GameLib::PI;
			else if (mStringData[0] == "left")
				rot = GameLib::PI * 3.f / 2.f;

			mTexture.SetRotation(rot);
			mCollider.SetRotation(rot);

			auto adjust = GameLib::Vector2::Rotation(GameLib::Vector2{ 0.f,-Stage::GoalParam::COLLIDER_ADJUST_DOWN_SIZE }, rot);
			mCollider.SetPosition(mPosData[0] + adjust);
		}
	}

	void GoalEditor::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
	}

	void GoalEditor::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
	}

	void GoalEditor::PrintStringDataInfo()
	{
		std::cout << "0: gravity dir4\n";
	}

}