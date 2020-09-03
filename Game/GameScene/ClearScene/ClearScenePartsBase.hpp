#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace Game
{
	class ClearScenePartsBase : public GameLib::Actor
	{
		unsigned char mFlag;

	public:
		ClearScenePartsBase(GameLib::Actor*);

		bool CheckFlag(unsigned char);

	protected:
		void UpFlag(unsigned char);
		void DownFlag(unsigned char);
	};
}