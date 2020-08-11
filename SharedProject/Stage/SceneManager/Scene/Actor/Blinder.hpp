#pragma once
#include"StageActorBase.hpp"
#include"Blinder/BlinderRect.hpp"

namespace Stage
{
	class Blinder : public ActorBase
	{
		BlinderRect mRect;

	public:
		Blinder(GameLib::Actor*);
		virtual ~Blinder() = default;

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&&);
	};
}