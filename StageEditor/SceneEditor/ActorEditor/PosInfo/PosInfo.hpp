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
		virtual ~PosInfo() = default;

		void CustomizeUpdate() override;

		//‚±‚ÌPosInfo‚ª’l‚ğŠ—L‚Å‚«‚½‚©‚Ç‚¤‚©
		bool IsOK();

		const GameLib::Vector2& GetPosition();
	};
}