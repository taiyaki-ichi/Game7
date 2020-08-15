#include"Game.hpp"
#include"StageSelect/StageSelect.hpp"
#include"StageData.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"Stage/Stage.hpp"

namespace Game
{
	Game::Game(GameLib::Actor* actor)
		:GameLib::Actor{actor}
		, mTitle{nullptr}
		, mStageSelect{nullptr}
		, mStage{nullptr}
		, mSaveData{}
		, mPlayerLifeNum{0}
		, mPlayerGemNum{ 0 }
		, mPosition{ std::make_pair(0,0) }
	{
		Load();

		//‰¼
		mStageSelect = new StageSelect{ this,mSaveData,gStageData,std::make_pair(0,0),5,5 };
	}

	void Game::CustomizeUpdate()
	{
		if (mTitle)
			UpdateTitle();
		else if (mStageSelect)
			UpdateStageSelect();
		else if (mStage)
			UpdateStage();
	}

	bool Game::Load()
	{
		//‰¼
		mSaveData.emplace(std::make_pair(1, 0), 0b1);
		//mSaveData.emplace(std::make_pair(2, 0), 0b10110);
		//mSaveData.emplace(std::make_pair(3, 0), 0b1);
	}

	bool Game::Save()
	{

	}

	void Game::UpdateTitle()
	{

	}

	void Game::UpdateStageSelect()
	{
		if (GameLib::InputState::GetState(GameLib::Key::Space) == GameLib::ButtonState::Pressed)
		{
			auto iter = gStageData.find(mStageSelect->GetChoicePos());
			if (iter != gStageData.end())
			{
				mStageSelect->SetState(GameLib::Actor::State::Dead);
				mStageSelect = nullptr;

				mPosition = iter->first;

				mStage = new ::Stage::Stage{ this,"../Data/Stage/" + iter->second[0] + ".json" };
			}

		}
	}

	void Game::UpdateStage()
	{

	}


}