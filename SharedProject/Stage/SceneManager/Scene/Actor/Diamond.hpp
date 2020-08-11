#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"

namespace Stage
{
	class Diamond : public ActorBase
	{
		GameLib::DrawAnimation mAnim;
		GameLib::Collider mCollider;

	public:
		Diamond(GameLib::Actor*);
		virtual ~Diamond() = default;

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&&) override;
	};
}