#include"Toge.hpp"
#include"Utility/IsInScope.hpp"
#include"Game/Window.hpp"
#include"Game/Stage/UtilityVectorFunction.hpp"
#include"Game/Stage/Gravity.hpp"
#include"GameLib/include/Math/Numbers.hpp"

namespace Game::Stage::Toge
{

	Actor::Actor(Scene* scene, std::vector<float>&& data)
		:ActorBase{ scene }
		, mAnimation{}
		, mStateManager{}
	{
		mAnimation.AddAnimation({ "../Assets/Enemy/Toge/stay.png" });
		mAnimation.AddAnimation({ "../Assets/Enemy/Toge/fall.png" });

		mAnimation.SetScale(0.1f);

		auto pos = GameLib::Vector2{ data[0],data[1] };
	//	std::cout << "x: " << data[0] << ", y: " << data[1] << "\n";
		mStateManager.SetState(new Toge::TogeActive{ &mAnimation,std::move(pos) });
	}

	bool Actor::UpdateOrNot() {
		auto pos = mAnimation.GetPosition();
		return IsInScope(pos, WINDOW_WIDTH + 200.f, WINDOW_WIDTH + 200.f) && StageIsNotRotation();
	}

	void Actor::ActorUpdate() {
		mAnimation.Update();
		mStateManager.Update();

		if (mStateManager.GetFlag() == 4)
			SetState(GameLib::Actor::State::Dead);
	}

	void Actor::Active() {
		mAnimation.SetIsAutoDrawing(true);
		mStateManager.Active();
	}

	void Actor::Pause() {
		mAnimation.SetIsAutoDrawing(false);
		mStateManager.Pause();
	}

	TogeActive::TogeActive(GameLib::DrawAnimation* anim,GameLib::Vector2&& pos)
		:StateBase{}
		, mCollider{}
		, mAnim{ anim }
		, mPhsicsModel{}
		, mTimer{}
	{
		mCollider.SetNameTag("TogeBody");
		mCollider.SetWidthAndHeith(550.f, 550.f);
		mCollider.SetColor({ 0,0,255,255 });

		mPhsicsModel.mPosition = std::move(pos);
		mPhsicsModel.mScale = 0.1f;

		auto hitGround = [this](const GameLib::Collider& c) {
			auto adjust = GetParallelRectAdjustVec(mCollider, c);
			//std::cout << "adjust: " << adjust.x << "," << adjust.y << "\n";
			mPhsicsModel.mPosition += adjust;

			auto adjustDir4Vec = Gravity::GetDir4Vec(adjust);

			if (adjustDir4Vec.mDir4 == Dir4::Up)
				mPhsicsModel.mVelocity = GameLib::Vector2{};

			Adjust();
		};

		mCollider.AddHitFunction("Ground", std::move(hitGround));

		Adjust();

		//std::cout << "pos: " << mPhsicsModel.mPosition.x << "," << mPhsicsModel.mPosition.y << "\n";
	}

	StateBase* TogeActive::Update()
	{
		//std::cout << "pos: " << mPhsicsModel.mPosition.x << "," << mPhsicsModel.mPosition.y << "\n";

		mTimer += 0.01f;
		mPhsicsModel.mScale = 0.15f + 0.05f * std::sin(GameLib::PI / 3.f * mTimer);
		
		auto g = Gravity::GetGravityVector2();
		mPhsicsModel.Update(std::move(g));

		Adjust();
		
		return this;
	}

	void TogeActive::Active()
	{
		mCollider.Active();
	}

	void TogeActive::Pause()
	{
		mCollider.Pause();
	}

	void TogeActive::Adjust()
	{
		mAnim->Set(mPhsicsModel.mPosition, mPhsicsModel.mScale, mPhsicsModel.mRotation);
		mCollider.Set(mPhsicsModel.mPosition, mPhsicsModel.mScale, mPhsicsModel.mRotation);
	}



}