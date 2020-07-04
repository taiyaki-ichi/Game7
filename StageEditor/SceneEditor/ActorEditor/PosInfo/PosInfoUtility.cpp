#include"PosInfo.hpp"
#include "PosInfoUtility.hpp"

namespace StageEditor
{
	float GetLength(PosInfo* a, PosInfo* b) {
		float dx = a->GetPosition().x - b->GetPosition().x;
		float dy = a->GetPosition().y - b->GetPosition().y;
		return std::sqrt(dx * dx + dy * dy);
	}
	bool IsClockwise(PosInfo* a, PosInfo* b, PosInfo* c)
	{
		GameLib::Vector2 vec1 = b->GetPosition() - a->GetPosition();
		GameLib::Vector2 vec2 = c->GetPosition() - b->GetPosition();
		return GameLib::Vector2::Cross(vec1, vec2) > 0.f;
	}
	GameLib::Vector2 GetCenter(PosInfo* a, PosInfo* b)
	{
		float minX = (a->GetPosition().x < b->GetPosition().x) ? a->GetPosition().x : b->GetPosition().x;
		float mixY = (a->GetPosition().y < b->GetPosition().y) ? a->GetPosition().y : b->GetPosition().y;
		float w = GetWidth(a, b);
		float h = GetHeight(a, b);
		return { minX + w / 2.f,mixY + h / 2.f };

	}
	float GetWidth(PosInfo* a, PosInfo* b)
	{
		return std::abs(a->GetPosition().x - b->GetPosition().x);
	}
	float GetHeight(PosInfo* a, PosInfo* b)
	{
		return std::abs(a->GetPosition().y - b->GetPosition().y);
	}
}