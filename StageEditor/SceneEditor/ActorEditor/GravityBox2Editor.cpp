#include"GravityBox2Editor.hpp"
#include"Stage/SceneManager/Scene/Actor/GravityBox/GravityBoxParam.hpp"
#include"GameLib/include/Math/Numbers.hpp"

namespace StageEditor
{
	
	GravityBox2Editor::GravityBox2Editor(GameLib::Actor* actor)
		:ActorEditorBase{actor,"GravityBox2",1,1}
		, mBox{ "../Assets/Object/GravityBox/box2.png" }
		, mApple{ "../Assets/Object/GravityBox/apple.png" }
	{
		mApple.SetScale(Stage::GravityBoxParam::AppleParam::SCALE);
		mApple.SetDrawOrder(1);

		mBox.SetScale(Stage::GravityBoxParam::SCALE);

		mCollider.SetScale(Stage::GravityBoxParam::SCALE);
		mCollider.SetWidthAndHeith(Stage::GravityBoxParam::WIDTH, Stage::GravityBoxParam::HEIGHT);

		auto stringDataChecker = [](int n, const std::string& str)->bool {
			if (n == 0) {
				if (str == "right" || str == "left" || str == "up" || str == "down")
					return true;
				else
					return false;
			}
			return false;
		};

		mStringData.SetDataCecker(std::move(stringDataChecker));
	}

	void GravityBox2Editor::Update()
	{
		mBox.SetPosition(mPosData[0]);
		mApple.SetPosition(mPosData[0]);
		mCollider.SetPosition(mPosData[0]);

		if (mStringData.GetDataNum() == 1)
		{
			float d = Stage::GravityBoxParam::AppleParam::MOVE_LENGTH;
			if (mStringData[0] == "right") {
				mApple.SetPosition(mPosData[0] + GameLib::Vector2{ d,0.f });
				mBox.SetRotation(GameLib::PI / 2.f);
			}
			else if (mStringData[0] == "left") {
				mApple.SetPosition(mPosData[0] + GameLib::Vector2{ -d,0.f });
				mBox.SetRotation(GameLib::PI / 2.f);
			}
			else if (mStringData[0] == "up")
				mApple.SetPosition(mPosData[0] + GameLib::Vector2{ 0.f,d });
			else if (mStringData[0] == "down")
				mApple.SetPosition(mPosData[0] + GameLib::Vector2{ 0.f,-d });
		}
	}

	void GravityBox2Editor::BeginWorking()
	{
		mBox.SetIsAutoDrawing(true);
		mApple.SetIsAutoDrawing(true);
	}

	void GravityBox2Editor::BeginToRest()
	{
		mBox.SetIsAutoDrawing(false);
		mApple.SetIsAutoDrawing(false);
	}

	void GravityBox2Editor::PrintStringDataInfo()
	{
		std::cout << "0: right or left or up or down (first change dir)\n";
	}
	
}