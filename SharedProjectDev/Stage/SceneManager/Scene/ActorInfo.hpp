#pragma once
#include<vector>
#include<string>
#include"GameLib/include/Math/Vector2.hpp"

namespace Stage
{
	struct ActorInfo {
		std::string mName;
		std::vector<GameLib::Vector2> mPosData;
		std::vector<std::string> mStringData;

		ActorInfo(std::string&& name, std::vector<float>&& data, std::vector<std::string>&& data2)
			:mName{ std::move(name) }
			, mPosData{ }
			, mStringData{std::move(data2)}
		{
			for (int i = 0; i < data.size() / 2.f; i++)
				mPosData.emplace_back(GameLib::Vector2{ data[i * 2],data[i * 2 + 1] });
		}

	};
}