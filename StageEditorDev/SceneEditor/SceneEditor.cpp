#include"SceneEditor.hpp"

namespace StageEditor
{

	SceneEditor::SceneEditor(GameLib::Actor* actor)
		:GameLib::Actor{actor}
	{}

	void SceneEditor::CreateActor(std::string&& actorName)
	{

	}

	bool SceneEditor::IsEdtingActor()
	{
		return false;
	}

	void SceneEditor::MessageToActor(std::string&& str)
	{

	}

	void SceneEditor::BeginWorking()
	{

	}

	void SceneEditor::BeginToRest()
	{

	}

	void SceneEditor::UpdateConsoleScreen()
	{

	}
}