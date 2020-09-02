#pragma once
#include<string>

namespace GameLib
{
	class Actor;
}

namespace Stage::BackGround
{
	void CreateSharpTreeForest(GameLib::Actor* owner);
	void CreateRoundTreeForest(GameLib::Actor* owner);
	void CreateIndianVillage(GameLib::Actor* owner);
	void CreateSanctuary(GameLib::Actor* onwer);
	void CreateCreepyCave(GameLib::Actor*);

}