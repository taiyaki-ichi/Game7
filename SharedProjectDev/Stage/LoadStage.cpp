#include"LoadStage.hpp"
#include"SceneManager/StageSceneManager.hpp"
#include"Stage.hpp"
#include"Json/picojson.hpp"
#include <fstream>
#include"SceneManager/Scene/ActorInfo.hpp"

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
		std::vector<float> floatData;
		while (obj[std::to_string(i)].is<double>()) {
			floatData.emplace_back(static_cast<float>(obj[std::to_string(i)].get<double>()));
			i++;
		}
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

				sceneVector.emplace_back(ActorInfo{ std::move(actorName),std::move(floatData) });

			}

			sceneVectorVector.emplace_back(sceneVector);
		}

		sceneManagerPtr->CreateScene(std::move(sceneVectorVector));

		return sceneManagerPtr;
	}

}