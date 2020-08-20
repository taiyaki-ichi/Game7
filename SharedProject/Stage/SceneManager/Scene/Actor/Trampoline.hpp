#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Stage/Utilty/Dir4Vec.hpp"

namespace Stage
{
	class Trampoline : public ActorBase
	{
		GameLib::DrawTexture mTexture;
		GameLib::Collider mCollider;

	public:
		//Dir4‚Í”ò‚Î‚·•ûŒü
		Trampoline(GameLib::Actor*, Dir4&&);

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&&) override;
	};
}