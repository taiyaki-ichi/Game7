#pragma once
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"MaiParam.hpp"
#include"Stage/Gravity/Gravity.hpp"

namespace Stage
{
	namespace MaiState
	{
		inline void AdjustCollider(GameLib::Collider& strength, GameLib::Collider& weakness, const GameLib::Vector2& pos)
		{
			using namespace MaiParam;

			strength.SetWidthAndHeith(WIDTH, HEIGHT * STRENGTH_RATE);
			strength.SetScale(SCALE);
			strength.SetColor({ 0,0,255,255 });
			strength.SetNameTag("MaiStrength");

			weakness.SetWidthAndHeith(WIDTH, HEIGHT * WEAKNESS_RATE);
			weakness.SetScale(SCALE);
			weakness.SetColor({ 0,255,0,255 });
			weakness.SetNameTag("MaiWeakness");

			auto adjustDown = GetVector2(Dir4::Down, ADJUST_COLLIDER_DOWN);
			auto adjustW = GetVector2(Dir4::Up, HEIGHT * SCALE * WEAKNESS_RATE / 2.f) + adjustDown;
			auto adjustS = GetVector2(Dir4::Down, HEIGHT * SCALE * STRENGTH_RATE / 2.f) + adjustDown;

			strength.SetPosition(std::move(pos + adjustS));
			weakness.SetPosition(std::move(pos + adjustW));

			strength.SetRotation(Gravity::GetRotation());
			weakness.SetRotation(Gravity::GetRotation());
		}
	}
}