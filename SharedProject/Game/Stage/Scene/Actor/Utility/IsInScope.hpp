#pragma once
#include"GameLib/include/Math/Vector2.hpp"

namespace Game::Stage
{
	//‰æ–Ê‚Ì’†S‚©‚ç‚±‚Ì”ÍˆÍ“à‚Épos‚ª‚ ‚é‚©‚Ç‚¤‚©
	bool IsInScope(const GameLib::Vector2& pos, float left, float right, float bottom, float top);
	bool IsInScope(const GameLib::Vector2& pos, float w, float h);
}