#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Stage
{
	class Kira : public GameLib::Actor
	{
		int mCnt;
		GameLib::DrawTexture mTexture;

	public:
		//¶¬”ÍˆÍ‚Ì’†S
		Kira(GameLib::Actor*,const GameLib::Vector2&);
		virtual ~Kira() = default;

		void CustomizeUpdate() override;
	};
}