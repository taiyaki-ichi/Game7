#include"CreateActor.hpp"
#include<functional>
#include"StageScene.hpp"
#include"Actor/Ground.hpp"
#include"Actor/Camera.hpp"
#include"Actor/WarpBase.hpp"
#include"Actor/GuruWarp.hpp"
#include"Actor/GravityBox.hpp"
#include"Actor/Triple.hpp"
#include"Actor/Toge.hpp"
#include"Actor/Bee.hpp"
#include"Actor/Goal.hpp"
#include"Actor/Diamond.hpp"
#include"Actor/Blinder.hpp"

namespace Stage
{
	namespace {

		//Actorê∂ê¨
		const std::unordered_map<std::string, std::function<ActorBase* (Scene*)>> ActorPtrGenerator =
		{
			{"Ground",[](Scene* scene) {return new GroundGenerator{scene}; }},
			{"Camera",[](Scene* scene) {return new Camera{scene}; }},
			{"GravityBox2",[](Scene* scene) {return new GravityBox{scene,2}; }},
			{"GravityBox4",[](Scene* scene) {return new GravityBox{scene,4}; }},
			{"Triple",[](Scene* scene) {return new Triple{scene}; }},
			{"Toge",[](Scene* scene) {return new Toge{scene}; }},
			{"StraightBee",[](Scene* scene) {return new Bee{scene}; }},
			{"CircleBee",[](Scene* scene) {return new Bee{scene}; }},
			{"GuruWarp",[](Scene* scene) {return new GuruWarp{scene}; }},
			{"Goal",[](Scene* scene) {return new Goal{scene}; }},
			{"Diamond",[](Scene* scene) {return new Diamond{scene}; }},
			{"Blinder",[](Scene* scene) {return new Blinder{scene}; }},

		};

	}






	ActorBase* CreateStageActor(Scene* scene, std::string&& name)
	{
		auto i = ActorPtrGenerator.find(name);
		if (i != ActorPtrGenerator.end())
			return i->second(scene);

		return nullptr;

	}

}