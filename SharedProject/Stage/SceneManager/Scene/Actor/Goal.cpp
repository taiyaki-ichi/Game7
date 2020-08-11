#include"Goal.hpp"
#include"Goal/GoalParam.hpp"
#include"Stage/Utilty/Geometry.hpp"
#include"Stage/Utilty/Dir4Vec.hpp"
#include"Goal/Kira.hpp"

namespace Stage
{
	Goal::Goal(GameLib::Actor* actor)
		:ActorBase{actor}
		, mTexture{ "../Assets/Object/Goal/diamond.png" }
		, mCollider{"Goal"}
		, mFallDir{Dir4::Down}
		, mKiraCnt{0}
	{
		mCollider.SetWidthAndHeith(GoalParam::COLLIDER_WIDTH, GoalParam::COLLIDER_HEIGHT);
		mCollider.SetScale(GoalParam::SCALE);

		mCollider.SetColor({ 0,255,0,255 });

		mTexture.SetScale(GoalParam::SCALE);
		mTexture.SetDrawOrder(-1);

		auto hitGround = [this](const GameLib::Collider& c) {
			auto adjsut = GetParallelRectAdjustVec(mCollider, c);

			auto pos = mCollider.GetPosition();
			pos += adjsut;
			mCollider.SetPosition(pos);

			mTexture.SetPosition(pos - GetFallDirVec() * GoalParam::COLLIDER_ADJUST_DOWN_SIZE);
		};

		mCollider.AddHitFunction("Ground", std::move(hitGround));
	}

	void Goal::Update()
	{
		auto pos = mTexture.GetPosition();

		pos += GetFallDirVec() * GoalParam::GRAVITY;

		mTexture.SetPosition(pos);

		mCollider.SetPosition(pos + GetFallDirVec() * GoalParam::COLLIDER_ADJUST_DOWN_SIZE);

		mKiraCnt++;
		if (mKiraCnt >= GoalParam::GENARATE_KIRA_TIME) {
			new Kira{ this,pos };
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
	}

	void Goal::LoadStringData(std::vector<std::string>&& data)
	{
		mFallDir = StringToDir4(data[0]);

		float rot = 0.f;
		if (data[0] == "right")
			rot = GameLib::PI / 2.f;
		else if (data[0] == "up")
			rot = GameLib::PI;
		else if (data[0] == "left")
			rot = GameLib::PI * 3.f / 2.f;

		mTexture.SetRotation(rot);
		mCollider.SetRotation(rot);
	}

	GameLib::Vector2 Goal::GetFallDirVec()
	{
		GameLib::Vector2 vecDir{};
		if (mFallDir == Dir4::Right)
			vecDir = GameLib::Vector2{ 1.f,0.f };
		else if (mFallDir == Dir4::Left)
			vecDir = GameLib::Vector2{ -1.f,0.f };
		else if (mFallDir == Dir4::Up)
			vecDir = GameLib::Vector2{ 0.f,1.f };
		else
			vecDir = GameLib::Vector2{ 0.f,-1.f };

		return vecDir;
	}
}