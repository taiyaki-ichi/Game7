
#include"GameLib/include/Actor/RootActor.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/include/App.hpp"

using namespace GameLib;

class MyActor : public RootActor
{
	DrawTexture mTexture;

public:
	MyActor()
		:RootActor{}
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