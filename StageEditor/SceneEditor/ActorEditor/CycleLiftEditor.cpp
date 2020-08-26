#include"CycleLiftEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/CycleLift/CycleLiftParam.hpp"
#include"Stage/SceneManager/Scene/Actor/Lift/LiftParam.hpp"

namespace StageEditor
{
	CycleLiftEditor::CycleLiftEditor(GameLib::Actor* actor)
		:ActorEditorBase{actor,"CycleLift",1,1}
		, mCircle{}
		, mLift1{"../Assets/Object/Lift/001.png"}
		, mLift2{ "../Assets/Object/Lift/001.png" }
		, mLift3{ "../Assets/Object/Lift/001.png" }
		, mLift4{ "../Assets/Object/Lift/001.png" }
	{
		using namespace Stage::CycleLiftParam;

		mCircle.SetRadius(CENTER_RADIUS);

		mCollider.SetWidthAndHeith(CENTER_RADIUS * 2.f, CENTER_RADIUS * 2.f);

		mLift1.SetScale(Stage::LiftParam::SCLAE);
		mLift2.SetScale(Stage::LiftParam::SCLAE);
		mLift3.SetScale(Stage::LiftParam::SCLAE);
		mLift4.SetScale(Stage::LiftParam::SCLAE);

		auto checker = [](int n, const std::string& str)
		{
			if (n == 0)
			{
				if (str == "false" || str == "true")
					return true;
				else
					return false;
			}

			return true;
		};

		mStringData.SetDataCecker(std::move(checker));
	}

	void CycleLiftEditor::Update()
	{
		mCollider.SetPosition(mPosData[0]);
		mCircle.SetPosition(mPosData[0]);

		using namespace GameLib;
		GameLib::Vector2 adjust{ Stage::CycleLiftParam::RADIUS,0.f };
		mLift1.SetPosition(mPosData[0] + adjust);
		mLift2.SetPosition(mPosData[0] + Vector2::Rotation(adjust, PI / 2.f));
		mLift3.SetPosition(mPosData[0] + Vector2::Rotation(adjust, PI));
		mLift4.SetPosition(mPosData[0] + Vector2::Rotation(adjust, PI / 2.f * 3.f));
	}

	void CycleLiftEditor::BeginWorking()
	{
		mCircle.SetIsAutoDrawing(true);
		mLift1.SetIsAutoDrawing(true);
		mLift2.SetIsAutoDrawing(true);
		mLift3.SetIsAutoDrawing(true);
		mLift4.SetIsAutoDrawing(true);
	}

	void CycleLiftEditor::BeginToRest()
	{
		mCircle.SetIsAutoDrawing(false);
		mLift1.SetIsAutoDrawing(false);
		mLift2.SetIsAutoDrawing(false);
		mLift3.SetIsAutoDrawing(false);
		mLift4.SetIsAutoDrawing(false);
	}

	void CycleLiftEditor::PrintStringDataInfo()
	{
		std::cout << "0: is clockwise (true or false)\n";
	}
}