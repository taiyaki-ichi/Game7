#include"SceneEditor.hpp"
#include"ActorEditor/ActorEditorBase.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"StageEditor/Console/ConsoleMessage.hpp"
#include"CreateActorEditor.hpp"

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

		if (mNowEditingActor == nullptr)
		{
			auto strings = ConsoleMessage::GetStrings();

			if (strings.size() == 1) {
				mNowEditingActor = CreateActorEditor(this, strings[0]);
			}
		}


		if (mNowEditingActor && mNowEditingActor->IsOK())
			mNowEditingActor = nullptr;

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

	SceneData SceneEditor::GetData()
	{
		SceneData actorData;
		for (auto iter = mActorEditors.begin(); iter != mActorEditors.end(); iter++)
			actorData.emplace_back((*iter)->GetData());

		return actorData;
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

	bool SceneEditor::IsNowEditingActor()
	{
		return mNowEditingActor != nullptr;
	}
	
}