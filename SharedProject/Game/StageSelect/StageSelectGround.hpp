#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace Game::StageSelect
{
	class StageSelect;

	class Ground : public GameLib::Actor
	{
		GameLib::Collider mCollider;
		GameLib::DrawRect mRect;
		GameLib::Vector2 mPosition;

	public:
		Ground(StageSelect* stageSelect, const GameLib::Vector2& pos = {}, float w = 0.f, float h = 0.f);
		virtual ~Ground() = default;

		void SetPosition(const GameLib::Vector2& pos);
		void SetWidthAndHeight(float w, float h);

	};
}