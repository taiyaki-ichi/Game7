#include"GravityBox.hpp"
#include"Stage/Utilty/Geometry.hpp"
#include"Stage/Gravity/GravityFunc.hpp"
#include"Stage/Gravity/Gravity.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GravityBox/Apple.hpp"
#include"Player.hpp"
#include"GravityBox/GravityBoxParam.hpp"

namespace Stage
{

	GravityBox::GravityBox(GameLib::Actor* scene,int dirNum)
		:ActorBase{ scene }
		, mCollider{}
		, mCollider2{ "Ground" }
		, mRotationCnt{ 0 }
		, mRotation{ 0.f }
		, mPosition{}
		, mTexture{(dirNum==4)?"../Assets/Object/GravityBox/box4.png": "../Assets/Object/GravityBox/box2.png" }
		, mApple{nullptr}
		, mNextDir{Dir4::Left}
		, mDeltaRotDir{1}
		, mCoolDownCnt{0}
	{
		using namespace GravityBoxParam;

		mTexture.SetScale(SCALE);

		mCollider.SetNameTag("GravityBox");
		mCollider.SetWidthAndHeith(WIDTH, HEIGHT);
		mCollider.SetScale(SCALE);

		mCollider2.SetWidthAndHeith(WIDTH* SCALE - COLLIDER2_DELTA_LENGTH, HEIGHT* SCALE - COLLIDER2_DELTA_LENGTH);

		auto hitPlayer = [this](const GameLib::Collider& c) {
			auto adjust = GetParallelRectAdjustVec(mCollider, c);
			auto dir4VecAdjust = GetDir4Vec(adjust);

			if (dir4VecAdjust.mDir4 == Dir4::Up && mRotationCnt == 0&&mCoolDownCnt==0) {
				
				auto gDir = Gravity::GetDir4();

				mRotationCnt = static_cast<int>(mNextDir) - static_cast<int>(Gravity::GetDir4());

				while (mRotationCnt < -2)
					mRotationCnt += 4;
				while (mRotationCnt > 2)
					mRotationCnt -= 4;

				//std::cout << "mRotationCnt: " << mRotationCnt << "\n";

				Gravity::SetDir4(mNextDir);

				//これじゃダメ！
				int dir = static_cast<int>(mNextDir) + mDeltaRotDir;
				while (dir > 3)
					dir -= 4;
				while (dir < 0)
					dir += 4;
				mNextDir = static_cast<Dir4>(dir);

				//回転終了判定に引っかからないようにするため
				//最初は余分に足しておく
				float rot = GameLib::Viewport::GetRotation();
				if (mRotationCnt > 0)
					rot += GravityBoxParam::CAMERA_DELTA_ROT;
				else
					rot -= GravityBoxParam::CAMERA_DELTA_ROT;
				GameLib::Viewport::SetRotation(rot);

				mRotation = GameLib::Viewport::GetRotation();
				mPosition = GameLib::Viewport::GetPos();

				Gravity::StartRotation();

				mApple->GoCenter();
				mApple->Rotation();

				//Collder1とPlayerが当たった時点でCollider2とは判定をさせない
				mCollider2.SetNameTag("");
			}
		};

		mCollider.AddHitFunction("Player", std::move(hitPlayer));

		mApple = new Apple{ this };
		mApple->SetDrawOrder(1);

		
	}
	void GravityBox::Update()
	{
		if (mCoolDownCnt > 0)
			mCoolDownCnt--;


		if (mRotationCnt != 0) {
			float rot = GameLib::Viewport::GetRotation();
			//std::cout << "rot: " << rot << "\n";
			auto pos = GameLib::Viewport::GetPos();
			//std::cout << "pos: "<<pos.x << "," << pos.y << "\n";

			if (mRotationCnt > 0)
				rot += GravityBoxParam::CAMERA_DELTA_ROT;
			else
				rot -= GravityBoxParam::CAMERA_DELTA_ROT;

			while (rot < 0.f)
				rot += GameLib::PI * 2.f;
			while (rot >= GameLib::PI * 2.f)
				rot -= GameLib::PI * 2.f;

			for (int i = 0; i < 4; i++) {
				if (std::abs(rot - GameLib::PI / 2.f * i) <= GravityBoxParam::CAMERA_DELTA_ROT) {
					if (mRotationCnt > 0)
						mRotationCnt--;
					else
						mRotationCnt++;

					rot = GameLib::PI / 2.f * i;

					if (mRotationCnt == 0) {
						Gravity::FinishRotation();
						mApple->Fall(mNextDir);
						mCollider2.SetNameTag("Ground");

						mCoolDownCnt = COOLDOWN_TIME;;
					}

				}
			}

			GameLib::Viewport::SetPos(GameLib::Vector2::Rotation(mPosition, -rot + mRotation));
			GameLib::Viewport::SetRotation(rot);

		}

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
	void GravityBox::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		mTexture.SetPosition(data[0]);
		mApple->SetCenter(data[0]);
		mCollider.SetPosition(data[0]);
		mCollider2.SetPosition(std::move(data[0]));
	}

	bool GravityBox::UpdateOrNot()
	{
		return true;
	}

	void GravityBox::LoadStringData(std::vector<std::string>&& data)
	{

		std::string nextDirString{};
		//2方向の場合
		if (data.size() == 1)
		{
			if (data[0] == "right" || data[0] == "left")
				mTexture.SetRotation(GameLib::PI / 2.f);

			mDeltaRotDir = 2;
			nextDirString = data[0];
		}
		else if (data.size() == 2)
		{
			if (data[0] == "right") {
				mTexture.SetHorizontalFlip(true);
				mDeltaRotDir = -1;
			}

			nextDirString = data[1];
		}


		if (nextDirString == "right")
			mNextDir = Dir4::Right;
		else if (nextDirString == "left")
			mNextDir = Dir4::Left;
		else if (nextDirString == "up")
			mNextDir = Dir4::Up;
		else if (nextDirString == "down")
			mNextDir = Dir4::Down;

		mApple->Fall(mNextDir);
	}

}