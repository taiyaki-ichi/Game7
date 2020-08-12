#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Game::StageSelect
{
	class PlayerIcon : public GameLib::Actor
	{
		GameLib::DrawTexture mTexture;

	public:
		PlayerIcon(GameLib::Actor*);

		void CustomizeUpdate() override;
	};

}