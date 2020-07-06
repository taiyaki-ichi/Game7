#include"ConsoleMessage.hpp"
#include<thread>
#include<vector>
#include <mutex>
#include"GameLib/include/InputState/InputState.hpp"

namespace StageEditor
{

	std::vector<std::string> ConsoleMessage::mStrings;

	namespace {
		std::mutex mtx_;
		std::vector<std::string> gConsoleMessages{};
	}

	void AddConsoleMessage(std::string&& str) {
		std::lock_guard<std::mutex> lock(mtx_);
		gConsoleMessages.emplace_back(std::move(str));
	}

	void GetConsoleMessage(std::vector<std::string>& strs) {
		std::lock_guard<std::mutex> lock(mtx_);
		strs = std::move(gConsoleMessages);
		gConsoleMessages.clear();
	}

	void ConsoleMessageLoop()
	{
		while (1) {
			std::string str;
			std::cin >> str;
			std::thread th{AddConsoleMessage, std::move(str)};
			th.join();
		}
	}

	ConsoleMessage::ConsoleMessage(GameLib::Actor* owner)
		:GameLib::Actor(owner,-100)
		, mReadCnt{-1}
	{
		std::thread getMessage{ ConsoleMessageLoop };
		getMessage.detach();
	}

	void ConsoleMessage::CustomizeUpdate()
	{
		using namespace GameLib;

		mStrings.clear();

		if (InputState::GetState(Key::Enter) == ButtonState::Pressed)
			mReadCnt = 10;

		if (mReadCnt >= 0)
			mReadCnt--;

		if (mReadCnt == 0)
		{
			std::vector<std::string> strs;
			std::thread th{ [&strs]() {
				std::lock_guard<std::mutex> lock(mtx_);
				strs = std::move(gConsoleMessages);
				//for (int i = 0; i < gConsoleMessages.size(); i++)
					//std::cout << i << ": " << gConsoleMessages[i] << std::endl;
				gConsoleMessages.clear();
			} };
			th.join();

			mStrings = std::move(strs);

			mReadCnt = -1;

			if (mStrings.size() > 0)
				std::system("cls");
		}


	}

	const std::vector<std::string>& ConsoleMessage::GetStrings() noexcept
	{
		return mStrings;
	}





}