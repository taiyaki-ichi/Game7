#include"SceneEditor.hpp"
#include"ActorEditor/ActorEditorBase.hpp"

namespace StageEditor
{
	SceneEditor::SceneEditor(GameLib::Actor* owenr)
		:GameLib::Actor(owenr)
		, mNowEditingActor{nullptr}
	{
		Pause();
	}

	void SceneEditor::CustomizeUpdate()
	{



	}

	void SceneEditor::AddActorEditor(ActorEditorBase* actor)
	{
		mActorEditors.emplace_back(actor);
	}

	void SceneEditor::RemoveActorEditor(ActorEditorBase* actor)
	{
		auto i = std::find(mActorEditors.begin(), mActorEditors.end(), actor);
		if (i != mActorEditors.end())
			mActorEditors.erase(i);
	}

	std::vector<ActorData> SceneEditor::GetActorDataObject()
	{
		std::vector<ActorData> actorDatas;
		for (int i = 0; i < mActorEditors.size(); i++)
			actorDatas.emplace_back(mActorEditors[i]->GetDateObject());
		return actorDatas;
	}
	void SceneEditor::Active()
	{
		SetState(Actor::State::Active);
		for (auto& actor : mActorEditors)
			actor->Active();
	}
	void SceneEditor::Pause()
	{
		SetState(Actor::State::Pause);
		for (auto& actor : mActorEditors)
			actor->Pause();
	}
	
}