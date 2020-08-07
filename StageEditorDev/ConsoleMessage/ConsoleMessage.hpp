#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace StageEditor
{
	class ConsoleMessage : public GameLib::Actor
	{

		std::vector<std::string> mMessage;

		void RunGetMessageThread();

	public:
		ConsoleMessage(GameLib::Actor* editor);
		virtual ~ConsoleMessage() = default;

		void CustomizeUpdate() override;

		//メッセージの取得、基本size=0な感じ
		const std::vector<std::string>& GetMessage() const;

		//メッセージをクリア
		void ClearMessage();
	};
}