#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Draw/DrawCircle.hpp"

namespace Stage
{
	class Lift;

	class CycleLift : public ActorBase
	{
		std::vector<Lift*> mLift;
		GameLib::DrawCircle mCircle;

		bool mIsClockwise;

		int mCnt;

	public:
		CycleLift(GameLib::Actor*);

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&&) override;
		void LoadStringData(std::vector<std::string>&&) override;
	};
}