#pragma once
#include<string>

namespace Stage
{
	class ActorBase;
	class Scene;

	//PlayerˆÈŠO‚ğ‚±‚±‚Å¶¬
	ActorBase* CreateStageActor(Scene* scene, std::string&& nameTag);

}