#include<iostream>
#include<string>
#include<memory>
#include"lib/include/Actor/RootActor.hpp"
#include"lib/include/App.hpp"
#include"lib/include/Component/CoordinateInfoInfo/CoordinateInfo.hpp"
#include"lib/include/Component/Draw/AnimComponent/AnimComponent.hpp"
#include"lib/src/Windows/Window.hpp"
#include"lib/include/Component/Collider/ColliderComponent.hpp"
#include"lib/include/Math/Vector2Func.hpp"

#include <stdlib.h>
#include <crtdbg.h>
#define malloc(X) _malloc_dbg(X,_NORMAL_BLOCK,__FILE__,__LINE__) 
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

using namespace GameLib;

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_DELAY_FREE_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);

	
	auto app = GameLib::CreatAppPtr({ "window",800,600 });

	auto root = new GameLib::RootActor();
	auto rootInfo = new GameLib::CoordinateInfo(root, { 0,0 },0.5f,0.1f);
	auto texture = new GameLib::AnimComponent(rootInfo, { "../Assets/run001.png","../Assets/run002.png","../Assets/run003.png","../Assets/run002.png" },1.0);
	auto collder = new ColliderComponent(rootInfo, "", 200.f, 300.f, { 255,0,0,255 });

	app->Start(root);
	
	//aaaaa

	return 0;
	
}