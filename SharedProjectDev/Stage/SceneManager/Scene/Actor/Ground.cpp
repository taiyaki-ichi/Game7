#include"Ground.hpp"

#include<iostream>

namespace Stage
{
	Ground::Ground(GameLib::Actor* scene, float left, float right, float bottom, float top)
		:ActorBase{ scene }
		, mPosition{ (right + left) / 2.f,(top + bottom) / 2.f }
		, mWidth{ right - left }
		, mHeigth{ top - bottom }
		, mCollider{ "Ground" }
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
	void CreateGround(GameLib::Actor* scene, float left, float right, float bottom, float top)
	{
		//std::cout << "left: " << left << "   right: " << right << "   bottom: " << bottom << "   top: " << top << "\n";
		if (right - left > Ground::MAX_SIZE && top - bottom > Ground::MAX_SIZE)
		{
			float centerX = (right + left) / 2.f;
			float centerY = (top + bottom) / 2.f;

			CreateGround(scene, left, centerX, bottom, centerY);
			CreateGround(scene, centerX, right, bottom, centerY);
			CreateGround(scene, left, centerX, centerY, top);
			CreateGround(scene, centerX, right, centerY, top);
		}
		else if (right - left > Ground::MAX_SIZE)
		{
			float centerX = (right + left) / 2.f;

			CreateGround(scene, left, centerX, bottom, top);
			CreateGround(scene, centerX, right, bottom, top);
		}
		else if (top - bottom > Ground::MAX_SIZE)
		{
			float centerY = (top + bottom) / 2.f;

			CreateGround(scene, left, right, bottom, centerY);
			CreateGround(scene, left, right, centerY, top);
		}
		else
		{
			new Ground{ scene,left,right,bottom,top };
		}


	}

	GroundGenerator::GroundGenerator(GameLib::Actor* scene)
		:ActorBase{ scene }
	{
	}

	void GroundGenerator::LoadData(std::vector<float>&& floatData)
	{

		float left, right, bottom, top;

		if (floatData[0] < floatData[2]) {
			left = floatData[0];
			right = floatData[2];
		}
		else {
			left = floatData[2];
			right = floatData[0];
		}

		if (floatData[1] < floatData[3]) {
			bottom = floatData[1];
			top = floatData[3];
		}
		else {
			bottom = floatData[3];
			top = floatData[1];
		}

		CreateGround(mOwner, left, right, bottom, top);

		SetState(GameLib::Actor::State::Dead);
	}
}