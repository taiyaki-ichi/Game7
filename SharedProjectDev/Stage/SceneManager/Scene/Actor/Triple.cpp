#include"Triple.hpp"
#include"Triple/TripleFlag.hpp"
#include"Triple/TripleActive.hpp"

namespace Stage
{
	Triple::Triple(GameLib::Actor* actor)
		:ActorBase{actor}
		, mAnimation{}
		, mStateManager{}
	{

		mAnimation.AddAnimation({ "../Assets/Enemy/Triple/left001.png","../Assets/Enemy/Triple/left002.png" });
		mAnimation.AddAnimation({ "../Assets/Enemy/Triple/right001.png","../Assets/Enemy/Triple/right002.png" });
		mAnimation.AddAnimation({ "../Assets/Enemy/Triple/death-left.png" });
		mAnimation.AddAnimation({ "../Assets/Enemy/Triple/death-right.png" });
		mAnimation.SetScale(0.1f);
		mAnimation.SetDrawOrder(10);
		mAnimation.SetAnimationFPS(10);
	}

	void Triple::Update()
	{
		mAnimation.Update();
		mStateManager.Update();
		if (mStateManager.CheckFlag(TripleFlag::DEATH_MOTION_FINISH_FLAG))
			SetState(GameLib::Actor::State::Dead);
	}

	void Triple::BeginWorking()
	{
		mAnimation.SetIsAutoDrawing(true);
		mStateManager.BeginWorking();
	}

	void Triple::BeginToRest()
	{
		mAnimation.SetIsAutoDrawing(false);
		mStateManager.BeginToRest();
	}

	void Triple::LoadData(std::vector<float>&& data)
	{
		auto pos = GameLib::Vector2{ data[0],data[1] };
		mAnimation.SetPosition(std::move(pos));
		mStateManager.SetStartState(new TripleState::Active{ &mAnimation });
	}

}