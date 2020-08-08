#pragma once
#include<string>
#include<unordered_map>

namespace Stage
{
	class ActorBase;
	class Scene;
	class WarpBase;

	//PlayerˆÈŠO‚ğ‚±‚±‚Å¶¬
	ActorBase* CreateStageActor(Scene* scene, std::string&& nameTag);



}