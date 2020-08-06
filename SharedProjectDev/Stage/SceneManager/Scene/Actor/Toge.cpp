#include"Toge.hpp"
#include"Toge/TogeActive.hpp"

namespace Stage
{
	Toge::Toge(GameLib::Actor* scene)
		:ActorBase{scene}
		, mAnimation{}
		, mStateManager{}
	{
		mAnimation.AddAnimation({ "../Assets/Enemy/Toge/stay.png" });
		mAnimation.AddAnimation({ "../Assets/Enemy/Toge/fall.png" });
	}

	void Toge::Update()
	{
		mAnimation.Update();
		mStateManager.Update();
	}

	void Toge::BeginWorking()
	{
		mAnimation.SetIsAutoDrawing(true);
		mStateManager.BeginWorking();
	}

	void Toge::BeginToRest()
	{
		mAnimation.SetIsAutoDrawing(false);
		mStateManager.BeginToRest();
	}

	void Toge::LoadData(std::vector<float>&& data)
	{
		auto pos = GameLib::Vector2{ data[0],data[1] };
		mAnimation.SetPosition(pos);

		mStateManager.SetStartState(new TogeState::Active{ &mAnimation });

	}

	
}