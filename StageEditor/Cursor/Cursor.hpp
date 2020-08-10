#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace StageEditor
{
	class Cursor : public GameLib::Actor
	{
		GameLib::Collider mColiider;

	public:
		Cursor(GameLib::Actor* actor);
		virtual ~Cursor() = default;

		void CustomizeUpdate() override;
	};
}