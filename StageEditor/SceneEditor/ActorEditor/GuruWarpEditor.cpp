#include"GuruWarpEditor.hpp"

namespace StageEditor
{
	GuruWarpEditor::GuruWarpEditor(GameLib::Actor* actor)
		:ActorEditorBase{ actor,"GuruWarp",1,2 }
		, mTexture{ "../Assets/Object/WarpGate/grugru.png" }
	{
		mCollider.SetWidthAndHeith(50.f, 50.f);
		mTexture.SetScale(0.1f);
	}

	void GuruWarpEditor::Update()
	{
		int num = mPosData.GetDataNum();
		if (num == 1)
		{
			mCollider.SetPosition(mPosData[0]);
			mTexture.SetPosition(mPosData[0]);
		}
	}

	void GuruWarpEditor::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
	}

	void GuruWarpEditor::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
	}

	void GuruWarpEditor::PrintStringDataInfo()
	{
		std::cout << "\n";
		std::cout << "0 : my name tag\n";
		std::cout << "1 : destination name tag\n\n";
	}
}