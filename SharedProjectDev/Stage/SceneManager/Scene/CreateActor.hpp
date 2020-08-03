#pragma once
#include<string>

namespace Stage
{
	class ActorBase;
	class Scene;
	class WarpBase;

	//PlayerˆÈŠO‚ğ‚±‚±‚Å¶¬
	ActorBase* CreateStageActor(Scene* scene, std::string&& nameTag);

	//Warp‚Í‚±‚±‚Å
	WarpBase* CreateStageWarp(Scene* scene, std::string&& warpType, std::string&& myNameTag, std::string&& destinationNameTag);

}