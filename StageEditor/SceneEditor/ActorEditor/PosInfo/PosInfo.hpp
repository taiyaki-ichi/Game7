#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Math/Vector2.hpp"

namespace StageEditor
{
	class EditingActorBase;

	class PosInfo : public GameLib::Actor
	{

		GameLib::Vector2 mPosition;
		bool mIsOK;

	public:
		PosInfo(GameLib::Actor* owner);
		PosInfo(GameLib::Actor* owner, GameLib::Vector2&& vec);
		virtual ~PosInfo() = default;

		void CustomizeUpdate() override;

		//Ç±ÇÃPosInfoÇ™ílÇèäóLÇ≈Ç´ÇΩÇ©Ç«Ç§Ç©
		bool IsOK();

		const GameLib::Vector2& GetPosition();
	};
}