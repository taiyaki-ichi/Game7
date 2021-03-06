#pragma once
#include<unordered_map>
#include<vector>
#include<string>
#include"GameScene/Utility/HexVec.hpp"
#include"Stage/BackGroundType.hpp"

namespace Game
{

	const std::unordered_map<HexVec, std::vector<std::string>> gStageData =
	{
		{{1,0},{"stage007","easy","かんたん原っぱ"}},
		{{2,0},{"stage001","easy","始まりの森"}},
		{{2,1},{"stage002","easy","カエルと動く地面"}},
		{{3,-1},{"stage010","nomal","にんじん平原"}},
		{{3,1},{"stage011","nomal","しがみつけ！"}},
		{{4,0},{"stage013","nomal","足元注意"}},
		{{4,-1},{"stage009","nomal","頭上注意"}},
		{{5,0},{"stage005","nomal","動けない？見えない？"}},
		{{5,1},{"stage008","difficult","アスレチックアスレチック"}},
		{{6,1},{"stage006","difficult","ぐるぐるかたつむり"}},
		{{6,-1},{"stage004","nomal","ぴょんぴょんぶんぶん"}},
		{{7,0},{"stage003","difficult","にんじんとりんご"}},
		{{7,-1},{"stage014","difficult","つるつるどうくつ"}},
		{{8,0},{"stage012","difficult","のぼれ！"}},
	
		
		{{-1,1},{"save"}},
		{{0,-1},{"title"}},
		{{0,0},{"start"}},
		{{9,0},{"goal"}},
	};

	const std::unordered_map<std::string, Stage::BackGroundType> gStageBackGroundType =
	{
		{"stage007",Stage::BackGroundType::RoundTreeForest},
		{"stage001",Stage::BackGroundType::RoundTreeForest},
		{"stage002",Stage::BackGroundType::SharpTreeForest},
		{"stage010",Stage::BackGroundType::IndianVilleage},
		{"stage011",Stage::BackGroundType::IndianVilleage},
		{"stage013",Stage::BackGroundType::RoundTreeForest},
		{"stage009",Stage::BackGroundType::RoundTreeForest},
		{"stage005",Stage::BackGroundType::Sanctuary},
		{"stage008",Stage::BackGroundType::SharpTreeForest},
		{"stage006",Stage::BackGroundType::Sanctuary},
		{"stage004",Stage::BackGroundType::SharpTreeForest},
		{"stage003",Stage::BackGroundType::Sanctuary},
		{"stage014",Stage::BackGroundType::RoundTreeForest},
		{"stage012",Stage::BackGroundType::RoundTreeForest},
	}; 

}