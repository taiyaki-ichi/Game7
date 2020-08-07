#include"ConsoleMessage.hpp"
#include<thread>
#include<mutex>
#include<sstream>
#include"GameLib/include/InputState/InputState.hpp"

namespace StageEditor
{
	namespace {
		std::mutex mtx;
		std::vector<std::string> gConsoleMessage{};
	}

	void GetConsleMessage()
	{
		std::lock_guard<std::mutex> lock(mtx);

		std::string str;
		std::getline(std::cin, str);

		std::stringstream strigStream{ str };
		std::string s;

		while (std::getline(strigStream, s, ' ')) {
			gConsoleMessage.emplace_back(std::move(s));
		}

	}


	ConsoleMessage::ConsoleMessage(GameLib::Actor* editor)
		:GameLib::Actor{editor,100}
		, mMessage{}
	{
		RunGetMessageThread();
	}

	void ConsoleMessage::CustomizeUpdate()
	{
		if (GameLib::InputState::GetState(GameLib::Key::Enter)==GameLib::ButtonState::Pressed)
		{
			std::vector<std::string> strs;
			std::thread th{ [&strs]() {
				std::lock_guard<std::mutex> lock(mtx);
				strs = std::move(gConsoleMessage);
				gConsoleMessage.clear();
			} };
			th.join();

			for (auto& s : strs)
				mMessage.emplace_back(s);

			RunGetMessageThread();
		}
	}

	const std::vector<std::string>& ConsoleMessage::GetMessage() const
	{
		return mMessage;
	}

	void ConsoleMessage::ClearMessage()
	{
		mMessage.clear();
	}

	void ConsoleMessage::RunGetMessageThread()
	{
		std::thread getMessage{ GetConsleMessage };
		getMessage.detach();
	}

}