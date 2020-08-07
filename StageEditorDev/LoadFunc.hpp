#pragma once
#include<string>

namespace StageEditor
{
	class StageEditor;
	bool LoadStageData(StageEditor* editor, std::string&& fileName);
}