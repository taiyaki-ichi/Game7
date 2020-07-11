#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Game::Stage::BackGround
{

	class FallObjectBase : public GameLib::Actor
	{
		GameLib::DrawTexture mTexture;
		
		//BackGroundのRange内に収まるように、つまりViewPortの影響を受けていない
		GameLib::Vector2 mPosition;

		//deltaPosは風的なイメージ
		GameLib::Vector2 mDeltaPos;
		float mDeltaRot;

		float mMoveRate;

	public:
		FallObjectBase(GameLib::Actor* owner, std::string&& fileName, GameLib::Vector2&& startPos, float startRot, float scale,
			GameLib::Vector2&& deltaPos, float deltaRot, float moveRate,int drawOrder);
		virtual ~FallObjectBase() = default;

		void CustomizeUpdate() override;
	};

}