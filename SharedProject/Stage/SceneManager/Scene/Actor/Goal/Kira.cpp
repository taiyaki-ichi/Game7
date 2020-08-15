#include"Kira.hpp"
#include<random>
#include"Stage/Gravity/Gravity.hpp"
#include"GoalParam.hpp"

namespace Stage
{

	namespace {
		std::random_device gSeed_gen;
		std::mt19937 gEngine(gSeed_gen());
	}

	Kira::Kira(GameLib::Actor* actor,const GameLib::Vector2& center)
		:GameLib::Actor{ actor }
		, mTexture{ "../Assets/Object/Goal/kira.png" }
		, mCnt{0}
	{
		//ïsåoçœ
		std::uniform_real_distribution<> x, y;

		if (Gravity::GetDir4() == Dir4::Up || Gravity::GetDir4() == Dir4::Down) {
			x = std::uniform_real_distribution<>{ static_cast<double>(center.x - GoalParam::KiraParam::GENERATE_WIDTH / 2.f),
				static_cast<double>(center.x + GoalParam::KiraParam::GENERATE_WIDTH / 2.f )};
			y = std::uniform_real_distribution<>{ static_cast<double>(center.y - GoalParam::KiraParam::GENERATE_HEIGHT / 2.f),
				static_cast<double>(center.y + GoalParam::KiraParam::GENERATE_HEIGHT / 2.f )};
		}
		else {
			x = std::uniform_real_distribution<>{ static_cast<double>(center.y - GoalParam::KiraParam::GENERATE_WIDTH / 2.f),
				static_cast<double>(center.y + GoalParam::KiraParam::GENERATE_WIDTH / 2.f )};
			y = std::uniform_real_distribution<>{ static_cast<double>(center.x - GoalParam::KiraParam::GENERATE_HEIGHT / 2.f),
				static_cast<double>(center.x + GoalParam::KiraParam::GENERATE_HEIGHT / 2.f) };
		}

		mTexture.SetPosition(GameLib::Vector2{ static_cast<float>(x(gEngine)),static_cast<float>(y(gEngine)) });
		mTexture.SetScale(0.f);
	}

	void Kira::CustomizeUpdate()
	{
		float scale = mTexture.GetScale();
		if (mCnt < GoalParam::KiraParam::DEATH_TIME / 2.f) {
			scale += GoalParam::KiraParam::DELTA_SCALE;
		}
		else {
			scale -= GoalParam::KiraParam::DELTA_SCALE;
		}
		mTexture.SetScale(scale);

		mCnt++;
		if (mCnt > GoalParam::KiraParam::DEATH_TIME)
			SetState(GameLib::Actor::State::Dead);
	}



}