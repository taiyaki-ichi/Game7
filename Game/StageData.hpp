#pragma once
#include<unordered_map>
#include<vector>
#include<string>
#include"StageSelect/HexVec.hpp"

namespace Game
{
	const std::unordered_map<HexVec, std::vector<std::string>> gStageData =
	{
		{{1,0},{"stage001","easy","énÇ‹ÇËÇÃêX"}},
		{{2,0},{"stage001","easy","Ç†Ç†Ç†Ç†Ç†"}},
		{{3,0},{"stage001","nomal","Ç†Ç†Ç†Ç†Ç†"}},
		{{4,0},{"stage001","nomal","Ç†Ç†Ç†Ç†Ç†"}},
		{{5,0},{"stage001","nomal","Ç†Ç†Ç†Ç†"}},

		{{-1,1},{"save"}},
		{{0,-1},{"title"}},
		{{0,0},{"start"}},
	};

	
}