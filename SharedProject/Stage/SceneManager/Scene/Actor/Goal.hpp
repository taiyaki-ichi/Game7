#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Stage/Utilty/Dir4Vec.hpp"

namespace Stage
{
	class Goal : public ActorBase
	{
		GameLib::DrawTexture mTexture;
		GameLib::Collider mCollider;

		Dir4 mFallDir;

		GameLib::Vector2 GetFallDirVec();

	public:
		Goal(GameLib::Actor*);
		virtual ~Goal() = default;

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&&) override;
		void LoadStringData(std::vector<std::string>&&) override;

	};
}