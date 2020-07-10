#include"CreateStage.hpp"
#include"Json/picojson.hpp"
#include <fstream>
#include"Stage.hpp"
#include"Scene/CreateActor.hpp"
#include"Scene/Scene.hpp"
#include"Player.hpp"
#include"Scene/CreateWarp.hpp"
#include"Scene/Actor/WarpBase.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace Game::Stage
{
	bool CreateStage(Stage* stagePtr, std::string&& fileName)
	{
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

		//そのシーンにPlayerがいたらスタートシーンとする
		bool startSceneFlag;


		picojson::object& stageObj = v.get<picojson::object>();
		picojson::array& sceneDataArray = stageObj["SceneData"].get<picojson::array>();
		for (auto& sceneDataValue : sceneDataArray) {

			startSceneFlag = false;

			picojson::object& sceneData = sceneDataValue.get<picojson::object>();
			picojson::array& actorsData = sceneData["ActorsData"].get<picojson::array>();

			std::string sceneName = sceneData["SceneName"].get<std::string>();
			auto scenePtr = stagePtr->AddScene(std::move(sceneName));

			for (auto& actorDataValue : actorsData) {
				picojson::object& actorData = actorDataValue.get<picojson::object>();

				int i = 0;
				std::vector<float> floatData;
				while (actorData[std::to_string(i)].is<double>()) {
					floatData.emplace_back(static_cast<float>(actorData[std::to_string(i)].get<double>()));
					i++;
				}

				std::string actorName = actorData["ActorName"].get<std::string>();

				if (actorName == "Player") {
					startSceneFlag = true;
					stagePtr->SetPlayerAndNowScene(new Player::Actor{ stagePtr,std::move(floatData) }, scenePtr);
				}
				else if (actorName == "Warp") {
					std::string warpGateType = actorData["WarpType"].get<std::string>();
					std::string nameTag = actorData["NameTag"].get<std::string>();
					std::string d = actorData["DestinationNameTag"].get<std::string>();
					auto ptr = CreateWarp(scenePtr, std::move(warpGateType), std::move(floatData));
					if (ptr)
						ptr->SetStringInfo(std::move(nameTag), std::move(d));
				}
				else
					CreateActor(scenePtr, std::move(actorName), std::move(floatData));

			}

			if (startSceneFlag)
				scenePtr->Active();
			else
				scenePtr->Pause();

		}

		GameLib::Collider::SetAllIsDrawing(false);

		return true;
	}
}