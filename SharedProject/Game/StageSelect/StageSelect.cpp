#include"StageSelect.hpp"
#include"Game/Stage/BackGround/Basis.hpp"
#include"Game/Stage/Player.hpp"
#include"Game/Stage/Gravity.hpp"
#include"GameLib/include/CollisionDetection/CollisionDetectionSetting.hpp"
#include"StageWarpBox.hpp"
#include"StageSelectGround.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Game/Window.hpp"
#include"Game/Stage/BackGround/CreateSlideObject.hpp"
#include"Game/Stage/BackGround/SlideObjectBase.hpp"
#include"MoveBackGround.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"StageNumChangeBox.hpp"

namespace Game::StageSelect
{

	namespace {

		const std::array<const std::string, 2> STAGE_DATA_FILE = { "aa","aa" };
	}

	std::vector<StageWarpBoxs> CreateStageWarpBoxs(StageSelect* stageSelect);
	void CreateStageSelectGrounds(StageSelect* stageSelect);

	constexpr float STAGESELECT_LEFT = -400.f;
	constexpr float STAGESELECT_RIGHT = 800.f;

	StageSelect::StageSelect(GameLib::Actor* owner)
		:GameLib::Actor{owner}
		, mBackGround{}
		, mStageWarpBox{}
		, mGoStageFlag{0}
	{
		mStageWarpBox = CreateStageWarpBoxs(this);
		CreateStageSelectGrounds(this);

		new Stage::BackGround::Basis{ this };

		Stage::Gravity::SetGravityDir4(Dir4::Down);
		float x = 0.f;
		float y = 0.f;
		mPlayer = new Stage::Player::Actor{ this ,std::vector<float>{x,y} };

		GameLib::CollisionDetectionSetting::SetWidth(1600.f);
		GameLib::CollisionDetectionSetting::SetHeight(700.f);
		GameLib::CollisionDetectionSetting::SetPos(GameLib::Vector2{ 800.f,0.f });

		mBackGround.emplace_back(Stage::BackGround::CreateSlideSharpTree(this));
		mBackGround.emplace_back(Stage::BackGround::CreateSlideTotemPole(this));

		SetStayPosition(mBackGround[1]);

		mStageNumChangeBox = new StageNumChangeBox{ this,GameLib::Vector2{-200.f,-50.f} };
	}
	void StageSelect::CustomizeUpdate()
	{
		auto viewPortPos = GameLib::Vector2{ mPlayer->GetPositon().x,0.f };
		if (viewPortPos.x + WINDOW_WIDTH / 2.f > STAGESELECT_RIGHT)
			viewPortPos.x = STAGESELECT_RIGHT - WINDOW_WIDTH / 2.f;
		if (viewPortPos.x - WINDOW_WIDTH / 2.f < STAGESELECT_LEFT)
			viewPortPos.x = STAGESELECT_LEFT + WINDOW_WIDTH / 2.f;
		GameLib::Viewport::SetPos(viewPortPos);


	}
	void StageSelect::GoStage(int stageNum)
	{
	}

	void StageSelect::ChangeStageNum(int num)
	{
		if (num != 1) {
			new DownBackGround{ this,mBackGround[num - 2] };
			new UpBackGround{ this,mBackGround[num - 1] };
		}
		else {
			new DownBackGround{ this,mBackGround[mBackGround.size() - 1] };
			new UpBackGround{ this,mBackGround[0] };
		}
	}


	std::vector<StageWarpBoxs> CreateStageWarpBoxs(StageSelect* stageSelect)
	{
		return {};
	}

	void CreateStageSelectGrounds(StageSelect* stageSelect)
	{
		float w = 200.f;
		float h = 400.f;

		GameLib::Vector2 pos{ STAGESELECT_LEFT + w / 2.f,-h / 2.f - 200.f };

		while (pos.x < STAGESELECT_RIGHT) {
			new Ground{ stageSelect,pos,w,h };
			pos.x += w;
		}

		new Ground{ stageSelect,GameLib::Vector2{STAGESELECT_LEFT - 50.f,150.f},100.f,300.f };
		new Ground{ stageSelect,GameLib::Vector2{STAGESELECT_LEFT - 50.f,-150.f},100.f,300.f };
		new Ground{ stageSelect,GameLib::Vector2{STAGESELECT_RIGHT + 50.f,150.f},100.f,300.f };
		new Ground{ stageSelect,GameLib::Vector2{STAGESELECT_RIGHT + 50.f,-150.f},100.f,300.f };
	}

}