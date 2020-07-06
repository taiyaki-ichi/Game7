#include"FileFunc.hpp"
#include"Json/picojson.hpp"
#include <fstream>

namespace StageEditor
{
	void SaveStageData(const std::string& stageName, std::unordered_map<std::string, ActorData>&& stageData, const std::string& fileName)
	{
		picojson::array allData;
		for (auto iter = stageData.begin(); iter != stageData.end(); iter++)
		{
			picojson::array actorsData;
			for (auto& actorData : iter->second)
			{
				picojson::object dataActor;
				for (auto& posInfo : actorData.second)
				{
					dataActor.insert(std::make_pair(posInfo.first, static_cast<double>(posInfo.second)));
				}
				dataActor.insert(std::make_pair("ActorName", actorData.first));
				actorsData.push_back(picojson::value(dataActor));
			}
			
			picojson::object sceneData;
			sceneData.insert(std::make_pair("SceneName", iter->first));
			sceneData.insert(std::make_pair("ActorsData", actorsData));

			allData.push_back(picojson::value(sceneData));
		}


		std::ofstream ofs(fileName);
		ofs << picojson::value(allData).serialize(true) << std::endl;
	}
}