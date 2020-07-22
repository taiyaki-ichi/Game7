#pragma once
#include"SlideObjectBase.hpp"

namespace Game::Stage::BackGround
{

	class SlideSharpTree230 : public SlideObjectBase
	{
	public:
		SlideSharpTree230(GameLib::Actor* actor, GameLib::Vector2&& pos);
		virtual ~SlideSharpTree230() = default;

	};

	class SlideSharpTree180 : public SlideObjectBase
	{
	public:
		SlideSharpTree180(GameLib::Actor* actor, GameLib::Vector2&& pos);
		virtual ~SlideSharpTree180() = default;

	};

	class SlideSharpTree130 : public SlideObjectBase
	{
	public:
		SlideSharpTree130(GameLib::Actor* actor, GameLib::Vector2&& pos);
		virtual ~SlideSharpTree130() = default;

	};

	class SlideRoundTree230 : public SlideObjectBase
	{
	public:
		SlideRoundTree230(GameLib::Actor* actor, GameLib::Vector2&& pos);
		virtual ~SlideRoundTree230() = default;
	};

	class SlideRoundTree180 : public SlideObjectBase
	{
	public:
		SlideRoundTree180(GameLib::Actor* actor, GameLib::Vector2&& pos);
		virtual ~SlideRoundTree180() = default;
	};

	class SlideRoundTree130 : public SlideObjectBase
	{
	public:
		SlideRoundTree130(GameLib::Actor* actor, GameLib::Vector2&& pos);
		virtual ~SlideRoundTree130() = default;
	};



}