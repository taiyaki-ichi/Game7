#include "GravityBox.hpp"
#include"Game/Stage/Gravity.hpp"
#include"Game/Stage/UtilityVectorFunction.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

#include<iostream>

namespace Game::Stage
{
	GravityBox::GravityBox(Scene* scene, std::vector<float>&& data)
		:ActorBase{scene}
		, mTexture{"../Assets/Box/001.png"}
		, mCollider{}
		, mRotationCnt{0}
	{
		auto pos = GameLib::Vector2{ data[0],data[1] };

		mTexture.SetScale(0.1f);
		mTexture.SetPosition(pos);

		mCollider.SetNameTag("Ground");
		mCollider.SetWidthAndHeith(76.f, 76.f);
		mCollider.SetPosition(pos);

		auto hitPlayer = [this](const GameLib::Collider& c) {
			auto adjust = GetParallelRectAdjustVec(mCollider, c);
			auto dir4VecAdjust = Gravity::GetDir4Vec(adjust);

			//std::cout << "a\n";
			
			/*
			if (dir4VecAdjust.mDir4 == Dir4::Down)
				std::cout << "down\n";
			if (dir4VecAdjust.mDir4 == Dir4::Up)
				std::cout << "up\n";
			if (dir4VecAdjust.mDir4 == Dir4::Right)
				std::cout << "right\n";
			if (dir4VecAdjust.mDir4 == Dir4::Left)
				std::cout << "left";

			if (Gravity::GetGravityDir4() == Dir4::Down)
				std::cout << "down\n";
			if (Gravity::GetGravityDir4() == Dir4::Up)
				std::cout << "up\n";
			if (Gravity::GetGravityDir4() == Dir4::Right)
				std::cout << "right\n";
			if (Gravity::GetGravityDir4() == Dir4::Left)
				std::cout << "left";
				*/
			if (dir4VecAdjust.mDir4 == Dir4::Up && mRotationCnt==0) {
				//std::cout << "b\n";
				auto gDir = Gravity::GetGravityDir4();
				int dir = static_cast<int>(gDir) + 1;
				if (dir > 3)
					dir -= 4;
				Gravity::SetGravityDir4(static_cast<Dir4>(dir));
				mRotationCnt++;
			}
		};

		mCollider.AddHitFunction("Player", std::move(hitPlayer));
	}
	void GravityBox::ActorUpdate()
	{

		if (mRotationCnt != 0) {
			float rot = GameLib::Viewport::GetRotation();
			if (mRotationCnt > 0)
				rot += DELTA_ROT;
			else
				rot -= DELTA_ROT;

			while (rot < 0.f)
				rot += GameLib::PI * 2.f;
			while (rot >= GameLib::PI * 2.f)
				rot -= GameLib::PI * 2.f;

			for (int i = 0; i < 4; i++) {
				if (std::abs(rot - GameLib::PI / 2.f * i) < DELTA_ROT / 2.f) {
					if (mRotationCnt > 0)
						mRotationCnt--;
					else
						mRotationCnt++;
					rot = GameLib::PI / 2.f * i;
				}
			}

			GameLib::Viewport::SetRotation(rot);
		}


	}
	void GravityBox::Active()
	{
		mTexture.SetIsAutoDrawing(true);
		mCollider.Active();
	}
	void GravityBox::Pause()
	{
		mTexture.SetIsAutoDrawing(false);
		mCollider.Pause();
	}
}
