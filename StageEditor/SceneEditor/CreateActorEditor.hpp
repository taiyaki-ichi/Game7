#pragma once
#include<string>
#include<vector>

namespace StageEditor
{
	class ActorEditorBase;
	class SceneEditor;

	ActorEditorBase* CreateActorEditor(SceneEditor* sceneEditor, const std::string& actorName, std::vector<float>&& data = {});
}