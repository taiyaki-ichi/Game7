#include"ThroughFloor.hpp"
#include"ThroughFloor/Pole.hpp"
#include"ThroughFloor/PoleParam.hpp"
#include"GameLib/include/Math/Vector2.hpp"

namespace Stage
{

	ThroughFloor::ThroughFloor(GameLib::Actor* actor)
		:ActorBase{actor}
		, mPole{}
		, mCollider{ "ThroughFloor" }
	{
	}

	void ThroughFloor::BeginWorking()
	{
		mCollider.Active();
		for (auto& p : mPole)
			p->BeginWorking();
	}

	void ThroughFloor::BeginToRest()
	{
		mCollider.Pause();
		for (auto& p : mPole)
			p->BeginToRest();
	}

	void ThroughFloor::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		float x = GameLib::GetDistanceX(data[0], data[1]);
		int num = std::round(x / static_cast<float>(PoleParam::RADIUSE*2.f));
		for (int i = 0; i < num; i++)
		{
			auto pos = data[0] + GameLib::Vector2{ PoleParam::RADIUSE + i * PoleParam::RADIUSE*2.f ,0.f };
			mPole.emplace_back(new Pole{ this,std::move(pos) });
		}

		float w = static_cast<float>(num) * PoleParam::RADIUSE * 2.f;
		mCollider.SetWidthAndHeith(w, PoleParam::RADIUSE);
		mCollider.SetPosition(data[0] + GameLib::Vector2{ w / 2.f,0.f });
		mCollider.SetColor({ 0,0,0,255 });

	}
}