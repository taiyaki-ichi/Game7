#include<iostream>
#include<string>
#include<memory>
#include"lib/include/Actor/RootActor.hpp"
#include"lib/include/App.hpp"
#include"lib/src/Windows/Window.hpp"
#include"lib/include/Math/Vector2Func.hpp"
#include"lib/include/Draw/DrawTexture.hpp"
#include"lib/include/Draw/DrawFillTriangle.hpp"
#include"lib/include/Viewport/Viewport.hpp"
#include"lib/include/Draw/DrawFillTriangle.hpp"
#include"lib/include/CollisionDetection/Collider.hpp"
#include"lib/include/InputState/InputState.hpp"

#include <stdlib.h>
#include <crtdbg.h>
#define malloc(X) _malloc_dbg(X,_NORMAL_BLOCK,__FILE__,__LINE__) 
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

using namespace GameLib;


class MyActor : public RootActor
{
public:
	MyActor()
		:RootActor()
		, mTriangle( { -300.f,300.f }, { 0.f,-300.f }, { 300.f,300.f }, {255,0,0,255})
	{
	}

	virtual void Update() override{
		if (InputState::GetState(Key::R) == ButtonState::Pressed)
			mTriangle.SetColor({ 255,0,0,255 });
		if (InputState::GetState(Key::G) == ButtonState::Pressed)
			mTriangle.SetColor({ 0,255,0,255 });
		if (InputState::GetState(Key::B) == ButtonState::Pressed)
			mTriangle.SetColor({ 0,0,255,255 });

	}

private:
	DrawFillTriangle mTriangle;

};


int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_DELAY_FREE_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);

	
	auto app = GameLib::CreatAppPtr({ "window",800,600 });
	auto root = new MyActor();
	app->Start(root);


	return 0;
	
}