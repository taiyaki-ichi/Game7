#include"IceGroundCollider.hpp"

namespace Stage
{
	IceGroundCollider::IceGroundCollider(GameLib::Actor* actor,const GameLib::Vector2& pos,float w,float h)
		:GameLib::Actor{ actor }
		, mCollider{ "IceGround" }
	{
		mCollider.SetPosition(pos);
		mCollider.SetWidthAndHeith(w, h);
		mCollider.SetColor({ 0, 255, 0, 255 });
	}

	void IceGroundCollider::BeginWorking()
	{
		mCollider.Active();
	}

	void IceGroundCollider::BeginToRest()
	{
		mCollider.Pause();
	}

}