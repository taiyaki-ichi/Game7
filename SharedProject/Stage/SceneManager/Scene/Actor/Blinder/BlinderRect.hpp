#pragma once
#include"GameLib/include/Draw/CustomizeDrawBase.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"
#include"GameLib/include/Draw/DrawCircle.hpp"

namespace Stage
{
	class BlinderRect :public GameLib::CustomizeDrawBase
	{
		GameLib::DrawRect mRect;
		GameLib::DrawCircle mCircle;

	public:
		BlinderRect();
		virtual ~BlinderRect() = default;

		void Draw() override;

		//舞フレーム呼ぶ
		void SetPlayerPos(const GameLib::Vector2&);

		void SetRect(const GameLib::Vector2& center, float width, float height);

	};
}