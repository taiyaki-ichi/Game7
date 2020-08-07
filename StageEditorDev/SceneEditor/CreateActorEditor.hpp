#pragma once
#include<string>

namespace GameLib
{
	class Actor;
}

namespace StageEditor
{
	class ActorEditorBase;
	ActorEditorBase* CreateActorEditor(GameLib::Actor* scene, const std::string& name);

}