#include"Blinder.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"Player.hpp"

namespace Stage
{
	Blinder::Blinder(GameLib::Actor* actor)
		:ActorBase{ actor }
		, mRect{}
	{

	}

	void Blinder::Update()
	{
		mRect.SetPlayerPos(Player::GetPosition());
	}

	void Blinder::BeginWorking()
	{
		mRect.SetIsAutoDrawing(true);
	}

	void Blinder::BeginToRest()
	{
		mRect.SetIsAutoDrawing(false);
	}

	void Blinder::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		auto c = GameLib::GetCenter(data[0], data[1]);
		float w = GameLib::GetDistanceX(data[0], data[1]);
		float h = GameLib::GetDistanceY(data[0], data[1]);

		mRect.SetRect(c, w, h);
	}


}