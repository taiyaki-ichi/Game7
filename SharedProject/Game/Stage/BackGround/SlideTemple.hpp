#pragma once
#include"SlideObjectBase.hpp"

namespace Game::Stage::BackGround
{
	class SlideTemple230 : public SlideObjectBase
	{
	public:
		SlideTemple230(GameLib::Actor* actor, GameLib::Vector2&& pos);
		virtual ~SlideTemple230() = default;

	};

	class SlideTemple180 : public SlideObjectBase
	{
	public:
		SlideTemple180(GameLib::Actor* actor, GameLib::Vector2&& pos);
		virtual ~SlideTemple180() = default;

	};

	class SlideTemple130 : public SlideObjectBase
	{
	public:
		SlideTemple130(GameLib::Actor* actor, GameLib::Vector2&& pos);
		virtual ~SlideTemple130() = default;

	};
}