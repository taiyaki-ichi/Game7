#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"

namespace Stage
{
	class PlayerStateManager;

	class Player : public ActorBase
	{
		GameLib::DrawAnimation mAnimation;
		PlayerStateManager* mStateManager;

	public:
		Player(GameLib::Actor* scene);
		virtual ~Player() = default;

		void Active() override;
		void Pause() override;

		void LoadData(std::vector<float>&& data) override;

		void SetPosition(const GameLib::Vector2& pos);

		//Animation�̈ʒu
		const GameLib::Vector2& GetPosition() const;
	};
}