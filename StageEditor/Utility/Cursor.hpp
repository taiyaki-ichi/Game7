#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace StageEditor
{
	class Cursor : public GameLib::Actor
	{
		GameLib::Collider mCollider;

	public:
		Cursor(GameLib::Actor* owner);
		virtual ~Cursor() = default;

		void CustomizeUpdate() override;
	};
}