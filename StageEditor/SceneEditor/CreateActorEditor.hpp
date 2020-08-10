#pragma once
#include<string>
#include<vector>

namespace GameLib
{
	class Actor;
}

namespace StageEditor
{
	class ActorEditorBase;
	ActorEditorBase* CreateActorEditor(GameLib::Actor* scene, const std::string& name);

	//helpコマンド用
	std::vector<std::string> GetAllActorEditorName();

}