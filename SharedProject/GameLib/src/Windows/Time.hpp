#pragma once

namespace GameLib
{
	//現在の時間の取得
	unsigned long GetTime();

	//prevTimeからwaitTime時間Sleep
	void Wait(unsigned long preTime, unsigned long waitTime);
}