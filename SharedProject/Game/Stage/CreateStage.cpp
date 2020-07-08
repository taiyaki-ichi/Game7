#include"CreateStage.hpp"
#include"Json/picojson.hpp"
#include <fstream>

namespace Game::Stage
{
	bool CreateStage(Stage* stagePtr, std::string&& fileName)
	{
		std::ifstream ifs(fileName, std::ios::in);
		if (ifs.fail()) {
			//::cerr << "failed to read " << fileName << std::endl;
			return false;
		}

		const std::string json((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
		ifs.close();

		picojson::value v;
		const std::string err = picojson::parse(v, json);
		if (err.empty() == false) {
			//std::cerr << err << std::endl;
			return false;
		}

		picojson::object& stageObject = v.get<picojson::object>();
		for (auto& a : stageObject) {

		}
	}
}