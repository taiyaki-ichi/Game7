#include"GravityBox.hpp"
#include"Stage/Utilty/Geometry.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"Stage/Gravity/Gravity.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GravityBox/Apple.hpp"
#include"Player.hpp"

namespace Stage
{

	GravityBox::GravityBox(GameLib::Actor* scene)
		:ActorBase{ scene }
		, mCollider{}
		, mCollider2{ "Ground" }
		, mRotationCnt{ 0 }
		, mRotation{ 0.f }
		, mPosition{}
		, mTexture{"../Assets/Object/GravityBox/box4.png"}
		, mApple{nullptr}
	{

		mTexture.SetScale(0.1f);

		mCollider.SetNameTag("GravityBox");
		mCollider.SetWidthAndHeith(76.f, 76.f);

		mCollider2.SetWidthAndHeith(74.f, 74.f);

		auto hitPlayer = [this](const GameLib::Collider& c) {
			auto adjust = GetParallelRectAdjustVec(mCollider, c);
			auto dir4VecAdjust = GetDir4Vec(adjust);

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
			if (dir4VecAdjust.mDir4 == Dir4::Up /*&& std::fabs(dir4VecAdjust.mSize) > 0.5f*/ && mRotationCnt == 0) {
				//std::cout << "b\n";
				auto gDir = Gravity::GetDir4();

				////////////////////////////////////////////////////////////////////////////////////////
				//+2‚Æ‚©‚¶‚á‚È‚­–Ú“I‚ÌDir‚ÆŒ»Ý‚ÌDir‚ðl—¶‚³‚·
				//nextDir‚Æ‚©‚à‚½‚·‚©
				int dir = static_cast<int>(gDir) + 1;
				while (dir > 3)
					dir -= 4;
				while (dir < 0)
					dir += 4;
				Gravity::SetDir4(static_cast<Dir4>(dir));
				///////////////////////////////////////////////////////////////////////////////////////
				mRotationCnt += 1;

				mRotation = GameLib::Viewport::GetRotation();
				mPosition = GameLib::Viewport::GetPos();

				Gravity::StartRotation();

				mApple->GoCenter();
				mApple->Rotation();

				//Collder1‚ÆPlayer‚ª“–‚½‚Á‚½Žž“_‚ÅCollider2‚Æ‚Í”»’è‚ð‚³‚¹‚È‚¢
				mCollider2.SetNameTag("");
			}
		};

		mCollider.AddHitFunction("Player", std::move(hitPlayer));

		mApple = new Apple{ this };
		///////////////////////////////////////////////////////////////////////////////////////////////////
		mApple->Fall(Dir4::Right);
		mApple->SetDrawOrder(1);
	}
	void GravityBox::Update()
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
						Gravity::FinishRotation();
						
						int dir = static_cast<int>(Gravity::GetDir4());

						//////////////////////////////////////////////////////////////////////////////
						dir = (dir + 1 > 3) ? 0 : dir + 1;
						mApple->Fall(static_cast<Dir4>(dir));

						mCollider2.SetNameTag("Ground");
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
	void GravityBox::BeginWorking()
	{
		mCollider.Active();
		mCollider2.Active();
		mApple->BeginWorking();
	}
	void GravityBox::BeginToRest()
	{
		mCollider.Pause();
		mCollider2.Pause();
		mApple->BeginToRest();
	}
	void GravityBox::LoadData(std::vector<float>&& data)
	{
		auto pos = GameLib::Vector2{ data[0],data[1] };
		mTexture.SetPosition(pos);
		mApple->SetCenter(pos);
		mCollider.SetPosition(pos);
		mCollider2.SetPosition(std::move(pos));
	}

	bool GravityBox::UpdateOrNot()
	{
		return true;
	}

}