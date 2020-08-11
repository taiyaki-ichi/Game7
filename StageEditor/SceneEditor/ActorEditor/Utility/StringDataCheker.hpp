#pragma once
#include<string>

namespace StageEditor
{
	struct IsDir4 {
		bool operator()(const std::string& str) {
			if (str == "right" || str == "left" || str == "up" || str == "down")
				return true;
			else
				return false;
		}
	};
}