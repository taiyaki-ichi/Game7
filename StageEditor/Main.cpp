#include"GameLib/include/App.hpp"
#include"StartActor.hpp"

int main()
{
	auto app = GameLib::CreatAppPtr({ "StageEditor",800,600 });
	app->Start<StageEditor::StartActor>();
}