#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Game
{
	class KeyHex;

	class MoveKeyAssist : public GameLib::Actor
	{
		GameLib::DrawTexture mIconTexture;
		std::vector<KeyHex*> mKeyHex;

		GameLib::Vector2 mPosition;

	public:
		MoveKeyAssist(GameLib::Actor*, int drawOrder = 0);

		void SetPosition(const GameLib::Vector2&);
		void AdjustPosition();
	};
}