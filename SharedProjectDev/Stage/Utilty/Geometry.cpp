#include"Geometry.hpp"

namespace Stage
{

	GameLib::Vector2 GetParallelRectAdjustVec(const GameLib::Collider& character, const GameLib::Collider& ground, float roundXY)
	{
		return GetParallelRectAdjustVec(character, ground, roundXY, roundXY);

	}

	GameLib::Vector2 GetParallelRectAdjustVec(const GameLib::Collider& character, const GameLib::Collider& ground, float roundX, float roundY)
	{

		using GameLib::Vector2;
		using GameLib::Collider;

		Vector2 characterPos = character.GetPosition();
		Vector2 groundPos = ground.GetPosition();

		float characterScale = character.GetScale();
		float characterWidth = character.GetWidth() * characterScale;
		float characterHeigth = character.GetHeigth() * characterScale;

		float characterRot = character.GetRotation();
		if ((GameLib::PI / 4.f <= characterRot && characterRot < GameLib::PI * 3.f / 4.f) ||
			(GameLib::PI * 5.f / 4.f <= characterRot && characterRot < GameLib::PI * 7.f / 4.f))
			std::swap(characterWidth, characterHeigth);

		float groundScale = ground.GetScale();
		float groundWidth = ground.GetWidth() * groundScale;
		float groundHeigth = ground.GetHeigth() * groundScale;

		float groundRot = ground.GetRotation();
		if ((GameLib::PI / 4.f <= groundRot && groundRot < GameLib::PI * 3.f / 4.f) ||
			(GameLib::PI * 5.f / 4.f <= groundRot && groundRot < GameLib::PI * 7.f / 4.f))
			std::swap(groundWidth, groundHeigth);

		float idealX = characterWidth / 2.f + groundWidth / 2.f;
		float idealY = characterHeigth / 2.f + groundHeigth / 2.f;

		Vector2 reativeVec = groundPos - characterPos;

		float adX = (reativeVec.x > 0.f) ? reativeVec.x - idealX : idealX + reativeVec.x;
		float adY = (reativeVec.y > 0.f) ? reativeVec.y - idealY : idealY + reativeVec.y;

		//TODO
		if (std::fabs(adX) < std::fabs(adY) && std::fabs(adX) > std::fabs(roundX))
			return { adX + 0.1f,0.f };
		else if (std::fabs(adY) < std::fabs(adX) && std::fabs(adY) > std::fabs(roundY))
			return { 0.f,adY + 0.1f };
		else
			return { 0.f,0.f };

	}
}