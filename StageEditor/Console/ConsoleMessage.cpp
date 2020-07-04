#include"ConsoleMessage.hpp"
#include<thread>
#include<vector>
#include"GameLib/include/InputState/InputState.hpp"

namespace StageEditor
{

	std::vector<std::string> ConsoleMessage::mStrings;

	namespace {
		std::vector<std::string> gConsoleMessages;
	}

	void GetConsoleMessage()
	{
		while (1) {
			std::string str;
			std::cin >> str;
			gConsoleMessages.emplace_back(std::move(str));
		}
	}

	ConsoleMessage::ConsoleMessage(GameLib::Actor* owner)
		:GameLib::Actor(owner,-100)
	{
		std::thread getMessage(GetConsoleMessage);
		getMessage.detach();
	}

	void ConsoleMessage::CustomizeUpdate()
	{
		using namespace GameLib;

		if (InputState::GetState(Key::Enter) == ButtonState::Pressed) {
			mStrings.clear();
			for (int i = 0; i < gConsoleMessages.size(); i++)
				mStrings.emplace_back(gConsoleMessages[i]);
			gConsoleMessages.clear();
			std::system("cls");
		}
	}

	const std::vector<std::string>& ConsoleMessage::GetStrings() noexcept
	{
		return mStrings;
	}





}