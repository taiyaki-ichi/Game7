#include"LoadStage.hpp"
#include"SceneManager/StageSceneManager.hpp"
#include"Stage.hpp"
#include"Json/picojson.hpp"
#include <fstream>
#include"SceneManager/Scene/ActorInfo.hpp"
#include<unordered_map>
#include<string>
#include"SceneManager/Scene/Actor/WarpBase.hpp"

#include<iostream>

namespace Stage
{

	bool OpenFile(std::string&& fileName, picojson::value& v) {

		std::ifstream ifs(fileName, std::ios::in);
		if (ifs.fail()) {
			std::cerr << "failed to read " << fileName << std::endl;
			return false;
		}

		const std::string json((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
		ifs.close();

		const std::string err = picojson::parse(v, json);
		if (err.empty() == false) {
			std::cerr << err << std::endl;
			return false;
		}

		return true;
	}

	std::vector<float> GetFloatData(picojson::object&& obj) {
		int i = 0;
		std::vector<float> floatData{};
		while (obj[std::to_string(i)].is<double>()) {
			floatData.emplace_back(static_cast<float>(obj[std::to_string(i)].get<double>()));
			i++;
		}

		return floatData;
	}


	std::unordered_map<std::string, std::string> GetStringData(const std::string& actorName, picojson::object& obj)
	{
		std::unordered_map<std::string, std::string> stringData{};

		if (actorName == "Warp") {
			
			std::string warpGateType = obj[WarpBase::TYPE].get<std::string>();
			std::string nameTag = obj[WarpBase::NAMETAG].get<std::string>();
			std::string destinationNameTag = obj[WarpBase::DESTINATION_NAMETAG].get<std::string>();

			stringData.emplace(WarpBase::TYPE ,std::move(warpGateType));
			stringData.emplace(WarpBase::NAMETAG, std::move(nameTag));
			stringData.emplace(WarpBase::DESTINATION_NAMETAG, std::move(destinationNameTag));
			
		}
		


		return stringData;
	}


	SceneManager* LoadStage(Stage* stage, std::string&& fileName)
	{
		auto sceneManagerPtr = new SceneManager{ stage };

		picojson::value v;
		if (!OpenFile(std::move(fileName), v))
			return sceneManagerPtr;

		std::vector<ActorInfo> sceneVector{};
		std::vector<std::vector<ActorInfo>> sceneVectorVector{};

		picojson::object& stageObj = v.get<picojson::object>();
		picojson::array& sceneDataArray = stageObj["SceneData"].get<picojson::array>();
		for (auto& sceneDataValue : sceneDataArray) {

			sceneVector.clear();

			picojson::object& sceneData = sceneDataValue.get<picojson::object>();
			picojson::array& actorsData = sceneData["ActorsData"].get<picojson::array>();

			for (auto& actorDataValue : actorsData) {
				picojson::object& actorData = actorDataValue.get<picojson::object>();

				std::string actorName = actorData["ActorName"].get<std::string>();
				std::vector<float> floatData = GetFloatData(std::move(actorData));

				//std::cout << actorName << std::endl;

				auto stringData = GetStringData(actorName, actorData);

				sceneVector.emplace_back(ActorInfo{ std::move(actorName),std::move(floatData),std::move(stringData) });

			}

			sceneVectorVector.emplace_back(sceneVector);
		}

		//std::cout << "sceneVectorSize: " << sceneVectorVector.size() << "\n";
		sceneManagerPtr->CreateScene(std::move(sceneVectorVector));

		return sceneManagerPtr;
	}

}