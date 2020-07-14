#include "GravityBox.hpp"
#include"Game/Stage/Gravity.hpp"
#include"Game/Stage/UtilityVectorFunction.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

#include<iostream>
#include"GameLib/include/InputState/InputState.hpp"
#include"Game/Stage/Scene/Scene.hpp"
#include"Game/Stage/Stage.hpp"

namespace Game::Stage
{
	GravityBox::GravityBox(Scene* scene, std::vector<float>&& data)
		:ActorBase{scene}
		, mTexture{"../Assets/Box/001.png"}
		, mCollider{}
		, mCollider2{"Ground"}
		, mRotationCnt{0}
		, mRotation{0.f}
		, mPosition{}
	{
		auto pos = GameLib::Vector2{ data[0],data[1] };

		mTexture.SetScale(0.1f);
		mTexture.SetPosition(pos);

		mCollider.SetNameTag("");
		mCollider.SetWidthAndHeith(76.f, 76.f);
		mCollider.SetPosition(pos);

		mCollider2.SetWidthAndHeith(74.f, 74.f);
		mCollider2.SetPosition(pos);

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
				while (dir > 3)
					dir -= 4;
				while (dir < 0)
					dir += 4;
				Gravity::SetGravityDir4(static_cast<Dir4>(dir));
				mRotationCnt++;
		
				mRotation = GameLib::Viewport::GetRotation();
				mPosition = GameLib::Viewport::GetPos();

				GetScene()->GetStage()->PlayerPause();
				Gravity::StartRotation();

			}
		};

		mCollider.AddHitFunction("Player", std::move(hitPlayer));
	}
	void GravityBox::ActorUpdate()
	{

		if (mRotationCnt != 0) {
			float rot = GameLib::Viewport::GetRotation();
			//std::cout << "rot: " << rot << "\n";
			auto pos = GameLib::Viewport::GetPos();
			//std::cout << "pos: "<<pos.x << "," << pos.y << "\n";

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

					if (mRotationCnt == 0) {
						GetScene()->GetStage()->PlayerAcitve();
						Gravity::FnishRotarion();
					}
			
				}
			}

			GameLib::Viewport::SetPos(GameLib::Vector2::Rotation(mPosition, -rot + mRotation));

			GameLib::Viewport::SetRotation(rot);

			//auto pos = GameLib::AffineInv(mPos, GameLib::Viewport::GetPos(), -GameLib::Viewport::GetRotation(), GameLib::Viewport::GetScale());
			
			//GameLib::Viewport::SetPos(mVec - GameLib::Vector2::Rotation(mVec, rot - mRot));
		}
		/*
		float rot = GameLib::Viewport::GetRotation();
		rot += 0.01f;
		GameLib::Viewport::SetRotation(rot);
		*/
		

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
