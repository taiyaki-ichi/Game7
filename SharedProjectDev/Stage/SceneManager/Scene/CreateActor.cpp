#include"CreateActor.hpp"
#include"StageScene.hpp"
#include"Actor/Ground.hpp"
#include"Actor/Camera.hpp"


namespace Stage
{

	ActorBase* CreateStageActor(Scene* scene, std::string&& name)
	{
		
		if (name == "Ground")
			return new GroundGenerator{ scene };
		if (name == "Camera")
			return new Camera{ scene };



		return nullptr;

	}

	WarpBase* CreateStageWarp(Scene* scene, std::string&& warpType, std::string&& myNameTag, std::string&& destinationNameTag)
	{
		return nullptr;
	}

}