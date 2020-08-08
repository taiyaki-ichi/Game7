#include"SceneEditor.hpp"
#include"ActorEditor/ActorEditorBase.hpp"
#include"CreateActorEditor.hpp"

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
		CreateActorEditor(this, std::move(actorName));
	}

	bool SceneEditor::IsEdtingActor()
	{
		return mNowActorEditor;
	}

	void SceneEditor::ForwardStringData(std::string&& str)
	{
		mNowActorEditor->ForwardStringData(std::move(str));
	}



	void SceneEditor::UpdateConsoleScreen()
	{
		if (mNowActorEditor)
			mNowActorEditor->PrintStringData();
	}
}