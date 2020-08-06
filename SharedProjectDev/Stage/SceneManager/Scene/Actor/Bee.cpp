#include"Bee.hpp"
#include"Bee/BeeParam.hpp"
#include"Bee/BeeCircleActive.hpp"
#include"Bee/BeeStraightActive.hpp"

namespace Stage
{

	Bee::Bee(GameLib::Actor* scene)
		:ActorBase{scene}
		, mAnim{}
		, mStateManager{}
	{
		mAnim.AddAnimation({
			"../Assets/Enemy/Bee/active001.png",
			"../Assets/Enemy/Bee/active002.png",
			"../Assets/Enemy/Bee/active003.png",
			"../Assets/Enemy/Bee/active002.png"
			});
		mAnim.AddAnimation({ "../Assets/Enemy/Bee/fall.png" });
		mAnim.SetAnimationFPS(8);
		mAnim.SetScale(BeeParam::SCALE);



	}

	void Bee::Update()
	{
		mAnim.Update();
		mStateManager.Update();
	}

	void Bee::BeginWorking()
	{
		mAnim.SetIsAutoDrawing(true);
		mStateManager.BeginWorking();
	}

	void Bee::BeginToRest()
	{
		mAnim.SetIsAutoDrawing(false);
		mStateManager.BeginToRest();
	}

	void Bee::LoadData(std::vector<float>&& data)
	{
		//Straight
		if (data.size() == 4)
		{
			auto center = GameLib::Vector2{ data[0],data[1] } / 2.f + GameLib::Vector2{ data[2],data[3] } / 2.f;
			auto radiusVec = GameLib::Vector2{ data[0],data[1] } / 2.f - GameLib::Vector2{ data[2],data[3] } / 2.f;
			mStateManager.SetStartState(new BeeState::StraightActive{ &mAnim,std::move(center),std::move(radiusVec) });
		}
		//Circle
		else
		{
			auto center = GameLib::Vector2{ data[0],data[1] };
			auto radiusVec = GameLib::Vector2{ data[2],data[3] } - GameLib::Vector2{ data[0],data[1] };

			auto p1 = GameLib::Vector2{ data[0],data[1] };
			auto p2 = GameLib::Vector2{ data[2],data[3] };
			auto p3 = GameLib::Vector2{ data[4],data[5] };

			float dir = (GameLib::Vector2::Cross(p2 - p1, p3 - p2) > 0.f) ? 1.f : -1.f;

			mStateManager.SetStartState(new BeeState::CircleActive{ &mAnim, std::move(center),std::move(radiusVec),dir });
		}
	}
}