#include"Carrot.hpp"
#include"Carrot/CarrotParam.hpp"
#include"Carrot/CarrotStay.hpp"
#include"Carrot/CarrotFlag.hpp"

namespace Stage
{
	Carrot::Carrot(GameLib::Actor* actor)
		:ActorBase{ actor }
		, mStateManager{}
		, mAnim{}
	{
		mAnim.AddAnimation({ "../Assets/Enemy/Carrot/stay.png" });
		mAnim.AddAnimation({ "../Assets/Enemy/Carrot/run001.png" ,"../Assets/Enemy/Carrot/run002.png" });
		mAnim.AddAnimation({ "../Assets/Enemy/Carrot/flat.png" });

		mAnim.SetScale(CarrotParam::SCALE);
		mAnim.SetAnimationFPS(10);
	}

	void Carrot::Update()
	{
		mAnim.Update();
		mStateManager.Update();
		if (mStateManager.CheckFlag(CarrotFlag::DEATH_MOTION_FNISH_FLAG))
			SetState(GameLib::Actor::State::Dead);
	}

	void Carrot::BeginWorking()
	{
		mStateManager.BeginWorking();
		mAnim.SetIsAutoDrawing(true);
	}

	void Carrot::BeginToRest()
	{
		mStateManager.BeginToRest();
		mAnim.SetIsAutoDrawing(false);
	}

	void Carrot::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		mAnim.SetPosition(std::move(data[0]));
		mStateManager.SetStartState(new CarrotState::Stay{ &mAnim });
	}
}