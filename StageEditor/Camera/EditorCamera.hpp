#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace StageEditor
{
	class Camera : public GameLib::Actor
	{
	public:
		Camera(GameLib::Actor*);
		
		void CustomizeUpdate() override;

		void Reset();
	};
}