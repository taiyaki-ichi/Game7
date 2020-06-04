#include<iostream>
#include"Windows/Window.hpp"
#include"Windows/Time.hpp"
#include"Windows/Event.hpp"
#include"Windows/Graphics.hpp"
#include"Windows/Input.hpp"


#include <stdlib.h>
#include <crtdbg.h>
#define malloc(X) _malloc_dbg(X,_NORMAL_BLOCK,__FILE__,__LINE__) 
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)


int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_DELAY_FREE_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);


	GameLib::CreateAppWindow("window", 800.f, 600.f);
	GameLib::InitGraphics();
	GameLib::InitInput();

	auto time = GameLib::GetTime();
	auto waitTime = 1000 / 60;

	bool isRunning = true;

	auto texture = GameLib::LoadTexture("../Assets/icon.png");
	if (!texture) {
		std::cout << "texture load faild\n";
		isRunning = false;
	}

	auto keyBoard = std::make_unique<GameLib::Keyboard>();
	float scale = 0.5f;

	while (isRunning)
	{
		GameLib::Wait(time, waitTime);
		isRunning = GameLib::PollEvent();

		keyBoard->Update();

		//スペース
		if (keyBoard->GetKeyState(0x39) == 1)
			scale += 0.1f;

		GameLib::DrawStart();

		GameLib::GraphicsDrawTexture(texture, 400, 300, 0.f, scale);
		GameLib::GraphicsDrawTexture(texture, 500, 300, 0.5f, 1.f);
		GameLib::GraphicsDrawTexture(texture, 300, 300, 0.f, 0.5f);

		GameLib::DrawEnd();
		
	}

	GameLib::ShutdownGraphics();
	GameLib::ShutdownInput();

	return 0;
	
}