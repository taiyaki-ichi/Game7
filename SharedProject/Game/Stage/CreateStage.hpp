#pragma once
#include<string>
namespace Game::Stage
{
	class Stage;

	bool CreateStage(Stage* stagePtr, std::string&& fileName);
}