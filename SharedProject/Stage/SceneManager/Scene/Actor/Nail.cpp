#include"Nail.hpp"
#include"Nail/NailParam.hpp"
#include"Nail/NailActive.hpp"
#include"Nail/NailFlag.hpp"

namespace Stage
{
	Nail::Nail(GameLib::Actor* actor,Dir4&& dir,const GameLib::Vector2& pos)
		:ActorBase{actor}
		, mAnim{}
		, mStateManager{}
	{
		mAnim.SetScale(NailParam::SCALE);
		mAnim.AddAnimation({ "../Assets/Enemy/Nail/001.png" });
		//mAnim.SetDrawOrder(-1);
		mAnim.SetPosition(pos);

		mStateManager.SetStartState(new NailState::Active{ &mAnim,std::move(dir) });
	}

	void Nail::Update()
	{
		mAnim.Update();
		mStateManager.Update();

		if (mStateManager.CheckFlag(NailFlag::DEATH_FLAG))
			SetState(GameLib::Actor::State::Dead);
	}

	void Nail::BeginWorking()
	{
		mAnim.SetIsAutoDrawing(true);
		mStateManager.BeginWorking();
	}

	void Nail::BeginToRest()
	{
		mAnim.SetIsAutoDrawing(false);
		mStateManager.BeginToRest();
	}

}