
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/include/App.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/src/CollisionDetection/ColliderManager.hpp"

using namespace GameLib;

class MyActor : public Actor
{
	DrawTexture mTexture;

public:
	MyActor(Actor* actor)
		:Actor{actor}
		, mTexture{ "../Assets/Player/icon.png" }
	{
		mTexture.SetScale(0.1f);
	}

	void CustomizeUpdate() override 
	{
		mTexture.SetPosition(InputState::GetMousePos());
	}
};


/*
class Player : public Actor
{
	//メンバ
	DrawAnimation mAnimation;
	Collider mCollider;

	
};

//コライダーのコンストラクタ

Collider::Collider(...)
{
	ColliderManager::Add(this);
	...
}

Collider::~Collider()
{
	ColliderManager::Remove(this);
	...
}

*/

int main()
{
	auto app = GameLib::CreatAppPtr({ "sample",500.f,500.f });
	app->Start<MyActor>();

	return 0;
}