#include"CreateBackGround.hpp"
#include"Parts/Horizon.hpp"
#include"Parts/Object/BackGroundTree.hpp"
#include"Stage/WindowSize.hpp"
#include"Parts/Object/CreateSlideObjects.hpp"

namespace Stage::BackGround
{
	void CreateSharpTreeForest(GameLib::Actor* owner)
	{
		new Horizon{ owner };

		CreateSlideObjects<SharpTree230>(owner, 5, 100.f, 200.f);
		CreateSlideObjects<SharpTree180>(owner, 4, 100.f, 140.f);
		CreateSlideObjects<SharpTree130>(owner, 4, 150.f, 90.f);

		
	}
}