#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Stage::BackGround
{
	
	class ObjectBase : public GameLib::Actor
	{
		GameLib::Vector2 mPosition;

		//中心からの幅
		float mMarginX;
		float mMarginY;

		//どれだけ動くか
		float mMoveRateX;
		float mMoveRateY;

		//ここポインタにしてアニメーションを入れられるようにしてもいいな
		GameLib::DrawTexture mTexture;

	public:
		ObjectBase(GameLib::Actor* owner, std::string&& fileName, int drawOrder);
		virtual ~ObjectBase() = default;

		void CustomizeUpdate() override;

		void SetMarginXY(float x, float y);
		void SetPosition(GameLib::Vector2&& pos);

	protected:
		//派生クラスのコンストラクタ内で使う予定
		void SetScale(float s);
		void SetMoveRateXY(float x, float y);
	};
}