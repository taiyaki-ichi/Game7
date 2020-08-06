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

namespace Stage
{
	namespace {

		//Actorê∂ê¨
		const std::unordered_map<std::string, std::function<ActorBase* (Scene*)>> ActorPtrGenerator =
		{
			{"Ground",[](Scene* scene) {return new GroundGenerator{scene}; }},
			{"Camera",[](Scene* scene) {return new Camera{scene}; }},
			{"GravityBox",[](Scene* scene) {return new GravityBox{scene}; }},
			{"Triple",[](Scene* scene) {return new Triple{scene}; }},
			{"Toge",[](Scene* scene) {return new Toge{scene}; }},
			{"Bee",[](Scene* scene) {return new Bee{scene}; }},

		};

		//WarpTypeÇ©ÇÁWarpê∂ê¨
		const std::unordered_map<std::string, std::function<WarpBase* (Scene*)>> WarpPtrGenerator =
		{
			{"Guru",[](Scene* scene) {return new GuruWarp{scene}; }}
		};

	}




	WarpBase* CreateStageWarp(Scene* scene, std::unordered_map<std::string, std::string>&& staringData);

	ActorBase* CreateStageActor(Scene* scene, std::string&& name, std::unordered_map<std::string, std::string>&& stringData)
	{
	
		if (name == "Warp")
			return CreateStageWarp(scene, std::move(stringData));

		auto i = ActorPtrGenerator.find(name);
		if (i != ActorPtrGenerator.end())
			return i->second(scene);



		return nullptr;

	}


	WarpBase* CreateStageWarp(Scene* scene, std::unordered_map<std::string, std::string>&& staringData)
	{
		auto warpType = staringData[WarpBase::TYPE];
		auto nameTag = staringData[WarpBase::NAMETAG];
		auto destinationNameTag = staringData[WarpBase::DESTINATION_NAMETAG];

		auto i = WarpPtrGenerator.find(warpType);
		if (i != WarpPtrGenerator.end()) {
			auto ptr = i->second(scene);

			//nameTagÇÃê›íËÇ∆destinationÇÃê›íË
			
			ptr->SetThisNameTag(std::move(nameTag));
			ptr->SetDestinationNameTag(std::move(destinationNameTag));

			return ptr;
		}
		
		return nullptr;
	}

}