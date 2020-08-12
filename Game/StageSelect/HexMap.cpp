#include"HexMap.hpp"
#include"DrawHexMap.hpp"
#include"PlayerIcon.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"HexMapParam.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

namespace Game::StageSelect
{
	HexMap::HexMap(GameLib::Actor* actor)
		:GameLib::Actor{ actor }
		, mMap{}
		, mPlayerIcon{nullptr}
	{
		mMap.emplace(std::make_pair(0,0), StageData{"",StageState::Clear});
		mMap.emplace(std::make_pair(1, 0), StageData{"",StageState::Clear});
		mMap.emplace(std::make_pair(2, 0), StageData{"",StageState::Open});
		mMap.emplace(std::make_pair(3, 0), StageData{"",StageState::Close });
		mMap.emplace(std::make_pair(1, 1), StageData{ "",StageState::Open });
		mMap.emplace(std::make_pair(2, -1), StageData{ "",StageState::Open });

		new DrawHexMap{ this,mMap };

		mPlayerIcon = new PlayerIcon{ this };
		
	}

	void HexMap::CustomizeUpdate()
	{
		UpdateIconPos();
	}

	void HexMap::UpdateIconPos()
	{
		auto pos = mPlayerIcon->GetPosition();
		GameLib::Viewport::SetPos(ToVector2(pos));
		if (GameLib::InputState::GetState(GameLib::Key::E) == GameLib::ButtonState::Pressed)
			pos = AddPair(pos, DIR_E_PAIR);
		if (GameLib::InputState::GetState(GameLib::Key::D) == GameLib::ButtonState::Pressed)
			pos = AddPair(pos, DIR_D_PAIR);
		if (GameLib::InputState::GetState(GameLib::Key::X) == GameLib::ButtonState::Pressed)
			pos = AddPair(pos, DIR_X_PAIR);

		if (GameLib::InputState::GetState(GameLib::Key::Z) == GameLib::ButtonState::Pressed)
			pos = AddPair(pos, DIR_Z_PAIR);
		if (GameLib::InputState::GetState(GameLib::Key::A) == GameLib::ButtonState::Pressed)
			pos = AddPair(pos, DIR_A_PAIR);
		if (GameLib::InputState::GetState(GameLib::Key::W) == GameLib::ButtonState::Pressed)
			pos = AddPair(pos, DIR_W_PAIR);

		auto iter = mMap.find(pos);
		if (iter != mMap.end())
		{
			if (iter->second.mStageState != StageState::Close)
				mPlayerIcon->SetPosision(pos);
		}
	}
}