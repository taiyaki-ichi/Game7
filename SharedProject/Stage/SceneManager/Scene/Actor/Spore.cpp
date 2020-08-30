#include"Spore.hpp"
#include"Spore/SporeParam.hpp"
#include"Stage/Utilty/IsInScope.hpp"
#include"Stage/WindowSize.hpp"

namespace Stage
{
	Spore::Spore(GameLib::Actor* actor,const GameLib::Vector2& pos, const GameLib::Vector2& v)
		:ActorBase{actor}
		, mVelocity{v}
		, mTexure{ "../Assets/Enemy/Spore/001.png" }
		, mCollider{ "Spore" }
	{
		using namespace SporeParam;

		mTexure.SetScale(SCALE);
		mTexure.SetPosition(pos);

		mCollider.SetScale(SCALE);
		mCollider.SetWidthAndHeith(WIDTH, HEIGHT);
		mCollider.SetColor({ 0,0,255,255 });
		mCollider.SetPosition(pos);
	}

	void Spore::Update()
	{
		auto pos = mTexure.GetPosition();
		pos += mVelocity;

		if (!IsInScope(pos, WindowSize::WIDTH + SporeParam::ACTIVE_RANGE, WindowSize::WIDTH + SporeParam::ACTIVE_RANGE))
			SetState(GameLib::Actor::State::Dead);

		mTexure.SetPosition(pos);
		mCollider.SetPosition(pos);
	}

	void Spore::BeginWorking()
	{
		mTexure.SetIsAutoDrawing(true);
		mCollider.Active();
	}

	void Spore::BeginToRest()
	{
		mTexure.SetIsAutoDrawing(false);
		mCollider.Pause();

		SetState(GameLib::Actor::State::Dead);
	}
}