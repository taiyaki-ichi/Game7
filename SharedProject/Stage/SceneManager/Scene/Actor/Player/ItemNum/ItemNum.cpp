#include"ItemNum.hpp"
#include"ItemNumParam.hpp"
#include"TearDisplay.hpp"

namespace Stage
{
	ItemNum::ItemNum(GameLib::Actor* actor, const GameLib::Vector2& pos, int life, int gem)
		:GameLib::Actor{actor}
		, mLifeCnt{life}
		, mGemCnt{gem}
		, mTearGemCnt{false,false,false}
		, mTearDisplay{pos+ItemNumParam::TEAR_DISPLAY_ADJUST}
		, mGemDisplay{pos+ItemNumParam::GEM_DISPLAY_ADJUST,gem}
		, mLifeDisplay{pos+ItemNumParam::LIFE_DISPLAY_ADJUST,life}
	{
	}

	void ItemNum::AddGem()
	{
		mGemCnt++;
		if (mGemCnt == ItemNumParam::GEM_MAX_NUM) {
			mGemCnt = 0;
			mLifeCnt++;
		}

		mGemDisplay.SetNum(mGemCnt);
		mLifeDisplay.SetNum(mLifeCnt);
	
	}
	void ItemNum::AddTearGem(int num)
	{
		mTearDisplay.Get(num);
	}
	
	void ItemNum::AdjustPos()
	{
		mGemDisplay.AdjustPos();
		mLifeDisplay.AdjustPos();
		mTearDisplay.AdjustPos();
	}
}