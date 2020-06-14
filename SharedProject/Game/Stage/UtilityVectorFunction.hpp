#pragma once
#include<cmath>
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Math/Vector2.hpp"

namespace Game::Stage
{
	using GameLib::Vector2;
	using GameLib::Collider;

	inline Vector2 GetParallelRectAdjustVec(const Collider& character, const Collider& ground, float round = 0.f) {

		Vector2 characterPos = character.GetPosition();
		Vector2 groundPos = ground.GetPosition();

		float characterScale = character.GetScale();
		float characterWidth = character.GetWidth() * characterScale;
		float characterHeigth = character.GetHeigth() * characterScale;

		float groundScale = ground.GetScale();
		float groundWidth = ground.GetWidth() * groundScale;
		float groundHeigth = ground.GetHeigth() * groundScale;

		float idealX = characterWidth / 2.f + groundWidth / 2.f;
		float idealY = characterHeigth / 2.f + groundHeigth / 2.f;

		Vector2 reativeVec = groundPos - characterPos;

		float adX = (reativeVec.x > 0.f) ? reativeVec.x - idealX : idealX + reativeVec.x;
		float adY = (reativeVec.y > 0.f) ? reativeVec.y - idealY : idealY + reativeVec.y;

		if (std::fabs(adX) < std::fabs(adY) && std::fabs(adX) > std::fabs(round))
			return { adX,0.f };
		else if (std::fabs(adY) < std::fabs(adX) && std::fabs(adY) > std::fabs(round))
			return { 0.f,adY };
		else
			return { 0.f,0.f };
	}
}