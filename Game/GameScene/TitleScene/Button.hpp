#pragma once
#include"GameLib/include/Draw/DrawRect.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"
#include"Stage/SceneManager/Scene/Actor/Player/ItemNum/GemDisplay.hpp"
#include"Stage/SceneManager/Scene/Actor/Player/ItemNum/LifeDisplay.hpp"

namespace Game
{
	class Button
	{
		GameLib::DrawRect mInsideRect;
		GameLib::DrawRect mOutsiedeRect;

		GameLib::DrawFontText mText;

		Stage::GemDisplay mGemDisplay;
		Stage::LifeDisplay mLifeDisplay;

	public:
		Button(const GameLib::Vector2&,int drawOrder = 0);

		void SetWidthAndHeightAndFlameWidth(float, float, float);
		void SetText(std::string&&);
		void SetLifeAndGemNum(int, int);

		void ChangeDark();
		void ChangeWhite();
	};
}