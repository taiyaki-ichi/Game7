#pragma once
#include"PosInfo.hpp"

namespace StageEditor
{
	//a,b‚Ì‹——£
	float GetLength(PosInfo* a, PosInfo* b);

	//’¼üabc‚ªŒv‰ñ‚è‚©‚Ç‚¤‚©
	bool IsClockwise(PosInfo* a, PosInfo* b, PosInfo* c);
}