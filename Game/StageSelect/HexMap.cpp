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
		mMap.emplace(std::make_pair(1, 0), StageData{"",StageState::Open});
		mMap.emplace(std::make_pair(2, 0), StageData{"",StageState::Close});
		mMap.emplace(std::make_pair(3, 0), StageData{"",StageState::Close });
		mMap.emplace(std::make_pair(1, 1), StageData{ "",StageState::Close });
		mMap.emplace(std::make_pair(2, -1), StageData{ "",StageState::Close });

		new DrawHexMap{ this,mMap };

		mPlayerIcon = new PlayerIcon{ this };
		mPlayerIcon->SetPosision(GameLib::Vector2{ 0.f,0.f });
	}

	void HexMap::CustomizeUpdate()
	{
		auto pos = mPlayerIcon->GetPosition();
		GameLib::Viewport::SetPos(pos);
		if (GameLib::InputState::GetState(GameLib::Key::E) == GameLib::ButtonState::Pressed)
			pos += HexMapParam::UNIT_Y;
		if (GameLib::InputState::GetState(GameLib::Key::D) == GameLib::ButtonState::Pressed)
			pos += HexMapParam::UNIT_X;
		if (GameLib::InputState::GetState(GameLib::Key::X) == GameLib::ButtonState::Pressed)
			pos += HexMapParam::UNIT_X - HexMapParam::UNIT_Y;

		if (GameLib::InputState::GetState(GameLib::Key::Z) == GameLib::ButtonState::Pressed)
			pos -= HexMapParam::UNIT_Y;
		if (GameLib::InputState::GetState(GameLib::Key::A) == GameLib::ButtonState::Pressed)
			pos -= HexMapParam::UNIT_X;
		if (GameLib::InputState::GetState(GameLib::Key::W) == GameLib::ButtonState::Pressed)
			pos -= HexMapParam::UNIT_X - HexMapParam::UNIT_Y;
		mPlayerIcon->SetPosision(pos);
		

	}
}