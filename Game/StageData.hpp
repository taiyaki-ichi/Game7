#pragma once
#include<unordered_map>
#include<vector>
#include<string>
#include"GameScene/Utility/HexVec.hpp"

namespace Game
{
	const std::unordered_map<HexVec, std::vector<std::string>> gStageData =
	{
		{{1,0},{"stage001","easy","始まりの森"}},
		//{{1,0},{"rot","easy","rot"}},
		{{2,0},{"stage002","easy","カエルと動く地面"}},
		{{3,0},{"stage003","difficult","にんじんとりんご"}},
		{{4,0},{"stage004","nomal","トランポリンとハチ"}},
		{{5,0},{"stage005","nomal","動けない？見えない？"}},
		{{6,0},{"stage006","むずい","ぐるぐるかたつむり"}},
		{{1,1},{"stage007","easy","かんたん平原"}},

		{{-1,1},{"save"}},
		{{0,-1},{"title"}},
		{{0,0},{"start"}},
	};

}