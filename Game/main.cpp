
#include<memory>
#include"GameLib/include/App.hpp"
#include"Game.hpp"
#include"Stage/WindowSize.hpp"

#include<Windows.h>

/*
//デバック用
#include <stdlib.h>
#include <crtdbg.h>
#define malloc(X) _malloc_dbg(X,_NORMAL_BLOCK,__FILE__,__LINE__) 
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

int main() 
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_DELAY_FREE_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);

	auto app = GameLib::CreatAppPtr({ "game",Stage::WindowSize::WIDTH,Stage::WindowSize::HEIGHT });
	app->Start<Game::Game>();

	return 0;
}
*/


int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)
{
	auto app = GameLib::CreatAppPtr({ "MEME",Stage::WindowSize::WIDTH,Stage::WindowSize::HEIGHT });
	app->Start<Game::Game>();

	return 0;
}

