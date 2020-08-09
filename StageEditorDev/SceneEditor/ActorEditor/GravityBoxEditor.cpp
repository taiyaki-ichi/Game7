#include"GravityBoxEditor.hpp"
#include"GameLib/include/Math/Numbers.hpp"

namespace StageEditor
{

	GravityBoxEditor::GravityBoxEditor(GameLib::Actor* actor)
		:ActorEditorBase{actor,"GravityBox",1,2}
		, mTexture2{ "../Assets/Object/GravityBox/box2.png" }
		, mTexture4{ "../Assets/Object/GravityBox/box4.png" }
		, mApple{ "../Assets/Object/GravityBox/apple.png" }
	{
		mTexture2.SetScale(0.1f);
		mTexture4.SetScale(0.1f);

		mTexture2.SetIsAutoDrawing(false);

		mApple.SetScale(0.09f);
		mApple.SetDrawOrder(1);

		mCollider.SetWidthAndHeith(76.f, 76.f);

		auto dataChecker = [](int num, const std::string& str)->bool {
			if (num == 0) {
				if (str == "2" || str == "4")
					return true;
				else
					return false;
			}
			if (num == 1) {
				if (str == "right" || str == "left" || str == "up" || str == "down")
					return true;
				else
					return false;
			}
			return false;
		};
		mStringData.SetDataCecker(std::move(dataChecker));

	}

	void GravityBoxEditor::Update()
	{
		
		mTexture2.SetPosition(mPosData[0]);
		mTexture4.SetPosition(mPosData[0]);

		mCollider.SetPosition(mPosData[0]);

		mApple.SetPosition(mPosData[0]);
		

		auto stringNum = mStringData.GetDataNum();
		if (stringNum >= 1)
		{
			if (mStringData[0] == "2") {
				mTexture2.SetIsAutoDrawing(true);
				mTexture4.SetIsAutoDrawing(false);
			}
			else if (mStringData[0] == "4")
			{
				mTexture2.SetIsAutoDrawing(false);
				mTexture4.SetIsAutoDrawing(true);
			}
		}
		
		if (stringNum == 2)
		{
			if (mStringData[1] == "right")
			{
				mApple.SetPosition(mPosData[0] + GameLib::Vector2{ 15.f,0.f });
				mTexture2.SetRotation(GameLib::PI / 2.f);
			}
			else if (mStringData[1] == "left")
			{
				mApple.SetPosition(mPosData[0] + GameLib::Vector2{ -15.f,0.f });
				mTexture2.SetRotation(GameLib::PI / 2.f);
			}
			else if (mStringData[1] == "up")
			{
				mApple.SetPosition(mPosData[0] + GameLib::Vector2{ 0.f,15.f });
			}
			else //if (mStringData[1] == "down")
			{
				mApple.SetPosition(mPosData[0] + GameLib::Vector2{ 0.f,-15.f });
			}

		}
	}

	void GravityBoxEditor::BeginWorking()
	{
		auto stringNum = mStringData.GetDataNum();
		if (stringNum >= 1)
		{
			if (mStringData[0] == "2") {
				mTexture2.SetIsAutoDrawing(true);
				mTexture4.SetIsAutoDrawing(false);
			}
			else if (mStringData[0] == "4")
			{
				mTexture2.SetIsAutoDrawing(false);
				mTexture4.SetIsAutoDrawing(true);
			}
		}

		mApple.SetIsAutoDrawing(true);
	}

	void GravityBoxEditor::BeginToRest()
	{
		mTexture2.SetIsAutoDrawing(false);
		mTexture4.SetIsAutoDrawing(false);
		mApple.SetIsAutoDrawing(true);
	}

	void GravityBoxEditor::PrintStringDataInfo()
	{
		std::cout << "0: 2 or 4  (change gravity dir)\n";
		std::cout << "1: right or left or up or down (first change dir)\n";
	}

}
