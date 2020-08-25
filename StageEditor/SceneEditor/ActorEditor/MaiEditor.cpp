#include"MaiEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/Mai/MaiParam.hpp"

namespace StageEditor
{
	MaiEditor::MaiEditor(GameLib::Actor* actor,std::string&& dir)
		:ActorEditorBase{ actor,dir + "Mai",1,0 }
		, mTexture{ "../Assets/Enemy/Mai/stay001.png" }
	{
		mTexture.SetScale(Stage::MaiParam::SCALE);

		mCollider.SetWidthAndHeith(Stage::MaiParam::WIDTH, Stage::MaiParam::HEIGHT);
		mCollider.SetScale(Stage::MaiParam::SCALE);

		float rot = 0.f;
		if (dir == "Right")
			rot = GameLib::PI / 2.f;
		else if (dir == "Left")
			rot = GameLib::PI / 2.f * 3.f;
		else if (dir == "Up")
			rot = GameLib::PI;

		mTexture.SetRotation(rot);
		mCollider.SetRotation(rot);
	}

	void MaiEditor::Update()
	{
		mTexture.SetPosition(mPosData[0]);

		GameLib::Vector2 adjust{ 0.f,-Stage::MaiParam::ADJUST_COLLIDER_DOWN };
		adjust = GameLib::Vector2::Rotation(adjust, mTexture.GetRotation());
		mCollider.SetPosition(mPosData[0] + adjust);
	}

	void MaiEditor::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
	}

	void MaiEditor::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
	}
}