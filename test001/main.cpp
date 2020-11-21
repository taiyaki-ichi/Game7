
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/include/App.hpp"

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


int main()
{
	auto app = GameLib::CreatAppPtr({ "sample",500.f,500.f });
	app->Start<MyActor>();

	return 0;
}