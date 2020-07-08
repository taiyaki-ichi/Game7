#include"Ground.hpp"

namespace Game::Stage
{
	Ground::Ground(Scene* scene, GameLib::Vector2&& pos, float width, float height)
		:ActorBase{scene}
		, mPosition{std::move(pos)}
		, mWidth{width}
		, mHeigth{height}
		, mCollider{"Ground"}
		, mDrawRect{}
	{
		mCollider.Set(mPosition, mWidth, mHeigth, 1.f, 0.f);

		mDrawRect.Set(mPosition, 1.f, 0.f);
		mDrawRect.SetWidthAndHeight(mWidth, mHeigth);
		mDrawRect.SetColor({ 50,50,50,255 });
	}
}