#include"StageEditor.hpp"
#include"ConsoleMessage/ConsoleMessage.hpp"

namespace StageEditor
{
	
	StageEditor::StageEditor(GameLib::Actor* actor)
		:GameLib::Actor{actor}
		, mIsEditingActor{false}
		, mConsoleMessage{nullptr}
	{
		mConsoleMessage = new ConsoleMessage{ this };
	
	}

	void StageEditor::CustomizeUpdate()
	{
		ProcessMessage();
	}

	void StageEditor::UpdateConsoleScreen()
	{

	}


	void StageEditor::SaveStage(std::string)
	{

	}

	void StageEditor::LoadStage(std::string)
	{

	}

	void StageEditor::ProcessMessage()
	{
		auto strs = mConsoleMessage->GetMessage();
		if (strs.size() > 0)
		{
			std::system("cls");

			for (auto& s : strs)
				std::cout << s << "\n";

			mConsoleMessage->ClearMessage();
		}
	}


	void StageEditor::AddScene(std::string)
	{

	}

	void StageEditor::RemoveScene(std::string)
	{

	}

	void StageEditor::ChangeScene(std::string)
	{

	}

}