#pragma once
#include"PosInfo.hpp"

namespace StageEditor
{
	//a,b‚Ì‹——£
	float GetLength(PosInfo* a, PosInfo* b);

	//’¼üabc‚ªŒv‰ñ‚è‚©‚Ç‚¤‚©
	bool IsClockwise(PosInfo* a, PosInfo* b, PosInfo* c);

	//a,b‚Ì^‚ñ’†
	GameLib::Vector2 GetCenter(PosInfo* a, PosInfo* b);

	//a,b‚Ìx•ûŒü‚Ì‹——£
	float GetWidth(PosInfo* a, PosInfo* b);
	float GetHeight(PosInfo* a, PosInfo* b);
}