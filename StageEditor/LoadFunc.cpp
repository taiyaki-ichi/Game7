#include"LoadFunc.hpp"
#include<fstream>
#include<iostream>
#include"Json/picojson.hpp"
#include"StageEditor.hpp"
#include"SceneEditor/CreateActorEditor.hpp"
#include"SceneEditor/SceneEditor.hpp"

namespace StageEditor
{

	bool LoadStageData(StageEditor* editor, std::string&& fileName)
	{

		// JSONデータの読み込み。
		std::ifstream ifs(fileName, std::ios::in);
		if (ifs.fail()) {
			std::cout << "failed to read " << fileName << std::endl;
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

		bool numZeroFlag = true;

		picojson::object& stageObj = v.get<picojson::object>();
		picojson::array& sceneDataArray = stageObj["SceneData"].get<picojson::array>();
		for (auto& sceneDataValue : sceneDataArray) {

			picojson::object& sceneData = sceneDataValue.get<picojson::object>();
			picojson::array& actorsData = sceneData["ActorsData"].get<picojson::array>();

			std::string sceneName = sceneData["SceneName"].get<std::string>();
			auto scenePtr = editor->AddScene(std::move(sceneName));

			if (scenePtr)
			{
				for (auto& actorDataValue : actorsData) {
					picojson::object& actorData = actorDataValue.get<picojson::object>();

					auto ptr = CreateActorEditor(scenePtr, actorData["ActorName"].get<std::string>());


					int i = 0;
					std::vector<float> floatData;
					while (actorData["FloatData" + std::to_string(i)].is<double>()) {
						floatData.emplace_back(static_cast<float>(actorData["FloatData" + std::to_string(i)].get<double>()));
						i++;
					}

					i = 0;
					std::vector<std::string> stringData;
					while (actorData["StringData" + std::to_string(i)].is<std::string>()) {
						stringData.emplace_back(actorData["StringData" + std::to_string(i)].get<std::string>());
						i++;
					}

					ptr->SetData(std::move(floatData), std::move(stringData));

				}

				if (numZeroFlag) {
					scenePtr->BeginWorking();
					numZeroFlag = false;
				}
				else
					scenePtr->BeginToRest();
			}
		}

		return true;
	}



}