#include"Ground.hpp"

namespace Game::Stage
{
	Ground::Ground(Scene* scene, float left, float right, float bottom, float top)
		:ActorBase{scene}
		, mPosition{(right+left)/2.f,(top+bottom)/2.f}
		, mWidth{right-left}
		, mHeigth{top-bottom}
		, mCollider{"Ground"}
		, mDrawRect{}
	{

		mCollider.Set(mPosition, mWidth, mHeigth, 1.f, 0.f);
		mCollider.SetColor({ 0,0,0,255 });

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

	//çƒãAóp
	void CreateGroundSub(Scene* scene, float left, float right, float bottom, float top)
	{
		//std::cout << "left: " << left << "   right: " << right << "   bottom: " << bottom << "   top: " << top << "\n";
		if (right - left > Ground::MAX_SIZE && top - bottom > Ground::MAX_SIZE)
		{
			float centerX = (right + left) / 2.f;
			float centerY = (top + bottom) / 2.f;

			CreateGroundSub(scene, left, centerX, bottom, centerY);
			CreateGroundSub(scene, centerX, right, bottom, centerY);
			CreateGroundSub(scene, left, centerX, centerY, top);
			CreateGroundSub(scene, centerX, right, centerY, top);
		}
		else if (right - left > Ground::MAX_SIZE) 
		{
			float centerX = (right + left) / 2.f;

			CreateGroundSub(scene, left, centerX, bottom, top);
			CreateGroundSub(scene, centerX, right, bottom, top);
		}
		else if (top - bottom > Ground::MAX_SIZE)
		{
			float centerY = (top + bottom) / 2.f;

			CreateGroundSub(scene, left, right, bottom, centerY);
			CreateGroundSub(scene, left, right, centerY, top);
		}
		else
		{
			new Ground{ scene,left,right,bottom,top };
		}
		

	}

	void CreateGround(Scene* scene, std::vector<float> data)
	{
		float left, right, bottom, top;

		if (data[0] < data[2]) {
			left = data[0];
			right = data[2];
		}
		else {
			left = data[2];
			right = data[0];
		}

		if (data[1] < data[3]) {
			bottom = data[1];
			top = data[3];
		}
		else {
			bottom = data[3];
			top = data[1];
		}

		CreateGroundSub(scene, left, right, bottom, top);
	}
}