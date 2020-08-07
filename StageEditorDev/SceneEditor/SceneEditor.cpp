#include"SceneEditor.hpp"
#include"ActorEditor/ActorEditorBase.hpp"

namespace StageEditor
{

	SceneEditor::SceneEditor(GameLib::Actor* actor)
		:GameLib::Actor{actor}
		, mNowActorEditor{nullptr}
	{}


	void SceneEditor::CustomizeUpdate()
	{
		if (mNowActorEditor && mNowActorEditor->IsOK())
			mNowActorEditor = nullptr;
	}

	void SceneEditor::CreateActor(std::string&& actorName)
	{

	}

	bool SceneEditor::IsEdtingActor()
	{
		return mNowActorEditor;
	}

	void SceneEditor::SendToActor(std::string&& str)
	{
		mNowActorEditor->AddData(std::move(str));
	}

	void SceneEditor::SendToActor(GameLib::Vector2&& pos)
	{
		mNowActorEditor->AddData(std::move(pos));
	}

	void SceneEditor::UpdateConsoleScreen()
	{
		if (mNowActorEditor)
			mNowActorEditor->PrintStringData();
	}
}