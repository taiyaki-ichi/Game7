#include"Frog.hpp"
#include"Frog/FrogParam.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"Stage/Gravity/Gravity.hpp"
#include"Frog/FrogActive.hpp"

namespace Stage
{
	Frog::Frog(GameLib::Actor* actor)
		:ActorBase{actor}
		, mAnim{}
		, mStateManager{}
	{
		mAnim.AddAnimation({ "../Assets/Enemy/Frog/stay.png" });
		mAnim.AddAnimation({ "../Assets/Enemy/Frog/jump.png" });
		mAnim.AddAnimation({ "../Assets/Enemy/Frog/fall_death.png" });
		mAnim.AddAnimation({ "../Assets/Enemy/Frog/flat.png" });

		mAnim.SetScale(FrogParam::SCALE);
		
	}

	void Frog::Update()
	{
		mAnim.Update();
		mStateManager.Update();
	}

	void Frog::BeginWorking()
	{
		mAnim.SetIsAutoDrawing(true);
		mStateManager.BeginWorking();
	}

	void Frog::BeginToRest()
	{
		mAnim.SetIsAutoDrawing(false);
		mStateManager.BeginToRest();
	}

	void Frog::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		mAnim.SetPosition(data[0]);

		float x = GameLib::GetDistanceY(data[0], data[1]);
		float jumpSpeed = std::sqrt(2.f * Gravity::GetDir4Vec().mSize * x);

		mStateManager.SetStartState(new FrogState::Active{ &mAnim,jumpSpeed });
	}

}
