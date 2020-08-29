#include"LoadSaveFunc.hpp"
#include <fstream>

namespace Game
{

	namespace {
		constexpr char FILE_NAME[] = "../Data/save.bin";
	}


	GameData LoadGameData()
	{
		std::ifstream file(FILE_NAME, std::ios::binary | std::ios::in);

		//ƒtƒ@ƒCƒ‹‚ª–³Œø‚Ìê‡
		if (!file)
			return START_GAMEDATA;
		
		GameData result;

		file >> result.mNowPos.x;
		file >> result.mNowPos.y;
		file >> result.mPlayerLifeNum;
		file >> result.mPlayerGemNum;

		int x{};
		int y{};
		unsigned char flag{};
		while (file >> x)
		{
			file >> y;
			file >> flag;
			result.mSaveData.insert_or_assign({ x,y }, flag);
		}

		file.close();

		return result;
	}

	void SaveGameData(const GameData& data)
	{
		std::ofstream file(FILE_NAME, std::ios::binary | std::ios::out);

		file << data.mNowPos.x << "\n";
		file << data.mNowPos.y << "\n";
		file << data.mPlayerLifeNum << "\n";
		file << data.mPlayerGemNum << "\n";

		for (const auto& saveData : data.mSaveData)
		{
			file << saveData.first.x << "\n";
			file << saveData.first.y << "\n";
			file << saveData.second << "\n";
		}

		file.close();
	}
}