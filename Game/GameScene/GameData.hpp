#pragma once
#include"Utility/HexVec.hpp"
#include<unordered_map>

namespace Game
{
	constexpr int START_PLAYER_LIFE_NUM = 5;

	struct GameData
	{
		HexVec mNowPos;
		int mPlayerLifeNum;
		int mPlayerGemNum;
		std::unordered_map<HexVec, unsigned char> mSaveData;

		GameData(const HexVec& pos,int life,int gem, const std::unordered_map<HexVec, unsigned char>& saveData)
			:mNowPos{pos}
			, mPlayerLifeNum{life}
			, mPlayerGemNum{gem}
			, mSaveData{ saveData }
		{}

		GameData()
			:mNowPos{}, mPlayerLifeNum{}, mPlayerGemNum{}, mSaveData{}
		{}
	};
}