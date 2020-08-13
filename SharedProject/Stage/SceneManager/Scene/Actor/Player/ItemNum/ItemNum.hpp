#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<array>
#include"GameLib/include/Math/Vector2.hpp"
#include"GemDisplay.hpp"
#include"LifeDisplay.hpp"
#include"TearDisplay.hpp"

namespace Stage
{

	class ItemNum : public GameLib::Actor
	{
		int mLifeCnt;
		int mGemCnt;
		std::array<bool, 3> mTearGemCnt;

		LifeDisplay mLifeDisplay;
		GemDisplay mGemDisplay;
		TearDisplay mTearDisplay;


	public:
		//pos,lifeNum,GemNum
		ItemNum(GameLib::Actor*,const GameLib::Vector2&, int, int);
		virtual ~ItemNum() = default;

		//void CustomizeUpdate() override;

		void AddGem();
		void AddTearGem(int);

		void AdjustPos();
	};
}