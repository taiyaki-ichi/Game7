#include"SaveFunc.hpp"
#include"Json/picojson.hpp"
#include<fstream>
#include<utility>

namespace StageEditor
{
	void SaveStageData(std::string&& fileName, std::unordered_map<std::string,std::vector<ActorData>>&& data)
	{

		picojson::array allData;
		for (auto& sceneDataAndName: data)
		{
			picojson::array actorsData;
			for (auto& actorData : sceneDataAndName.second)
			{
				picojson::object dataActor;
				for (int i = 0; i < actorData.mPosData.size(); i++) {
					dataActor.insert(std::make_pair("FloatData" + std::to_string(i * 2), static_cast<double>(actorData.mPosData[i * 2].x)));
					dataActor.insert(std::make_pair("FloatData" + std::to_string(i * 2 + 1), static_cast<double>(actorData.mPosData[i * 2 + 1].x)));
				}
				for (int i = 0; i < actorData.mStringData.size(); i++) {
					dataActor.insert(std::make_pair("StringData" + std::to_string(i), actorData.mStringData[i]));

				}

				dataActor.insert(std::make_pair("ActorName", actorData.mNameTag));
				actorsData.push_back(picojson::value(dataActor));
			}

			picojson::object sceneData;
			sceneData.insert(std::make_pair("SceneName", sceneDataAndName.first));
			sceneData.insert(std::make_pair("ActorsData", actorsData));

			allData.push_back(picojson::value(sceneData));
		}

		picojson::object stageAllData;
		stageAllData.insert(std::make_pair("SceneData", picojson::value(allData)));

		std::ofstream ofs(fileName);
		ofs << picojson::value(stageAllData).serialize(true) << std::endl;
	}
}