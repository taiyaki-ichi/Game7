#pragma once
#include"Json/picojson.hpp"
#include<iostream>
#include <fstream>


bool PrintJson()
{
	std::string fileName{ "test.json" };

	// JSONデータの読み込み。
	std::ifstream ifs(fileName, std::ios::in);
	if (ifs.fail()) {
		std::cerr << "failed to read " << fileName << std::endl;
		return false;
	}
	const std::string json((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	ifs.close();

	picojson::value v;
	const std::string err = picojson::parse(v, json);
	if (err.empty() == false) {
		std::cerr << err << std::endl;
		return false;
	}

	picojson::object& stageObj = v.get<picojson::object>();
	picojson::array& sceneDataArray = stageObj["SceneData"].get<picojson::array>();
	for (auto& sceneDataValue : sceneDataArray) {

		picojson::object& sceneData = sceneDataValue.get<picojson::object>();
		picojson::array& actorsData = sceneData["ActorsData"].get<picojson::array>();

		std::string sceneName = sceneData["SceneName"].get<std::string>();
		std::cout << sceneName << "\n";

		for (auto& actorDataValue : actorsData) {
			picojson::object& actorData = actorDataValue.get<picojson::object>();

			std::cout << actorData["ActorName"].get<std::string>() << " ";

		}
		std::cout << "\n";

	}
}
