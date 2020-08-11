#include"Diamond.hpp"
#include"Diamond/DiamondParam.hpp"

namespace Stage
{
	Diamond::Diamond(GameLib::Actor* actor)
		:ActorBase{actor}
		, mAnim{}
		, mCollider{ "Diamond" }
	{
		mAnim.AddAnimation({ "../Assets/Item/Diamond/001.png","../Assets/Item/Diamond/002.png" ,"../Assets/Item/Diamond/004.png",
			"../Assets/Item/Diamond/003.png" });
		mAnim.SetScale(DiamondParam::SCALE);
		mAnim.SetAnimationFPS(10.f);

		auto hitPlayer = [this](const GameLib::Collider& c) {
			SetState(GameLib::Actor::State::Dead);
		};

		mCollider.AddHitFunction("Player", std::move(hitPlayer));
		mCollider.SetWidthAndHeith(DiamondParam::WIDTH, DiamondParam::HEIGHT);
		mCollider.SetScale(DiamondParam::SCALE);
		mCollider.SetColor({ 0,255,0,255 });
	}

	void Diamond::Update()
	{
		mAnim.Update();
	}

	void Diamond::BeginWorking()
	{
		mAnim.SetIsAutoDrawing(true);
		mCollider.Active();
	}

	void Diamond::BeginToRest()
	{
		mAnim.SetIsAutoDrawing(false);
		mCollider.Pause();
	}

	void Diamond::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		mAnim.SetPosition(data[0]);
		mCollider.SetPosition(std::move(data[0]));
	}

}