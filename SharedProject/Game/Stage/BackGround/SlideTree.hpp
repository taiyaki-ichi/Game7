#pragma once
#include"SlideObjectBase.hpp"

namespace Game::Stage::BackGround
{

	class SlideTree230 : public SlideObjectBase
	{
	public:
		SlideTree230(GameLib::Actor* actor, const GameLib::Vector2& pos);
		virtual ~SlideTree230() = default;

	};

	class SlideTree180 : public SlideObjectBase
	{
	public:
		SlideTree180(GameLib::Actor* actor, const GameLib::Vector2& pos);
		virtual ~SlideTree180() = default;

	};

	class SlideTree130 : public SlideObjectBase
	{
	public:
		SlideTree130(GameLib::Actor* actor, const GameLib::Vector2& pos);
		virtual ~SlideTree130() = default;

	};
}