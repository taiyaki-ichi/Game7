#pragma once
#include<vector>
#include<string>

namespace Stage
{
	struct ActorInfo {
		std::string mName;
		std::vector<float> mData;

		ActorInfo(std::string&& name, std::vector<float>&& data)
			:mName{ std::move(name) }
			, mData{ std::move(data) }
		{}

	};
}