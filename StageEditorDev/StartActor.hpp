#pragma once
#include"GameLib/include/Actor/RootActor.hpp"
#include"StageEditor.hpp"

namespace StageEditor
{
	class StartActor :public GameLib::RootActor
	{
	public:
		StartActor()
			:GameLib::RootActor{}
		{
			new StageEditor{ this };
		}
	};
}