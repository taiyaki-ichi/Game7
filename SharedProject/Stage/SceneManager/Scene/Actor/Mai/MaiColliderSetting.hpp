#pragma once
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Stage/Utilty/Dir4Vec.hpp"
#include"MaiParam.hpp"

namespace Stage
{
	namespace MaiState
	{
		inline void ColliderSetting(GameLib::Collider& strength, GameLib::Collider& weakness, const GameLib::Vector2& pos,const Dir4& dir)
		{
			using namespace MaiParam;

			float rot = 0.f;
			if (dir == Dir4::Right)
				rot = GameLib::PI / 2.f;
			else if (dir == Dir4::Left)
				rot = GameLib::PI / 2.f * 3.f;
			else if (dir == Dir4::Up)
				rot = GameLib::PI;

			strength.SetWidthAndHeith(WIDTH, HEIGHT * STRENGTH_RATE);
			strength.SetScale(SCALE);
			strength.SetColor({ 0,0,255,255 });
			strength.SetNameTag("MaiStrength");

			weakness.SetWidthAndHeith(WIDTH, HEIGHT * WEAKNESS_RATE);
			weakness.SetScale(SCALE);
			weakness.SetColor({ 0,255,0,255 });
			weakness.SetNameTag("MaiWeakness");

			GameLib::Vector2 adjustW{ 0.f,HEIGHT * SCALE * WEAKNESS_RATE / 2.f };
			GameLib::Vector2 adjustS{ 0.f,-HEIGHT * SCALE * STRENGTH_RATE / 2.f };
			GameLib::Vector2 adjustDown{ 0.f,-ADJUST_COLLIDER_DOWN };
			adjustDown = GameLib::Vector2::Rotation(adjustDown, rot);

			strength.SetPosition(pos + GameLib::Vector2::Rotation(adjustS, rot) + adjustDown);
			weakness.SetPosition(pos + GameLib::Vector2::Rotation(adjustW, rot) + adjustDown);
		}
	}
}