#include"FallLeaf.hpp"

namespace Game::Stage::BackGround
{
	FallLeaf160::FallLeaf160(GameLib::Actor* owner, GameLib::Vector2&& pos, float rot)
		:FallObjectBase{ owner,"../Assets/BackGround/leaf-160.png",std::move(pos),rot,0.07f,GameLib::Vector2{-2.f,0.f},0.05f,0.2f ,-125}
	{
	}
	FallLeaf200::FallLeaf200(GameLib::Actor* owner, GameLib::Vector2&& pos, float rot)
		: FallObjectBase{ owner,"../Assets/BackGround/leaf-200.png",std::move(pos),rot,0.05f,GameLib::Vector2{-1.f,0.f},0.05f,0.1f ,-175}
	{
	}
}