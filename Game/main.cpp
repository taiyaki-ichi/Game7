#include<iostream>
#include<string>
#include<memory>
#include<random>
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

using namespace GameLib;

std::random_device rnd;     
std::mt19937 mt(rnd());     
std::uniform_real_distribution<> myRand(-300.0, 300.0);

class Tama : public Actor
{
	Collider mCollider;
	Vector2 mPosition;
	Vector2 mVelocity;

public:
	Tama(Actor* owner)
		:Actor(owner)
		, mPosition({myRand(mt),myRand(mt)})
		, mVelocity({myRand(mt)/60.f,myRand(mt)/60.f})
		, mCollider(this, "Tama", mPosition, 20.f, 20.f, 1.f, 0.f)
	{
		mCollider.AddHitFunction("Move", [this](const Collider& c) {mCollider.SetColor({ 255,0,0,255 }); });
		mCollider.AddHitFunction("Tama", [this](const Collider& c) {mCollider.SetColor({ 0,0,255,255 }); });
	}

	void CustomizeUpdate()override {
		mPosition += mVelocity;
		if (mPosition.x < -400.f || 400.f < mPosition.x)
			mVelocity.x *= -1.f;
		if (mPosition.y < -300.f || 300.f < mPosition.y)
			mVelocity.y *= -1.f;
		mCollider.SetColor({ 0,0,0,255 });
		mCollider.SetPosition(mPosition);
	}


};


class Move :public Actor
{
	Collider mCollider;
	float mRotation;

public:
	Move(Actor* owner)
		:Actor(owner)
		, mCollider(this, "Move", { 0.f,0.f }, 50.f, 50.f, 1.f, 0.f, { 0,0,0,255 })
		,mRotation(0.f)
	{}

	void CustomizeUpdate() override {
		mRotation += 0.01f;
		mCollider.SetColor({ 0,255,0,255 });
		mCollider.Set(InputState::GetMousePos(), 100.f, 100.f, 1.f, mRotation);
	}
	
};

class MyActor : public RootActor
{
public:
	MyActor()
		:RootActor()
	{
		//mMove = new Move(this);
		for (int i = 0; i < 10; i++)
			new Tama(this);
	}

private:
	//Move* mMove;
	
};


#include <stdlib.h>
#include <crtdbg.h>
#define malloc(X) _malloc_dbg(X,_NORMAL_BLOCK,__FILE__,__LINE__) 
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_DELAY_FREE_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);

	
	auto app = GameLib::CreatAppPtr({ "window",800,600 },60.f);
	app->Start<MyActor>();
	
	return 0;
	
}