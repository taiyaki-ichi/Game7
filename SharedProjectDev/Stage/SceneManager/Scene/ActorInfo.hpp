#pragma once
#include<vector>
#include<string>
#include<unordered_map>
#include<string>

namespace Stage
{
	struct ActorInfo {
		std::string mName;
		std::vector<float> mFloatData;
		std::unordered_map<std::string, std::string> mStringData;

		ActorInfo(std::string&& name, std::vector<float>&& data, std::unordered_map<std::string, std::string>&& data2 = {})
			:mName{ std::move(name) }
			, mFloatData{ std::move(data) }
			, mStringData{std::move(data2)}
		{}

	};
}