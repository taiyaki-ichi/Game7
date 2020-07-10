#pragma once
#include"GameLib/include/Draw/CustomizeDrawBase.hpp"

namespace Game::Stage
{
	class CurtainBase : public GameLib::CustomizeDrawBase
	{
	public:
		CurtainBase() = default;
		virtual ~CurtainBase() = default;

		virtual void Update() = 0;

		virtual bool IsClosed()=0;
		virtual void Open()=0;
		virtual bool IsOpened() = 0;
	};
}