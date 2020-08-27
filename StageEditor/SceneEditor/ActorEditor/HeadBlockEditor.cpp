#include"HeadBlockEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/HeadBlock/HeadBlockParam.hpp"

namespace StageEditor
{
	HeadBlockEditor::HeadBlockEditor(GameLib::Actor* actor)
		:ActorEditorBase{actor,"HeadBlock",1,0}
		, mTexture{ "../Assets/Object/HeadBlock/stay.png" }
		, mRect{}
	{
		mRect.SetColor({ 255,255,255,255 });
		mRect.SetDrawOrder(-1);
		
		using namespace Stage::HeadBlockParam;
		mRect.SetWidthAndHeight(WIDTH, HEIGHT);
		mRect.SetScale(SCALE);

		mTexture.SetScale(SCALE);

		mCollider.SetWidthAndHeith(WIDTH, HEIGHT);
		mCollider.SetScale(SCALE);
	}

	void HeadBlockEditor::Update()
	{
		mRect.SetPosition(mPosData[0]);
		mTexture.SetPosition(mPosData[0]);
		mCollider.SetPosition(mPosData[0]);
	}

	void HeadBlockEditor::BeginWorking()
	{
		mRect.SetIsAutoDrawing(true);
		mTexture.SetIsAutoDrawing(true);
	}

	void HeadBlockEditor::BeginToRest()
	{
		mRect.SetIsAutoDrawing(false);
		mTexture.SetIsAutoDrawing(false);
	}
}