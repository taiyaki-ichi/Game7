#pragma once

namespace Game
{
	class GameSceneBase;
	class Game;

	GameSceneBase* ChangeScene(Game* game, std::string&& nameTag);
}