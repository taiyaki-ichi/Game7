#include"TrampolineEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/Trampoline/TrampolineParam.hpp"

namespace StageEditor
{
	TrampolineEditor::TrampolineEditor(GameLib::Actor* actor, std::string&& dir)
		:ActorEditorBase{ actor ,dir + "Trampoline",1,0 }
		, mTexture{ "../Assets/Object/Trampoline/001.png" }
	{
		mTexture.SetScale(Stage::TrampolineParam::SCALE);

		mCollider.SetScale(Stage::TrampolineParam::SCALE);
		mCollider.SetWidthAndHeith(Stage::TrampolineParam::WIDTH, Stage::TrampolineParam::HEIGHT);

		float rot = 0.f;
		if (dir == "Right")
			rot = GameLib::PI * 3.f / 2.f;
		else if (dir == "Down")
			rot = GameLib::PI;
		else if (dir == "Left")
			rot = GameLib::PI / 2.f;

		mTexture.SetRotation(rot);
		mCollider.SetRotation(rot);
	}

	void TrampolineEditor::Update()
	{
		mTexture.SetPosition(mPosData[0]);
		mCollider.SetPosition(mPosData[0]);
	}

	void TrampolineEditor::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
	}

	void TrampolineEditor::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
	}
}