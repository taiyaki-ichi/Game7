#include"Mai.hpp"
#include"Mai/MaiParam.hpp"
#include"GameLib/include/Math/Numbers.hpp"
#include"Mai/MaiStay.hpp"

namespace Stage
{
	Mai::Mai(GameLib::Actor* actor,Dir4&& dir)
		:ActorBase{actor}
		, mAnim{}
		, mStateManager{}
		,mGroundDir{std::move(dir)}
	{

		mAnim.AddAnimation({
			"../Assets/Enemy/Mai/stay001.png",
			"../Assets/Enemy/Mai/stay002.png",
			"../Assets/Enemy/Mai/stay003.png",
			"../Assets/Enemy/Mai/stay004.png",
			"../Assets/Enemy/Mai/stay005.png",
			"../Assets/Enemy/Mai/stay006.png",
			});
		mAnim.AddAnimation({ "../Assets/Enemy/Mai/launch.png" });
		mAnim.AddAnimation({ "../Assets/Enemy/Mai/death.png" });
		mAnim.AddAnimation({ "../Assets/Enemy/Mai/flat.png" });

		mAnim.SetScale(MaiParam::SCALE);
		mAnim.SetAnimationFPS(10);

		if (mGroundDir == Dir4::Right)
			mAnim.SetRotation(GameLib::PI / 2.f);
		else if (mGroundDir == Dir4::Left)
			mAnim.SetRotation(GameLib::PI * 3.f / 2.f);
		else if (mGroundDir == Dir4::Up)
			mAnim.SetRotation(GameLib::PI);


	}

	void Mai::Update()
	{
		mAnim.Update();
		mStateManager.Update();
	}

	void Mai::BeginWorking()
	{
		mAnim.SetIsAutoDrawing(true);
		mStateManager.BeginWorking();
	}

	void Mai::BeginToRest()
	{
		mAnim.SetIsAutoDrawing(false);
		mStateManager.BeginToRest();
	}

	void Mai::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		mAnim.SetPosition(data[0]);
		mStateManager.SetStartState(new MaiState::Stay{ &mAnim,mGroundDir });
	}
}