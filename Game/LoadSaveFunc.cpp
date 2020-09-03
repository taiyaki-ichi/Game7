#include"LoadSaveFunc.hpp"
#include <fstream>
#include"StageData.hpp"
#include"GameScene/StageDataParam.hpp"


namespace Game
{

	namespace {
		constexpr char FILE_NAME[] = "../Data/save.bin";
	}

	//有効なセーブデータかどうか
	bool CheckStageData(const HexVec& vec)
	{
		auto iter = gStageData.find(vec);
		if (iter != gStageData.end() && iter->second.size() == StageDataParam::STAGE_STRING_NUM)
			return true;
		else
			return false;
	}

	GameData LoadGameData()
	{
		std::ifstream file(FILE_NAME, std::ios::binary | std::ios::in);

		//ファイルが存在しない場合
		if (!file)
			return {};
		
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

			auto pos = HexVec{ x,y };
			if (CheckStageData(pos))
				result.mSaveData.insert_or_assign(std::move(pos), flag);
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