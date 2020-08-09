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

	void Toge::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		mAnimation.SetPosition(data[0]);
		//std::cout << "data[0] " << data[0].x << "," << data[0].y << "\n";
		mStateManager.SetStartState(new TogeState::Active{ &mAnimation });

	}

	
}