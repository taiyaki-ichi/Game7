#include"Apple.hpp"
#include"GravityBoxParam.hpp"

namespace Stage
{

	Apple::Apple(GameLib::Actor* actor)
		:GameLib::Actor{ actor }
		, mTexture{"../Assets/Object/GravityBox/apple.png"}
		, mCenter{}
		, mVelocity{}
		, mIsRotation{false}
	{
		mTexture.SetScale(GravityBoxParam::AppleParam::SCALE);
	}

	void Apple::CustomizeUpdate()
	{
		using namespace GravityBoxParam::AppleParam;

		if (mIsRotation)
		{
			float rot = mTexture.GetRotation();
			rot += ROTATION_SPEED;
			mTexture.SetRotation(rot);
		}

		auto pos = mTexture.GetPosition();
		pos += mVelocity;

		
		if ((mCenter - pos).Length() > MOVE_LENGTH) {
			mVelocity.Normalize();
			pos = mCenter + mVelocity * MOVE_LENGTH;
			mVelocity = GameLib::Vector2{ 0.f,0.f };
		}

		
		//posがCenterを超えてしまわないように
		if ((pos - mCenter).Length() <= MOVE_SPEED/2.f)
		{
			pos = mCenter;
			mVelocity = GameLib::Vector2{ 0.f,0.f };
		}

		mTexture.SetPosition(pos);


	}

	void Apple::SetCenter(const GameLib::Vector2& pos)
	{
		mCenter = pos;
		mTexture.SetPosition(pos);
	}

	void Apple::Fall(const Dir4& dir)
	{
		using namespace GravityBoxParam::AppleParam;

		if (dir == Dir4::Up)
			mVelocity = GameLib::Vector2{ 0.f,MOVE_SPEED };
		else if (dir == Dir4::Down)
			mVelocity = GameLib::Vector2{ 0.f,-MOVE_SPEED };
		else if (dir == Dir4::Right)
			mVelocity = GameLib::Vector2{ MOVE_SPEED,0.f };
		else
			mVelocity = GameLib::Vector2{ -MOVE_SPEED,0.f };

		mIsRotation = false;
	}

	void Apple::GoCenter()
	{
		using namespace GravityBoxParam::AppleParam;

		auto dirVec = mCenter - mTexture.GetPosition();
		dirVec.Normalize();
		mVelocity = dirVec * MOVE_SPEED;

		mIsRotation = false;
	}

	void Apple::Rotation()
	{
		mIsRotation = true;
	}

	void Apple::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
	}
	void Apple::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
	}

	void Apple::SetDrawOrder(int o)
	{
		mTexture.SetDrawOrder(o);
	}
}