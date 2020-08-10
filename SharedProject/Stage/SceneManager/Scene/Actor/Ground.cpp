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

		//std::cout << "w: " << mWidth << " h: " << mHeigth << "\n";
		if (mWidth <= 0.f || mHeigth <= 0.f)
			SetState(Actor::State::Dead);

	}

	void Ground::BeginWorking()
	{
		mCollider.Active();
		mDrawRect.SetIsAutoDrawing(true);
	}

	void Ground::BeginToRest()
	{
		mCollider.Pause();
		mDrawRect.SetIsAutoDrawing(false);
	}

	//Ä‹A—p
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

	void GroundGenerator::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{

		float left, right, bottom, top;

		if (data[0].x < data[1].x) {
			left = data[0].x;
			right = data[1].x;
		}
		else {
			left = data[1].x;
			right = data[0].x;
		}

		if (data[0].y < data[1].y) {
			bottom = data[0].y;
			top = data[1].y;
		}
		else {
			bottom = data[1].y;
			top = data[0].y;
		}

		CreateGround(mOwner, left, right, bottom, top);

		SetState(GameLib::Actor::State::Dead);
	}
}