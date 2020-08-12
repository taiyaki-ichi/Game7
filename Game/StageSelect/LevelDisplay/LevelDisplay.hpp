#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"

namespace Game::StageSelect
{
	class LevelDisplay : public GameLib::Actor
	{
		GameLib::DrawFontText mText;

	public:
		LevelDisplay(GameLib::Actor*);
		virtual ~LevelDisplay() = default;

		void SetLevelString(const std::string& level);
		void AdjustPos();
	};
}