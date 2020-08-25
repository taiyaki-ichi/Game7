#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace Stage
{
	class TogeBlock : public ActorBase
	{
		GameLib::DrawTexture mTexture;
		GameLib::Collider mCollder;

	public:
		TogeBlock(GameLib::Actor*);

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&&) override;
	};
}