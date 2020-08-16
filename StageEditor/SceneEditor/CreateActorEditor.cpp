#include"CreateActorEditor.hpp"
#include<unordered_map>
#include<functional>
#include"ActorEditor/PlayerEditor.hpp"
#include"ActorEditor/GroundEditor.hpp"
#include"ActorEditor/GuruWarpEditor.hpp"
#include"ActorEditor/CameraEditor.hpp"
#include"ActorEditor/TogeEditor.hpp"
#include"ActorEditor/TripleEditor.hpp"
#include"ActorEditor/GravityBox2Editor.hpp"
#include"ActorEditor/GravityBox4Editor.hpp"
#include"ActorEditor/CircleBeeEditor.hpp"
#include"ActorEditor/StraightBeeEditor.hpp"
#include"ActorEditor/GoalEditor.hpp"
#include"ActorEditor/GemEditor.hpp"
#include"ActorEditor/BlinderEditor.hpp"
#include"ActorEditor/TearGemEditor.hpp"
#include"ActorEditor/FrogEditor.hpp"
#include"ActorEditor/ThroughFloorEditor.hpp"
#include"ActorEditor/MoveGroundEditor.hpp"


namespace StageEditor
{


	namespace {
		std::unordered_map<std::string, std::function<ActorEditorBase* (GameLib::Actor*)>> gActorEditorGenerator = {
			{"Player",[](GameLib::Actor* actor) {return new PlayerEditor{actor}; }},
			{"Ground",[](GameLib::Actor* actor) {return new GroundEditor{actor}; }},
			{"GuruWarp",[](GameLib::Actor* actor) {return new GuruWarpEditor{actor}; }},
			{"Camera",[](GameLib::Actor* actor) {return new CameraEditor{actor}; }},
			{"Toge",[](GameLib::Actor* actor) {return new TogeEditor{actor}; }},
			{"Triple",[](GameLib::Actor* actor) {return new TripleEditor{actor}; }},
			{"GravityBox2",[](GameLib::Actor* actor) {return new GravityBox2Editor{actor}; }},
			{"GravityBox4",[](GameLib::Actor* actor) {return new GravityBox4Editor{actor}; }},
			{"CircleBee",[](GameLib::Actor* actor) {return new CircleBeeEditor{actor}; }},
			{"StraightBee",[](GameLib::Actor* actor) {return new StraightBeeEditor{actor}; }},
			{"Goal",[](GameLib::Actor* actor) {return new GoalEditor{actor}; }},
			{"Gem",[](GameLib::Actor* actor) {return new GemEditor{actor}; }},
			{"Blinder",[](GameLib::Actor* actor) {return new BlinderEditor{actor}; }},
			{"TearGem",[](GameLib::Actor* actor) {return new TearGemEditor{actor}; }},
			{"Frog",[](GameLib::Actor* actor) {return new FrogEditor{actor}; }},
			{"ThroughFloor",[](GameLib::Actor* actor) {return new ThroughFloorEditor{actor}; }},
			{"MoveGround",[](GameLib::Actor* actor) {return new MoveGroundEditor{actor}; }},



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