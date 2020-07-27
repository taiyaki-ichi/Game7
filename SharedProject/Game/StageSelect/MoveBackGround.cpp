#include"MoveBackGround.hpp"
#include"Game/Stage/BackGround/SlideObjectBase.hpp"
#include"StageSelect.hpp"

namespace Game::StageSelect
{
	constexpr float SPEED = 20.f;

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
		if (mCnt >= STAGE_CHANGE_TIME)
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
		if (mCnt >= STAGE_CHANGE_TIME)
			SetState(GameLib::Actor::State::Dead);
	}

	void SetStayPosition(const std::vector<Stage::BackGround::SlideObjectBase*>& backGround)
	{
		for (auto bg : backGround) {
			auto pos = bg->GetPosition();
			pos.y -= SPEED * STAGE_CHANGE_TIME;
			bg->SetPosition(pos);
		}
		
	}

}