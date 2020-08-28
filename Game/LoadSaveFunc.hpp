#pragma once
#include"GameScene/GameData.hpp"

namespace Game
{
	GameData LoadGameData();
	void SaveGameData(const GameData&);
}