#include<iostream>
#include<string>
#include<memory>
#include"lib/include/Manager.hpp"

#include <stdlib.h>
#include <crtdbg.h>
#define malloc(X) _malloc_dbg(X,_NORMAL_BLOCK,__FILE__,__LINE__) 
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)


struct Print {
	static void function(std::string* ptr) {
		std::cout << *ptr << "\n";
	}
};

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_DELAY_FREE_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);

	
	auto manager = std::make_unique<GameLib::Manager<std::string>>();

	auto aaa = new std::string("aaa");
	manager->Add(aaa);

	auto bbb = new std::string("bbb");
	manager->Add(bbb);

	auto ccc = new std::string("ccc");
	manager->Add({ ccc,5 });

	auto ddd = new std::string("ddd");
	manager->Add({ ddd,-1 });

	manager->Remove(aaa);
	delete aaa;

	manager->Invoke<Print>();

	return 0;
	
}