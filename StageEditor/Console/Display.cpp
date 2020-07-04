#include"Display.hpp"
#include<thread>

namespace StageEditor
{
	std::string gConsoleMessage = "";

	void GetConsoleMessage()
	{
		while (1)
			std::cin >> gConsoleMessage;
	}

	Display::Display(GameLib::Actor* owner, int updateOrder)
		:GameLib::Actor{owner,updateOrder}
	{
		std::thread getMessage(GetConsoleMessage);
		getMessage.detach();
	}

	void Display::CustomizeUpdate()
	{
		if (gConsoleMessage.size() > 0) {
			std::system("cls");
			std::cout << "input : " << gConsoleMessage << "\n";
			gConsoleMessage = "";
		}
	}

}