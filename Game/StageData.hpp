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
		{{2,0},{"stage007","easy","かんたん原っぱ"}},
		{{2,1},{"stage002","easy","カエルと動く地面"}},
		{{3,-1},{"stage010","ふつう","にんじん平原"}},
		{{3,1},{"stage011","ふつう","しがみつけ！"}},
		{{4,-1},{"stage009","ふつうくらい","頭上注意"}},
		{{4,0},{"stage003","difficult","にんじんとりんご"}},
		{{4,1},{"stage004","nomal","ぴょんぴょんぶんぶん"}},
		{{5,-1},{"stage005","nomal","動けない？見えない？"}},
		{{5,1},{"stage006","むずい","ぐるぐるかたつむり"}},
		{{6,-1},{"stage012","むずい","のぼれ！"}},
		{{6,0},{"stage008","まあまあむずい","アスレチックアスレチック"}},

		{{13,0},{"stage013","ふつー","足元注意"}},
		{{14,0},{"stage014","むずい","つるつるどうくつ"}},
	

		{{-1,1},{"save"}},
		{{0,-1},{"title"}},
		{{0,0},{"start"}},
	};

}