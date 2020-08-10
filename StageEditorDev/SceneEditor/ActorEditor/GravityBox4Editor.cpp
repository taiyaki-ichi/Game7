#include"GravityBox4Editor.hpp"
#include"Stage/SceneManager/Scene/Actor/GravityBox/GravityBoxParam.hpp"

namespace StageEditor
{
	GravityBox4Editor::GravityBox4Editor(GameLib::Actor* actor)
		:ActorEditorBase{actor,"GravityBox4",1,2}
		, mBox{ "../Assets/Object/GravityBox/box4.png" }
		, mApple{ "../Assets/Object/GravityBox/apple.png" }
	{
		mApple.SetScale(Stage::GravityBoxParam::AppleParam::SCALE);
		mApple.SetDrawOrder(1);

		mBox.SetScale(Stage::GravityBoxParam::SCALE);

		mCollider.SetScale(Stage::GravityBoxParam::SCALE);
		mCollider.SetWidthAndHeith(Stage::GravityBoxParam::WIDTH, Stage::GravityBoxParam::HEIGHT);

		auto stringDataChecker = [](int n, const std::string& str)->bool {
			if (n == 0)
			{
				if (str == "right" || str == "left")
					return true;
				else
					return false;
			}
			if (n == 1) {
				if (str == "right" || str == "left" || str == "up" || str == "down")
					return true;
				else
					return false;
			}
			return false;
		};

		mStringData.SetDataCecker(std::move(stringDataChecker));
	}

	void GravityBox4Editor::Update()
	{
		mCollider.SetPosition(mPosData[0]);
		mBox.SetPosition(mPosData[0]);
		mApple.SetPosition(mPosData[0]);

		if (mStringData.GetDataNum() > 0)
		{
			if (mStringData[0] == "right")
				mBox.SetHorizontalFlip(true);
		}

		if (mStringData.GetDataNum() == 2)
		{
			float d = Stage::GravityBoxParam::AppleParam::MOVE_LENGTH;
			if (mStringData[1] == "right")
				mApple.SetPosition(mPosData[0] + GameLib::Vector2{ d,0.f });
			else if (mStringData[1] == "left")
				mApple.SetPosition(mPosData[0] + GameLib::Vector2{ -d,0.f });
			else if (mStringData[1] == "up")
				mApple.SetPosition(mPosData[0] + GameLib::Vector2{ 0.f,d });
			else if (mStringData[1] == "down")
				mApple.SetPosition(mPosData[0] + GameLib::Vector2{ 0.f,-d });
		}
	}

	void GravityBox4Editor::BeginWorking()
	{
		mBox.SetIsAutoDrawing(true);
		mApple.SetIsAutoDrawing(true);
	}

	void GravityBox4Editor::BeginToRest()
	{
		mBox.SetIsAutoDrawing(false);
		mApple.SetIsAutoDrawing(false);
	}

	void GravityBox4Editor::PrintStringDataInfo()
	{
		std::cout << "0: right or left (rotation dir)\n";
		std::cout << "1: right or left or up or down (first change dir)\n";
	}
}