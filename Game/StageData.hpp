#pragma once
#include<unordered_map>
#include<vector>
#include<string>
#include"StageSelect/HexVec.hpp"

namespace Game
{
	const std::unordered_map<HexVec, std::vector<std::string>> gStageData =
	{
		{{1,0},{"stage001","easy","始まりの森"}},
		{{2,0},{"stage002","easy","あああああ"}},
		{{3,0},{"stage001","nomal","あああああ"}},
		{{4,0},{"stage001","nomal","あああああ"}},
		{{5,0},{"stage001","nomal","ああああ"}},

		{{-1,1},{"save"}},
		{{0,-1},{"title"}},
		{{0,0},{"start"}},
	};

	
}