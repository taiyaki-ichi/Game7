#include"Lift.hpp"
#include"Stage/Gravity/Gravity.hpp"
#include"LiftParam.hpp"
#include"Stage/Gravity/Gravity.hpp"

namespace Stage
{
	Lift::Lift(GameLib::Actor* actor)
		:GameLib::Actor{actor}
		, mCollider{ "ThroughFloor" }
		, mTexture{ "../Assets/Object/Lift/001.png" }
	{
		mCollider.SetWidthAndHeith(LiftParam::WIDTH, LiftParam::HEIGHT);
		mCollider.SetScale(LiftParam::SCLAE);
		mCollider.SetColor({ 255, 255, 0, 255 });

		mTexture.SetScale(LiftParam::SCLAE);
	}

	void Lift::CustomizeUpdate()
	{
		mCollider.SetRotation(Gravity::GetRotation());
		mTexture.SetRotation(Gravity::GetRotation());
	}

	void Lift::SetPosition(const GameLib::Vector2& pos)
	{
		mCollider.SetPosition(pos);
		mTexture.SetPosition(pos);
	}

	const GameLib::Vector2& Lift::GetPosition() const
	{
		return mCollider.GetPosition();
	}

	void Lift::BeginWorking()
	{
		mCollider.Active();
		mTexture.SetIsAutoDrawing(true);
	}

	void Lift::BeginToRest()
	{
		mCollider.Pause();
		mTexture.SetIsAutoDrawing(false);
	}

}