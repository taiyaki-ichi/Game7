#pragma once
#include<Windows.h>
#include<string>

namespace GameLib
{
	//ウィンドウの生成
	bool CreateAppWindow(const std::string& windowName,float windowWidth,float windowHeigth);
}