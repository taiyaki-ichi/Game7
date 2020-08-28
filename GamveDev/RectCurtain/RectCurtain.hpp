#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace Game
{
	class RectCurtain : public GameLib::Actor
	{
		GameLib::DrawRect mRect;

		//0:âΩÇ‡Å@-1:close 1:open
		int mState;

	public:
		RectCurtain(GameLib::Actor*);
		virtual ~RectCurtain() = default;

		void CustomizeUpdate() override;

		void Open();
		void Close();

		bool IsOpen();
		bool IsClose();

	};
}