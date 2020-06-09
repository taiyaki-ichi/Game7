#include<iostream>
#include<string>
#include<memory>
#include"lib/include/Actor/RootActor.hpp"
#include"lib/include/App.hpp"
#include"lib/include/Component/Draw/AnimComponent/AnimComponent.hpp"
#include"lib/src/Windows/Window.hpp"
#include"lib/include/CollisionDetection/MortonNumber.hpp"
#include"lib/include/Component/Collider/ColliderComponent.hpp"
#include"lib/include/Math/Vector2Func.hpp"
#include"lib/include/Actor/CoordinateActor.hpp"

#include <stdlib.h>
#include <crtdbg.h>
#define malloc(X) _malloc_dbg(X,_NORMAL_BLOCK,__FILE__,__LINE__) 
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

using namespace GameLib;

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_DELAY_FREE_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);

	
	auto app = GameLib::CreatAppPtr({ "window",800,600 });

	auto root = new GameLib::RootActor();
	auto actor = new GameLib::CoordinateActor(root, { 0,0 },0.5f,1.f);
	auto texture = new GameLib::AnimComponent(actor, { "../Assets/run001.png","../Assets/run002.png","../Assets/run003.png","../Assets/run002.png" },1.0);
	auto collder = new ColliderComponent(actor, "", 200.f, 300.f, { 255,0,0,255 });

	app->Start(root);
	

	
	return 0;
	
}