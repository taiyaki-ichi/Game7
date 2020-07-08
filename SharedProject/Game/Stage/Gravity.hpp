#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"Game/Dir4Vec.hpp"
#include"PhysicsModel.hpp"

namespace Game::Stage
{
	class Gravity : public GameLib::Actor
	{
		static float mSize;
		static Dir4 mDir4;

	public:
		Gravity(GameLib::Actor* owner);
		virtual ~Gravity() = default;

		//ViewPortの回転の回転の制御
		void CustomizeUpdate() override;

		static GameLib::Vector2 GetGravityVector2();

		static GameLib::Vector2 GetVector2(const Dir4& dir4, float size);
		
		//Vector2をDir4Vecに丸め込む
		static Dir4Vec GetDir4Vec(const GameLib::Vector2& vec);

		//Vector2のDir4方向の大きさ、マイナスの場合もあり
		static float GetDir4Size(const GameLib::Vector2& vec, const Dir4& dir4);

		static float GetGravityRotation();

		//vector2を垂直、水平方向に反転
		static GameLib::Vector2 GetVerticalFlippedVector2(const GameLib::Vector2& vec);
		static GameLib::Vector2 GetHolizonalFlippedVector2(const GameLib::Vector2& vec);

		//フレーム当たりの力の合計や重力の方向を踏まえて更新
		static void UpdatePhysicsModel(PhysicsModel& model, const GameLib::Vector2& power, float horizonMaxSpeed = -1.f, float virticalMaxSpeed = -1.f, bool isRotaion = true);

		
		static float GetGravitySize() noexcept;
		static const Dir4& GetGravityDir4() noexcept;
		/*
		static void SetSize(float s);
		static void SetDir4(const Dir4& dir4);
		static void SetDir4Vec(const Dir4Vec& dir4Vec);
		*/
	};
}