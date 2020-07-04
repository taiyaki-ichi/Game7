#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<string>
#include<vector>
#include<functional>

namespace StageEditor
{

	class ConsoleMessage : public GameLib::Actor
	{
		static std::vector<std::string> mStrings;

	public:
		ConsoleMessage(GameLib::Actor* owner);
		virtual ~ConsoleMessage() = default;

		void CustomizeUpdate() override;

		static const std::vector<std::string>& GetStrings() noexcept;
	};


}