#pragma once
#include"InfoBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"

namespace StageEditor
{
	class Vector2Info : public InfoBase
	{

		GameLib::Vector2 mVector2;

		void PrintInfo() override;

	public:
		Vector2Info(EditingActorBase* owner, std::string& infoName);
		virtual ~Vector2Info() = default;

		//コンソールからの入力とウィンドウからの入力ができるようにしたい
		void EditingInfoUpdate() override;


	};
}