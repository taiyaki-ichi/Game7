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
}