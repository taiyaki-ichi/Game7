#include"Dogu.hpp"
#include"Dogu/DoguStay.hpp"

namespace Stage
{
	Dogu::Dogu(GameLib::Actor* actor)
		:ActorBase{actor}
		, mAnim{}
		, mStateManager{}
	{
		mAnim.AddAnimation({ "../Assets/Enemy/Dogu/stay.png" });
		mAnim.AddAnimation({ "../Assets/Enemy/Dogu/active.png" });
		mAnim.AddAnimation({ "../Assets/Enemy/Dogu/curse.png" });
	}

	void Dogu::Update()
	{
		mAnim.Update();
		mStateManager.Update();
	}

	void Dogu::BeginWorking()
	{
		mStateManager.BeginWorking();
		mAnim.SetIsAutoDrawing(true);
	}

	void Dogu::BeginToRest()
	{
		mStateManager.BeginToRest();
		mAnim.SetIsAutoDrawing(false);
	}

	void Dogu::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		//std::cout << "daat[0]: " << data[0].x << "," << data[0].y << "\n";
		mAnim.SetPosition(data[0]);
		mStateManager.SetStartState(new DoguState::Stay{ &mAnim });
	}
	
}