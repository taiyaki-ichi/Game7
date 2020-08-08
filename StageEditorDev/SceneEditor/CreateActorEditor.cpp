#include"CreateActorEditor.hpp"
#include<unordered_map>
#include<functional>

namespace StageEditor
{


	namespace {
		std::unordered_map<std::string, std::function<ActorEditorBase* (GameLib::Actor*)>> gActorEditorGenerator = {

		};
	}




	ActorEditorBase* CreateActorEditor(GameLib::Actor* scene, const std::string& name)
	{

		auto iter = gActorEditorGenerator.find(name);

		if (iter != gActorEditorGenerator.end())
			return iter->second(scene);


		return nullptr;
	}

	std::vector<std::string> GetAllActorEditorName()
	{
		std::vector<std::string> names{};
		for (auto& actor : gActorEditorGenerator)
			names.emplace_back(actor.first);

		return names;
	}
}