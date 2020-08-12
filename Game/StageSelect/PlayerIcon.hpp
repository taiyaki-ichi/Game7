#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Game::StageSelect
{
	class PlayerIcon : public GameLib::Actor
	{
		GameLib::DrawTexture mTexture;

		GameLib::Vector2 mPosition;
		int mCnt;

	public:
		PlayerIcon(GameLib::Actor*);

		void CustomizeUpdate() override;

		void SetPosision(const GameLib::Vector2&);
		const GameLib::Vector2& GetPosition() const;
	};

}