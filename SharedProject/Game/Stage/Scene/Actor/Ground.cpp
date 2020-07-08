#include"Ground.hpp"

namespace Game::Stage
{
	Ground::Ground(Scene* scene,std::vector<float>&& initData)
		:ActorBase{scene}
		, mPosition{}
		, mWidth{}
		, mHeigth{}
		, mCollider{"Ground"}
		, mDrawRect{}
	{

		float centerX = (initData[0] + initData[2]) / 2.f;
		float centerY = (initData[1] + initData[3]) / 2.f;
		mPosition = GameLib::Vector2{ centerX,centerY };

		mWidth = std::abs(initData[0] - initData[2]);
		mHeigth = std::abs(initData[1] - initData[3]);

		mCollider.Set(mPosition, mWidth, mHeigth, 1.f, 0.f);

		mDrawRect.Set(mPosition, 1.f, 0.f);
		mDrawRect.SetWidthAndHeight(mWidth, mHeigth);
		mDrawRect.SetColor({ 50,50,50,255 });
	}

	void Ground::Active()
	{
		mCollider.Active();
		mDrawRect.SetIsAutoDrawing(true);
	}

	void Ground::Pause()
	{
		mCollider.Pause();
		mDrawRect.SetIsAutoDrawing(false);
	}
}