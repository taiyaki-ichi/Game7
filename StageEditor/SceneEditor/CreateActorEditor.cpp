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
#include"ActorEditor/CarrotEditor.hpp"
#include"ActorEditor/DoguEditor.hpp"
#include"ActorEditor/TrampolineEditor.hpp"
#include"ActorEditor/MaiEditor.hpp"
#include"ActorEditor/TogeBlockEditor.hpp"
#include"ActorEditor/CycleLiftEditor.hpp"
#include"ActorEditor/MoveLiftEditor.hpp"
#include"ActorEditor/HeadBlockEditor.hpp"
#include"ActorEditor/StandEditor.hpp"
#include"ActorEditor/IceGroundEditor.hpp"





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
			{"DownGoal",[](GameLib::Actor* actor) {return new GoalEditor{actor,"Down"}; }},
			{"UpGoal",[](GameLib::Actor* actor) {return new GoalEditor{actor,"Up"}; }},
			{"RightGoal",[](GameLib::Actor* actor) {return new GoalEditor{actor,"Right"}; }},
			{"LeftGoal",[](GameLib::Actor* actor) {return new GoalEditor{actor,"Left"}; }},
			{"Gem",[](GameLib::Actor* actor) {return new GemEditor{actor}; }},
			{"Blinder",[](GameLib::Actor* actor) {return new BlinderEditor{actor}; }},
			{"TearGem",[](GameLib::Actor* actor) {return new TearGemEditor{actor}; }},
			{"Frog",[](GameLib::Actor* actor) {return new FrogEditor{actor}; }},
			{"ThroughFloor",[](GameLib::Actor* actor) {return new ThroughFloorEditor{actor}; }},
			{"MoveGround",[](GameLib::Actor* actor) {return new MoveGroundEditor{actor}; }},
			{"Carrot",[](GameLib::Actor* actor) {return new CarrotEditor{actor}; }},
			{"Dogu",[](GameLib::Actor* actor) {return new DoguEditor{actor}; }},
			{"UpTrampoline",[](GameLib::Actor* actor) {return new TrampolineEditor{actor,"Up"}; }},
			{"DownTrampoline",[](GameLib::Actor* actor) {return new TrampolineEditor{actor,"Down"}; }},
			{"RightTrampoline",[](GameLib::Actor* actor) {return new TrampolineEditor{actor,"Right"}; }},
			{"LeftTrampoline",[](GameLib::Actor* actor) {return new TrampolineEditor{actor,"Left"}; }},
			{"DownMai",[](GameLib::Actor* actor) {return new MaiEditor{actor,"Down"}; }},
			{"RightMai",[](GameLib::Actor* actor) {return new MaiEditor{actor,"Right"}; }},
			{"LeftMai",[](GameLib::Actor* actor) {return new MaiEditor{actor,"Left"}; }},
			{"UpMai",[](GameLib::Actor* actor) {return new MaiEditor{actor,"Up"}; }},
			{"TogeBlock",[](GameLib::Actor* actor) {return new TogeBlockEditor{actor}; }},
			{"CycleLift",[](GameLib::Actor* actor) {return new CycleLiftEditor{actor}; }},
			{"MoveLift",[](GameLib::Actor* actor) {return new MoveLiftEditor{actor}; }},
			{"HeadBlock",[](GameLib::Actor* actor) {return new HeadBlockEditor{actor}; }},
			{"RightStand",[](GameLib::Actor* actor) {return new StandEditor{actor,"Right"}; }},
			{"LeftStand",[](GameLib::Actor* actor) {return new StandEditor{actor,"Left"}; }},
			{"UpStand",[](GameLib::Actor* actor) {return new StandEditor{actor,"Up"}; }},
			{"DownStand",[](GameLib::Actor* actor) {return new StandEditor{actor,"Down"}; }},
			{"IceGround",[](GameLib::Actor* actor) {return new IceGroundEditor{actor}; }},




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