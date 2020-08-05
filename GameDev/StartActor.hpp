#pragma once
#include"GameLib/include/Actor/RootActor.hpp"
#include"Stage/Stage.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace dev
{
	class StartActor : public GameLib::RootActor
	{
	public:
		StartActor()
			:GameLib::RootActor{}
		{
			new Stage::Stage{ this,"../Data/Stage/aaa.json" };
			GameLib::Collider::SetIsDebug(true);
		}

		virtual ~StartActor() = default;

		//void CustomizeUpdate() override;

	private:

	};
}