#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"

namespace Stage
{
	class Gem : public ActorBase
	{
		GameLib::DrawAnimation mAnim;
		GameLib::Collider mCollider;

	public:
		Gem(GameLib::Actor*);
		virtual ~Gem() = default;

		bool UpdateOrNot() override;
		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&&) override;
	};
}