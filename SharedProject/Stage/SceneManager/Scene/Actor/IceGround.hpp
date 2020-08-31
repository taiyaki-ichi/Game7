#pragma once
#include"StageActorBase.hpp"
#include"IceGround/IceGroundTexture.hpp"

namespace Stage
{
	class IceGroundCollider;

	class IceGround : public ActorBase
	{
		std::vector<IceGroundCollider*> mIceGroundCollider;
		IceGroundTexture mTexture;

	public:
		IceGround(GameLib::Actor* actor);

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&&) override;
	};
}