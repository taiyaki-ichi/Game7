#pragma once
#include"GameLib/include/Draw/CustomizeDrawBase.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace Stage
{
	
	class IceGroundTexture : public GameLib::CustomizeDrawBase
	{
		GameLib::DrawRect mRect;

		GameLib::DrawRect mRect2;

	public:
		IceGroundTexture(int drawOrder = 0);

		void Draw() override;

		void SetWidthAndHeight(float w, float h);
		void SetPosition(const GameLib::Vector2&);
	};

}