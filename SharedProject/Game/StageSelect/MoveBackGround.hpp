#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace Game::Stage::BackGround {
	class SlideObjectBase;
}

namespace Game::StageSelect
{
	constexpr float BG_MOVE_DISTANCE = 600.f;

	class UpBackGround : public GameLib::Actor
	{
		int mCnt;
		std::vector<Stage::BackGround::SlideObjectBase*> mBackGrounds;

	public:
		UpBackGround(GameLib::Actor* owner, const std::vector<Stage::BackGround::SlideObjectBase*>& backGroud);
		virtual ~UpBackGround() = default;

		void CustomizeUpdate() override;
	};

	class DownBackGround : public GameLib::Actor
	{
		int mCnt;
		std::vector<Stage::BackGround::SlideObjectBase*> mBackGrounds;

	public:
		DownBackGround(GameLib::Actor* owner, const std::vector<Stage::BackGround::SlideObjectBase*>& backGroud);
		virtual ~DownBackGround() = default;

		void CustomizeUpdate() override;
	};

	
	void SetStayPosition(const std::vector<Stage::BackGround::SlideObjectBase*>& backGround);
}