#include"TearGemEditor.hpp"
#include"Stage/SceneManager/Scene/Actor/TearGem/TearGemParam.hpp"

namespace StageEditor
{
	std::vector<std::string> TearGemEditor::mNumbers{};

	TearGemEditor::TearGemEditor(GameLib::Actor* actor)
		:ActorEditorBase{ actor,"TearGem",1,1 }
		, mTexture{ "../Assets/Item/Gem/tear.png" }
	{
		mTexture.SetScale(Stage::TearGemParam::SCALE);

		mCollider.SetWidthAndHeith(Stage::TearGemParam::WIDTH, Stage::TearGemParam::HEIDHT);
		mCollider.SetScale(Stage::TearGemParam::SCALE);

		auto checker = [this](int num, const std::string& str) {
			if (num == 0)
			{
				//ダブりがないならおｋ
				int i = 0;
				for (; i < mNumbers.size(); i++)
					if (str == mNumbers[i])
						break;
			
				if (i == mNumbers.size()) {
					mNumbers.emplace_back(str);
					return true;
				}
				else
					return false;
			}
			return true;
		};

		mStringData.SetDataCecker(std::move(checker));
	}

	TearGemEditor::~TearGemEditor()
	{
		if (mStringData.GetDataNum() == 1)
		{
			auto iter = std::find(mNumbers.begin(), mNumbers.end(), mStringData[0]);
			if (iter != mNumbers.end())
				mNumbers.erase(iter);
		}
	}

	void TearGemEditor::Update()
	{
		mTexture.SetPosition(mPosData[0]);
		mCollider.SetPosition(mPosData[0] + GameLib::Vector2{ 0.f,Stage::TearGemParam::COLLIDER_ADJUST_Y });

		//stringDataの確認
		if (mPosData.IsOK() && mStringData.IsOK()) {
			if (!(mStringData[0] == "1" || mStringData[0] == "2" || mStringData[0] == "3"))
				SetState(GameLib::Actor::State::Dead);
		}
	}

	void TearGemEditor::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
	}

	void TearGemEditor::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
	}

	void TearGemEditor::PrintStringDataInfo()
	{
		std::cout << "1 or 2 or 3 (non - overlapping)\n";
	}

	const std::vector<std::string>& TearGemEditor::GetNumbers()
	{
		return mNumbers;
	}

	void TearGemEditor::ResetNumbers()
	{
		mNumbers.clear();
	}
}