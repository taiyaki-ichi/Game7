#include<iostream>
#include<string>
#include<memory>
#include"lib/include/Manager/Manager.hpp"
#include"lib/include/Actor.hpp"
#include"lib/include/Component.hpp"

#include <stdlib.h>
#include <crtdbg.h>
#define malloc(X) _malloc_dbg(X,_NORMAL_BLOCK,__FILE__,__LINE__) 
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)


struct Print {
	static void func(GameLib::Actor* actor) {
		std::cout << actor->GetUpdateOrder() << "\n";
	}

	void operator()(GameLib::Actor* actor) {
		std::cout << actor->GetUpdateOrder() << "\n";
	}
};

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_DELAY_FREE_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);


	auto root = new GameLib::Actor(nullptr);

	
	auto aaa = new GameLib::Actor(root, 100);
	auto aaaComponent = new GameLib::Component(aaa, 100);

	auto bbb = new GameLib::Actor(root, 50);
	auto ccc = new GameLib::Actor(root, 150);

	root->InvokeOwnedActors<Print>();

	delete bbb;

	root->InvokeOwnedActors<Print>();
	
	delete root;

	return 0;
	
}