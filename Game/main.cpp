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


class Red : public Actor
{
	Collider mCollider;

public:
	Red(Actor* owner)
		:Actor(owner)
		, mCollider(this, "Red", { 200.f,200.f }, 50.f, 50.f, 1.f, 0.f, {255,0,0,255})
	{}
};

class Move :public Actor
{
	Collider mCollider;

public:
	Move(Actor* owner)
		:Actor(owner)
		, mCollider(this, "Move", { 0.f,0.f }, 20.f, 20.f, 1.f, 0.f, { 0,0,0,255 })
	{}

	void Update() override {
		mCollider.SetColor({ 0,0,0,255 });
		mCollider.Set(InputState::GetMousePos(), 20.f, 20.f, 1.f,0.f);
	}

	void HitCollider(const Collider& c) override {
		auto nameTag = c.GetNameTag();
		if (nameTag == "Red")
			mCollider.SetColor({ 255,0,0,255 });
	}
};

class MyActor : public RootActor
{
public:
	MyActor()
		:RootActor()
	{
		mRed = new Red(this);
		mMove = new Move(this);
	}

	virtual void Update() override{
		mRed->Update();
		mMove->Update();
	}
private:
	Red* mRed;
	Move* mMove;

};


int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_DELAY_FREE_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);

	
	auto app = GameLib::CreatAppPtr({ "window",800,600 });
	auto root = new MyActor();
	app->Start(root);


	return 0;
	
}