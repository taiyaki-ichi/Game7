#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<string>

namespace StageEditor
{

	class Display : public GameLib::Actor
	{
	public:
		Display(GameLib::Actor* owner, int updateOrder = 0);
		virtual ~Display() = default;

		void CustomizeUpdate() override;

	
	};
}