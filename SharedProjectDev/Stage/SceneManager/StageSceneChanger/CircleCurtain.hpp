#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/CustomizeDrawBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Draw/DrawCircle.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace Stage
{
	//Sceneを変更する際の暗転->明転の処理
	class CircleCurtain : public GameLib::CustomizeDrawBase
	{
		GameLib::DrawCircle mCircle;
		GameLib::DrawRect mRect;
		
		//0はじめ、1真っ暗にしている、2真っ暗、3明るくしている、4明るくなった
		int mStateFlag;

		constexpr static float RADIUS_SPEED = 15.f;
		constexpr static float MAX_RADIUS = 800.f;

	public:
		CircleCurtain();
		virtual ~CircleCurtain() = default;

		//posを中心にして暗転
		void TurnDark(const GameLib::Vector2& pos);

		//まっくらになったかどうか
		bool IsDark();

		//posを中止にして明転
		void TurnBright(const GameLib::Vector2& pos);

		//明るくなったか
		bool IsBright();

		void Draw() override;

		//毎フレーム呼び出す
		void Update();
	};
}