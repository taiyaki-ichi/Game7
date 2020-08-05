#include"CreateBackGround.hpp"
#include"Parts/Horizon.hpp"
#include"Parts/Object/BackGroundTree.hpp"
#include"Stage/WindowSize.hpp"
#include"Parts/Object/CreateSlideObjects.hpp"
#include"Parts/Object/BackGroundTotemPole.hpp"
#include"Parts/Object/BackGroundTemple.hpp"

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
}