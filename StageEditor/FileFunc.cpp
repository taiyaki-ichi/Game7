#include"FileFunc.hpp"
#include"Json/picojson.hpp"
#include <fstream>

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
}