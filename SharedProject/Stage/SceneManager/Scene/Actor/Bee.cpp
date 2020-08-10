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

	void Bee::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		//Straight
		if (data.size() == 2)
		{
			auto center = data[0] / 2.f + data[1] / 2.f;
			auto radiusVec = data[0] / 2.f - data[1] / 2.f;
			mStateManager.SetStartState(new BeeState::StraightActive{ &mAnim,std::move(center),std::move(radiusVec) });
		}
		//Circle
		else
		{
			auto center = data[0];
			auto radiusVec = data[1] - data[0];

			float dir = (GameLib::Vector2::Cross(data[1] - data[0], data[2] - data[1]) > 0.f) ? 1.f : -1.f;

			mStateManager.SetStartState(new BeeState::CircleActive{ &mAnim, std::move(center),std::move(radiusVec),dir });
		}
	}
}