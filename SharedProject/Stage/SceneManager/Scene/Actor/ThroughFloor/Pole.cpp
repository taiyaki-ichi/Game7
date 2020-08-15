#include"Pole.hpp"
#include"PoleParam.hpp"

namespace Stage
{
	Pole::Pole(GameLib::Actor* actor, GameLib::Vector2&& pos)
		:GameLib::Actor{ actor }
		, mCircle{}
	{
		mCircle.SetPosition(std::move(pos));
		mCircle.SetRadius(PoleParam::RADIUSE);
		mCircle.SetColor({ 50,50,50,255 });
	}

	void Pole::BeginWorking()
	{
		mCircle.SetIsAutoDrawing(true);
	}

	void Pole::BeginToRest()
	{
		mCircle.SetIsAutoDrawing(false);
	}
}