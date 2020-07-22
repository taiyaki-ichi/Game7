#pragma once
#include"SlideObjectBase.hpp"

namespace Game::Stage::BackGround
{
	class SlideTotemPole130 : public SlideObjectBase
	{
	public:
		SlideTotemPole130(GameLib::Actor* actor, GameLib::Vector2&& pos);
		virtual ~SlideTotemPole130() = default;
	};

	class SlideTotemPole180 : public SlideObjectBase
	{
	public:
		SlideTotemPole180(GameLib::Actor* actor, GameLib::Vector2&& pos);
		virtual ~SlideTotemPole180() = default;
	};

	class SlideTotemPole230 : public SlideObjectBase
	{
	public:
		SlideTotemPole230(GameLib::Actor* actor, GameLib::Vector2&& pos);
		virtual ~SlideTotemPole230() = default;
	};
}