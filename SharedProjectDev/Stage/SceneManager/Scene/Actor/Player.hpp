#pragma once
#include"StageActorBase.hpp"
#include<optional>
#include<utility>
#include"GameLib/include/Math/Vector2.hpp"

namespace Stage
{
	class Player : public ActorBase
	{
		GameLib::Vector2 mPos;

	public:
		Player(GameLib::Actor* scene);
		virtual ~Player() = default;

		void Active() override;
		void Pause() override;

		void LoadData(std::vector<float>&& data, std::unordered_map<std::string, std::string>&& stringData) override;

		std::optional<std::pair<std::string,std::string>> GetWarpNameTag();
		void Warp(const GameLib::Vector2& pos);

		const GameLib::Vector2& GetPosition() const;
	};
}