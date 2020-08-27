#include"CreateBackGround.hpp"
#include"Parts/Horizon.hpp"
#include"Parts/Object/BackGroundTree.hpp"
#include"Stage/WindowSize.hpp"
#include"Parts/Object/CreateSlideObjects.hpp"
#include"Parts/Object/BackGroundTotemPole.hpp"
#include"Parts/Object/BackGroundTemple.hpp"
#include"Parts/Cave.hpp"
#include"Parts/Object/BackGroundThroat.hpp"

namespace Stage::BackGround
{
	void CreateSharpTreeForest(GameLib::Actor* owner)
	{
		new Horizon{ owner };

		CreateSlideObjects<SharpTree230>(owner, 5, 100.f, 200.f);
		CreateSlideObjects<SharpTree180>(owner, 4, 100.f, 140.f);
		CreateSlideObjects<SharpTree130>(owner, 4, 150.f, 90.f);
		
	}

	void CreateRoundTreeForest(GameLib::Actor* owner)
	{
		new Horizon{ owner };

		CreateSlideObjects<RoundTree230>(owner, 5, 100.f, 200.f);
		CreateSlideObjects<RoundTree180>(owner, 3, 150.f, 140.f);
		CreateSlideObjects<RoundTree130>(owner, 3, 200.f, 90.f);
	}

	void CreateIndianVillage(GameLib::Actor* owner)
	{
		new Horizon{ owner };

		CreateSlideObjects<TotemPole230>(owner, 5, 100.f, 180.f);
		CreateSlideObjects<TotemPole180>(owner, 4, 100.f, 120.f);
		CreateSlideObjects<TotemPole130>(owner, 4, 150.f, 70.f);
	}

	void CreateSanctuary(GameLib::Actor* owner)
	{
		new Horizon{ owner };

		CreateSlideObjects<Temple230>(owner, 3, 150.f, 180.f);
		CreateSlideObjects<Temple180>(owner, 4, 150.f, 130.f);
		CreateSlideObjects<Temple130>(owner, 4, 160.f, 35.f);
	}

	void CreateCreepyCave(GameLib::Actor* actor)
	{
		new Cave{ actor };

		constexpr int num120 = 2;
		constexpr int num100 = 3;
		constexpr int num140 = 2;

		constexpr float MarginX = 50.f;
		constexpr float MarginX140 = 100.f;

		CreateSlideObjects<Throat120>(actor, num120, MarginX, -10.f);
		CreateSlideObjects<Throat100>(actor, num100, MarginX, 10.f);
		CreateSlideObjects<Throat140>(actor, num140, MarginX140, -150.f);

		float w = MarginX * 2.f + WindowSize::WIDTH;
		float w140 = MarginX140 * 2.f + WindowSize::WIDTH;

		auto bg120 = CreateSlideObjects<Throat120>(actor, num120, MarginX, 10.f, true);
		for (auto tmp : bg120)
			tmp->SetPosition(tmp->GetPosition() + GameLib::Vector2{ w / static_cast<float>(num120) / 2.f ,0.f });
		auto bg100 = CreateSlideObjects<Throat100>(actor, num100, MarginX, -10.f, true);
		for(auto tmp : bg100)
			tmp->SetPosition(tmp->GetPosition() + GameLib::Vector2{ w / static_cast<float>(num100) / 2.f ,0.f });

		auto bg140 = CreateSlideObjects<Throat140>(actor, num140, MarginX140,150.f, true);
		for (auto tmp : bg140)
			tmp->SetPosition(tmp->GetPosition() + GameLib::Vector2{ w140 / static_cast<float>(num140) / 2.f ,0.f });

	}

}