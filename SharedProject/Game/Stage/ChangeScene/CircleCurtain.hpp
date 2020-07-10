#pragma once
#include"CurtainBase.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"
#include"GameLib/include/Draw/DrawCircle.hpp"

namespace Game::Stage
{
	class CircleCurtain : public CurtainBase
	{
		float mRadius;
		GameLib::DrawRect mRect;
		GameLib::DrawCircle mCircle;
		GameLib::Vector2 mNowPlayerPos;
		GameLib::Vector2 mNextPlayerPos;

		int mMode;

	public:
		CircleCurtain(const GameLib::Vector2& nowPlayerPos, const GameLib::Vector2& nextPlayerPos);
		virtual ~CircleCurtain() = default;

		void Update() override;

		bool IsClosed() override;
		void Open() override;
		bool IsOpened() override;

		void Draw() override;
	};
}