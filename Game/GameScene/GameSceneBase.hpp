#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<string>

namespace Game
{
	class GameSceneBase : public GameLib::Actor
	{

	public:
		GameSceneBase(GameLib::Actor* game);
		virtual ~GameSceneBase() = default;

		virtual std::string GetNextSceneTag() = 0;
	};
}