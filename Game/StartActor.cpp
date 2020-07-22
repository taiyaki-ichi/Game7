#include"StartActor.hpp"
#include"Game/StageSelect/StageSelect.hpp"


namespace Game
{
	StartActor::StartActor()
		:RootActor()
	{
		new StageSelect::StageSelect{ this };
	}
	void StartActor::CustomizeUpdate()
	{
		

		

	}
}