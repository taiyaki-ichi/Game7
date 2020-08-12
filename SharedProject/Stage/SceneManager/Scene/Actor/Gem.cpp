#include"Gem.hpp"
#include"Gem/GemParam.hpp"

namespace Stage
{
	Gem::Gem(GameLib::Actor* actor)
		:ActorBase{actor}
		, mAnim{}
		, mCollider{ "Diamond" }
	{
		mAnim.AddAnimation({ "../Assets/Item/Diamond/001.png","../Assets/Item/Diamond/002.png" ,"../Assets/Item/Diamond/004.png",
			"../Assets/Item/Diamond/003.png" });
		mAnim.SetScale(GemParam::SCALE);
		mAnim.SetAnimationFPS(10.f);

		auto hitPlayer = [this](const GameLib::Collider& c) {
			SetState(GameLib::Actor::State::Dead);
		};

		mCollider.AddHitFunction("Player", std::move(hitPlayer));
		mCollider.SetWidthAndHeith(GemParam::WIDTH, GemParam::HEIGHT);
		mCollider.SetScale(GemParam::SCALE);
		mCollider.SetColor({ 0,255,0,255 });
	}

	void Gem::Update()
	{
		mAnim.Update();
	}

	void Gem::BeginWorking()
	{
		mAnim.SetIsAutoDrawing(true);
		mCollider.Active();
	}

	void Gem::BeginToRest()
	{
		mAnim.SetIsAutoDrawing(false);
		mCollider.Pause();
	}

	void Gem::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		mAnim.SetPosition(data[0]);
		mCollider.SetPosition(std::move(data[0]));
	}

}