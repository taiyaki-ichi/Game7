#include<iostream>
#include<string>
#include<memory>
#include"lib/include/Actor/RootActor.hpp"
#include"lib/include/App.hpp"
#include"lib/include/Component/BasicActorInfo/BasicActorInfo.hpp"
#include"lib/include/Component/Draw/TextureComponent/Texturecomponent.hpp"

#include <stdlib.h>
#include <crtdbg.h>
#define malloc(X) _malloc_dbg(X,_NORMAL_BLOCK,__FILE__,__LINE__) 
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)



int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_DELAY_FREE_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);

	auto app = GameLib::CreatAppPtr({ "window",800,600 });

	auto root = new GameLib::RootActor();
	auto rootInfo = new GameLib::BasicActorInfo(root, { 400,300 },1.f);
	auto texture = new GameLib::TextureComponent(rootInfo, "../Assets/icon.png");

	app->Start(root);

	return 0;
	
}