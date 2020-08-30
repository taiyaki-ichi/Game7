#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace Stage
{
	class Spore : public ActorBase
	{
		GameLib::DrawTexture mTexure;
		GameLib::Collider mCollider;

		GameLib::Vector2 mVelocity;

	public:
		Spore(GameLib::Actor*,const GameLib::Vector2& pos, const GameLib::Vector2& velocity);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&&) {};
	};
}