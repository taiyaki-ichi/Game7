#include"Stand.hpp"
#include"Stand/StandParam.hpp"
#include"Stand/StandActive.hpp"
#include"GameLib/include/Math/Numbers.hpp"
#include"Stage/Utilty/IsInScope.hpp"
#include"Stage/Gravity/Gravity.hpp"
#include"Stage/WindowSize.hpp"
#include"Spore.hpp"
#include"Player.hpp"
#include"Stand/StandFlag.hpp"

namespace Stage
{
	Stand::Stand(GameLib::Actor* actor,Dir4&& dir)
		:ActorBase{actor}
		, mHeadAnim{}
		, mBodyAnim{}
		, mStageManager{}
	{
		using namespace StandParam;

		mHeadAnim.AddAnimation({ "../Assets/Enemy/Stand/head-active.png" });
		mHeadAnim.AddAnimation({ "../Assets/Enemy/Stand/head-beam.png" });
		mHeadAnim.AddAnimation({ "../Assets/Enemy/Stand/head-death.png" });

		mHeadAnim.SetScale(HEAD_SCALE);
		mHeadAnim.SetDrawOrder(1);

		mBodyAnim.AddAnimation({ "../Assets/Enemy/Stand/body-up.png" });
		mBodyAnim.AddAnimation({ "../Assets/Enemy/Stand/body-down.png" });

		mBodyAnim.SetScale(BODY_SCALE);

		if (dir == Dir4::Left)
			mBodyAnim.SetRotation(GameLib::PI / 2.f * 3.f);
		else if (dir == Dir4::Right)
			mBodyAnim.SetRotation(GameLib::PI / 2.f);
		else if (dir == Dir4::Up)
			mBodyAnim.SetRotation(GameLib::PI);
	}

	bool Stand::UpdateOrNot()
	{
		using namespace StandParam;
		return !Gravity::IsRotation() && IsInScope(mBodyAnim.GetPosition(), WindowSize::WIDTH + UPDATE_RANGE, WindowSize::WIDTH + UPDATE_RANGE);
	}

	void Stand::Update()
	{
		mBodyAnim.Update();
		mHeadAnim.Update();
		mStageManager.Update();
		if (mStageManager.CheckFlag(StandFlag::SPORE_FLAG))
		{
			auto vec = Player::GetPosition() - mHeadAnim.GetPosition();
			vec.Normalize();
			vec *= StandParam::SPORE_SPEED;
			new Spore{ mOwner,mHeadAnim.GetPosition(),vec };
			mStageManager.DownFlag(StandFlag::SPORE_FLAG);
		}
	}

	void Stand::BeginWorking()
	{
		mBodyAnim.SetIsAutoDrawing(true);
		mHeadAnim.SetIsAutoDrawing(true);
		mStageManager.BeginWorking();
	}

	void Stand::BeginToRest()
	{
		mBodyAnim.SetIsAutoDrawing(false);
		mHeadAnim.SetIsAutoDrawing(false);
		mStageManager.BeginToRest();
	}

	void Stand::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		mBodyAnim.SetPosition(data[0]);
		mStageManager.SetStartState(new StandState::Active{ &mHeadAnim,&mBodyAnim });
	}
}