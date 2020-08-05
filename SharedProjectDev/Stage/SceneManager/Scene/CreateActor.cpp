#include"CreateActor.hpp"
#include"StageScene.hpp"
#include"Actor/Ground.hpp"
#include"Actor/Camera.hpp"
#include"Actor/WarpBase.hpp"
#include<functional>

namespace Stage
{
	namespace {

		//Actorê∂ê¨
		const std::unordered_map<std::string, std::function<ActorBase* (Scene*)>> ActorPtrGenerator =
		{
			{"Ground",[](Scene* scene) {return new GroundGenerator{scene}; }},
			{"Camera",[](Scene* scene) {return new Camera{scene}; }}



		};

		//WarpTypeÇ©ÇÁWarpê∂ê¨
		const std::unordered_map<std::string, std::function<WarpBase* (Scene*)>> WarpPtrGenerator =
		{

		};

	}




	WarpBase* CreateStageWarp(Scene* scene, std::unordered_map<std::string, std::string>&& staringData);

	ActorBase* CreateStageActor(Scene* scene, std::string&& name, std::unordered_map<std::string, std::string>&& stringData)
	{
		
		auto i = ActorPtrGenerator.find(name);
		if (i != ActorPtrGenerator.end())
			return i->second(scene);

		if (name == "Warp")
			return CreateStageWarp(scene, std::move(stringData));



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

			return ptr;
		}
		
		return nullptr;
	}

}