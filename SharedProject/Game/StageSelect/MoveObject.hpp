#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include<type_traits>
#include<iterator>

namespace Game::StageSelect
{
	//GetPOsition‚ÆSetPosiotion‚ğ—v‹
	template<typename Object>
	class MoveActor : public GameLib::Actor
	{
		int mCnt;
		const int mDeathTime;

		const GameLib::Vector2 mSpeed;

		Object* mObject;

	public:
		MoveActor(Object* obj, const GameLib::Vector2& speed, int time) 
			:GameLib::Actor{obj->GetOwner()}
			, mCnt{0}
			, mSpeed{speed}
			, mDeathTime{time}
			, mObject{obj}
		{
			static_assert(std::is_base_of_v<GameLib::Actor, Object>);

		}
		virtual ~MoveActor() = default;

		void CustomizeUpdate() override {
			GameLib::Vector2 pos = mObject->GetPosition();
			pos += mSpeed;
			mObject->SetPosition(std::move(pos));

			mCnt++;
			if (mCnt >= mDeathTime)
				SetState(GameLib::Actor::State::Dead);
		}
	};

	template<typename Iter>
	void MoveActors(Iter begin, Iter end,const GameLib::Vector2& speed,int time)
	{
		using value_type = typename std::iterator_traits<Iter>::value_type;
		//static_assert(std::is_base_of_v<GameLib::Actor*, value_type>);

		for (auto i = begin; i != end; i++) {
			new MoveActor{ *i,speed,time };
		}

	}


	//speed‚Åtime“®‚­•ª‚ğˆÚ“®
	template<typename Object>
	void WarpActor(Object* obj, const GameLib::Vector2& speed, int time) {
		GameLib::Vector2 pos = obj->GetPosition();
		pos += speed * time;
		obj->SetPosition(std::move(pos));
	}

	template<typename Iter>
	void WarpActors(Iter begin, Iter end, const GameLib::Vector2& speed, int time) {
		for (auto i = begin; i != end; i++)
			WarpActor(*i, speed, time);
	}

}