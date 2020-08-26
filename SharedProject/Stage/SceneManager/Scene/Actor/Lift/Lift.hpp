#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Stage
{
	//StageActorBeseÇ©ÇÁîhê∂Ç≥ÇπÇƒÇ¢Ç»Ç¢ÇÃÇ≈SceneÇ…éùÇΩÇπÇƒÇÕÇ¢ÇØÇ»Ç¢
	class Lift : public GameLib::Actor
	{
		GameLib::Collider mCollider;
		GameLib::DrawTexture mTexture;

	public:
		Lift(GameLib::Actor*);

		void CustomizeUpdate() override;

		void SetPosition(const GameLib::Vector2&);
		const GameLib::Vector2& GetPosition() const;

		void BeginWorking();
		void BeginToRest();
	};
}