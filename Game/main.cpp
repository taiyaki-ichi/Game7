#include<iostream>
#include<string>
#include<memory>
#include"lib/include/Actor/RootActor.hpp"
#include"lib/include/App.hpp"
#include"lib/include/Component/BasicActorInfo/BasicActorInfo.hpp"

#include <stdlib.h>
#include <crtdbg.h>
#define malloc(X) _malloc_dbg(X,_NORMAL_BLOCK,__FILE__,__LINE__) 
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)



int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_DELAY_FREE_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);


	auto root = new GameLib::RootActor();
	auto actInfo = new GameLib::BasicActorInfo(root);
	auto app = GameLib::CreatAppPtr({ "window",800,600 });
	app->Start(root);

	return 0;
	
}