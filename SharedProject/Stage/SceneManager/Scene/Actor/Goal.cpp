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
	}

	void Goal::LoadStringData(std::vector<std::string>&& data)
	{
		mFallDir = StringToDir4(data[0]);

		float rot = 0.f;
		if (data[0] == "right") {
			rot = GameLib::PI / 2.f;
			mFallDir = Dir4::Right;
		}
		else if (data[0] == "up") {
			rot = GameLib::PI;
			mFallDir = Dir4::Up;
		}
		else if (data[0] == "left") {
			rot = GameLib::PI * 3.f / 2.f;
			mFallDir = Dir4::Left;
		}
		else
			mFallDir = Dir4::Down;

		mTexture.SetRotation(rot);
		mCollider.SetRotation(rot);

		auto pos = mTexture.GetPosition();
		pos += GameLib::Vector2::Rotation(GameLib::Vector2{ 0.f,-GoalParam::COLLIDER_ADJUST_DOWN_SIZE }, rot);
		mCollider.SetPosition(pos);

	}
}