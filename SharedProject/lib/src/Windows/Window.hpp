#pragma once
#include<Windows.h>
#include<string>

namespace GameLib
{
	//ウィンドウの生成
	bool CreateAppWindow(std::string&& windowName,float windowWidth,float windowHeigth);
}