#pragma once
#include"GameLib/include/Actor/RootActor.hpp"

namespace StageEditor
{
	class StartActor : public GameLib::RootActor
	{
	public:
		StartActor()
			:GameLib::RootActor{}
		{}
		virtual ~StartActor() = default;

	};
}