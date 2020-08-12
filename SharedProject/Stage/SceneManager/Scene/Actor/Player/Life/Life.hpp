#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"

namespace Stage
{
	class Life : public GameLib::Actor
	{
		GameLib::DrawTexture mTexture;
		GameLib::DrawFontText mNumText;

		int mLifeNum;

	public:
		Life(GameLib::Actor*);
		virtual ~Life() = default;

		void CustomizeUpdate() override;

		void Damage();
		void Heal();

		bool IsLifeZero();

		void AdjustPos();
	};
}