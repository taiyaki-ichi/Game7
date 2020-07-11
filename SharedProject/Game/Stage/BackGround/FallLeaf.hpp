#pragma once
#include"FallObjectBase.hpp"

namespace Game::Stage::BackGround
{
	class FallLeaf160 : public FallObjectBase
	{
	public:
		FallLeaf160(GameLib::Actor* owner, GameLib::Vector2&& pos, float rot);
		virtual ~FallLeaf160() = default;

	};

	class FallLeaf200 : public FallObjectBase
	{
	public:
		FallLeaf200(GameLib::Actor* owner, GameLib::Vector2&& pos, float rot);
		virtual ~FallLeaf200() = default;
	};
}