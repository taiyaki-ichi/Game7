#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"Stage/Utilty/Dir4Vec.hpp"

namespace Stage
{
	class Apple : public GameLib::Actor
	{
		GameLib::DrawTexture mTexture;

		GameLib::Vector2 mCenter;

		GameLib::Vector2 mVelocity;
		bool mIsRotation;

	public:
		Apple(GameLib::Actor* gravityBox);

		void SetCenter(const GameLib::Vector2& pos);

		void CustomizeUpdate() override;

		void GoCenter();
		void Fall(const Dir4& dir);
		void Rotation();

		void BeginWorking();
		void BeginToRest();

		void SetDrawOrder(int o);
	};
}