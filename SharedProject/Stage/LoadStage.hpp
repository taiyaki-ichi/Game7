#pragma once
#include<string>

namespace Stage
{
	class Stage;
	class SceneManager;

	SceneManager* LoadStage(Stage* stage, std::string&& fileName, int playerLifeNum, int playerGemNum);
}