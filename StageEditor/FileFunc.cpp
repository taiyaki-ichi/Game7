#include"FileFunc.hpp"
#include"Json/picojson.hpp"
#include <fstream>
#include"SceneEditor/CreateActorEditor.hpp"

namespace StageEditor
{
	void SaveStageData(const std::string& stageName, std::unordered_map<std::string, std::vector<ActorData>>&& stageData, const std::string& fileName)
	{
		picojson::array allData;
		for (auto iter = stageData.begin(); iter != stageData.end(); iter++)
		{
			picojson::array actorsData;
			for (auto& actorData : iter->second)
			{
				picojson::object dataActor;
				for (int i = 0; i < actorData.mData.size(); i++) {
					dataActor.insert(std::make_pair(std::to_string(i), static_cast<double>(actorData.mData[i])));
				}

				dataActor.insert(std::make_pair("ActorName", actorData.mActorName));
				actorsData.push_back(picojson::value(dataActor));
			}
			
			picojson::object sceneData;
			sceneData.insert(std::make_pair("SceneName", iter->first));
			sceneData.insert(std::make_pair("ActorsData", actorsData));

			allData.push_back(picojson::value(sceneData));
		}

		picojson::object stageAllData;
		stageAllData.insert(std::make_pair("SceneData", picojson::value(allData)));

		std::ofstream ofs(fileName);
		ofs << picojson::value(stageAllData).serialize(true) << std::endl;
	}


	bool LoadStageData(StageEditor* stageEditorPtr, std::string&& fileName)
	{
		stageEditorPtr->ResetSumNum();

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

		bool numZeroFlag = true;

		picojson::object& stageObj = v.get<picojson::object>();
		picojson::array& sceneDataArray = stageObj["SceneData"].get<picojson::array>();
		for (auto& sceneDataValue : sceneDataArray) {

			picojson::object& sceneData = sceneDataValue.get<picojson::object>();
			picojson::array& actorsData = sceneData["ActorsData"].get<picojson::array>();

			std::string sceneName = sceneData["SceneName"].get<std::string>();
			auto scenePtr = stageEditorPtr->AddScene(std::move(sceneName));

			for (auto& actorDataValue : actorsData) {
				picojson::object& actorData = actorDataValue.get<picojson::object>();

				int i = 0;
				std::vector<float> floatData;
				while (actorData[std::to_string(i)].is<double>()) {
					floatData.emplace_back(static_cast<float>(actorData[std::to_string(i)].get<double>()));
					i++;
				}

				CreateActorEditor(scenePtr, actorData["ActorName"].get<std::string>(), std::move(floatData));
			}

			if (numZeroFlag) {
				scenePtr->Active();
				numZeroFlag = false;
			}
			else
				scenePtr->Pause();
		}

		return true;
	}
}