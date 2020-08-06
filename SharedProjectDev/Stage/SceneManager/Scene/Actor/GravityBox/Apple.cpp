#include"Apple.hpp"

namespace Stage
{

	Apple::Apple(GameLib::Actor* actor)
		:GameLib::Actor{ actor }
		, mTexture{"../Assets/Object/GravityBox/apple.png"}
		, mCenter{}
		, mVelocity{}
		, mIsRotation{false}
	{
		mTexture.SetScale(0.09f);
	}

	void Apple::CustomizeUpdate()
	{
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

		
		//pos‚ªCenter‚ð’´‚¦‚Ä‚µ‚Ü‚í‚È‚¢‚æ‚¤‚É
		if ((pos - mCenter).Length() < MOVE_SPEED)
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