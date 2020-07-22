#include"MoveBackGround.hpp"
#include"Game/Stage/BackGround/SlideObjectBase.hpp"

namespace Game::StageSelect
{
	constexpr float SPEED = 20.f;
	constexpr int DEATH_TIME = 30;

	UpBackGround::UpBackGround(GameLib::Actor* owner, const std::vector<Stage::BackGround::SlideObjectBase*>& backGroud)
		:GameLib::Actor{owner}
		, mBackGrounds{backGroud}
		,mCnt{0}
	{
	}
	void UpBackGround::CustomizeUpdate()
	{
		for (auto bg : mBackGrounds) {
			auto pos = bg->GetPosition();
			pos.y += SPEED;
			bg->SetPosition(pos);
		}

		mCnt++;
		if (mCnt >= DEATH_TIME)
			SetState(GameLib::Actor::State::Dead);

	}
	DownBackGround::DownBackGround(GameLib::Actor* owner, const std::vector<Stage::BackGround::SlideObjectBase*>& backGroud)
		:GameLib::Actor{ owner }
		, mBackGrounds{ backGroud }
		, mCnt{ 0 }
	{
	}
	void DownBackGround::CustomizeUpdate()
	{
		for (auto bg : mBackGrounds) {
			auto pos = bg->GetPosition();
			pos.y -= SPEED;
			bg->SetPosition(pos);
		}

		mCnt++;
		if (mCnt >= DEATH_TIME)
			SetState(GameLib::Actor::State::Dead);
	}

	void SetStayPosition(const std::vector<Stage::BackGround::SlideObjectBase*>& backGround)
	{
		for (auto bg : backGround) {
			auto pos = bg->GetPosition();
			pos.y -= SPEED * DEATH_TIME;
			bg->SetPosition(pos);
		}
		
	}

}