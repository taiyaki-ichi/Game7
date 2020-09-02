#include"Goal.hpp"
#include"Goal/GoalParam.hpp"
#include"Stage/Utilty/Geometry.hpp"
#include"Stage/Utilty/Dir4Vec.hpp"
#include"Goal/Kira.hpp"
#include"Goal/GoalText.hpp"
#include"Stage/Gravity/Gravity.hpp"

namespace Stage
{
	Goal::Goal(GameLib::Actor* actor,Dir4&& dir)
		:ActorBase{actor}
		, mTexture{ "../Assets/Object/Goal/diamond.png" }
		, mCollider{Dir4ToString(dir)+"Goal"}
		, mFallDir{std::move(dir)}
		, mKiraCnt{0}
		, mGoalTextFlag{true}
	{
		mCollider.SetWidthAndHeith(GoalParam::COLLIDER_WIDTH, GoalParam::COLLIDER_HEIGHT);
		mCollider.SetScale(GoalParam::SCALE);

		mCollider.SetColor({ 0,255,0,255 });

		mTexture.SetScale(GoalParam::SCALE);
		mTexture.SetDrawOrder(-1);

		float rot = 0.f;
		if (mFallDir == Dir4::Right) 
			rot = GameLib::PI / 2.f;
		else if (mFallDir == Dir4::Up) 
			rot = GameLib::PI;
		else if (mFallDir == Dir4::Left) 
			rot = GameLib::PI * 3.f / 2.f;

		mTexture.SetRotation(rot);
		mCollider.SetRotation(rot);

		auto hitPlayer = [this](const GameLib::Collider& c) {

			if (mGoalTextFlag&&mFallDir==Gravity::GetDir4()) {
				new GoalText{ this };
				mGoalTextFlag = false;
			}
		};

		mCollider.AddHitFunction("Player", std::move(hitPlayer));

	}

	void Goal::Update()
	{
		mKiraCnt++;
		if (mKiraCnt >= GoalParam::GENARATE_KIRA_TIME) {
			new Kira{ this,mTexture.GetPosition() };
			mKiraCnt = 0;
		}
	}

	void Goal::BeginWorking()
	{
		mTexture.SetIsAutoDrawing(true);
		mCollider.Active();
	}

	void Goal::BeginToRest()
	{
		mTexture.SetIsAutoDrawing(false);
		mCollider.Pause();
	}

	void Goal::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		mTexture.SetPosition(data[0]);
		float rot = mTexture.GetRotation();
		auto adjust = GameLib::Vector2::Rotation(GameLib::Vector2{ 0.f,-GoalParam::COLLIDER_ADJUST_DOWN_SIZE }, rot);
		mCollider.SetPosition(data[0] + adjust);
	}

}