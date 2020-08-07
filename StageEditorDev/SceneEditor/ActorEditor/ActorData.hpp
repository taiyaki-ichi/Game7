#pragma once
#include<vector>
#include<string>
#include"GameLib/include/Math/Vector2.hpp"

namespace StageEditor
{

	//Scene‚É‘—‚é‚æ‚¤
	struct ActorData {
		std::string mNameTag;
		std::vector<GameLib::Vector2> mPosData;
		std::vector<std::string> mStringData;

		ActorData(const std::string& nameTag, std::vector<GameLib::Vector2>&& posData, std::vector<std::string>&& stringData)
			:mNameTag{ nameTag }
			, mStringData{ std::move(stringData) }
			, mPosData{ std::move(posData) }
		{}
		~ActorData() = default;
	};

}