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
#include"GameLib/include/InputState/InputState.hpp"
#include"StageNumChangeBox.hpp"
#include"MoveObject.hpp"
#include"StageWarpBox.hpp"
#include"GameLib/include/CollisionDetection/CollisionDetectionSetting.hpp"

namespace Game::StageSelect
{

	namespace {

		const std::array<const std::string, 2> STAGE_DATA_FILE = { "aa","aa" };
	}

	std::vector<StageWarpBoxs> CreateStageWarpBoxs(StageSelect* stageSelect);
	void CreateStageSelectGrounds(StageSelect* stageSelect);

	//kari
	constexpr float STAGESELECT_LEFT = -400.f;
	constexpr float STAGESELECT_RIGHT = 1600.f;

	constexpr float WARPBOX_LEFT = 200.f;
	constexpr float WARPBOX_DISTANCE = 250.f;
	

	StageSelect::StageSelect(GameLib::Actor* owner)
		:GameLib::Actor{owner}
		, mBackGround{}
		, mStageWarpBox{}
		, mGoStageFlag{0}
		,mNums{}
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
		mBackGround.emplace_back(Stage::BackGround::CreateSlideTemple(this));


		WarpActors(mBackGround[1].begin(), mBackGround[1].end(), GameLib::Vector2{ 0.f,-20.f }, STAGE_CHANGE_TIME);
		WarpActors(mBackGround[2].begin(), mBackGround[2].end(), GameLib::Vector2{ 0.f,-20.f }, STAGE_CHANGE_TIME);

		mStageNumChangeBox = new StageNumChangeBox{ this,GameLib::Vector2{-200.f,-50.f} };


		for(int i=0;i<COURCE_NUM;i++){
			mNums[i] = GameLib::DrawFontText{ "../Assets/Font/mplus-1c-black.ttf" };
			mNums[i].SetText(std::to_string(i + 1));
			mNums[i].SetPosition(GameLib::Vector2{ WARPBOX_LEFT + i * WARPBOX_DISTANCE,-250.f });
			mNums[i].SetColor({ 255,255,255,255 });
			mNums[i].SetSize(GameLib::Font::Size::Size_72);
			mNums[i].SetDrawOrder(10);
		}
	}
	void StageSelect::CustomizeUpdate()
	{

		auto viewPortPos = GameLib::Vector2{ mPlayer->GetPositon().x,0.f };
		if (viewPortPos.x + WINDOW_WIDTH / 2.f > STAGESELECT_RIGHT)
			viewPortPos.x = STAGESELECT_RIGHT - WINDOW_WIDTH / 2.f;
		if (viewPortPos.x - WINDOW_WIDTH / 2.f < STAGESELECT_LEFT)
			viewPortPos.x = STAGESELECT_LEFT + WINDOW_WIDTH / 2.f;
		GameLib::Viewport::SetPos(viewPortPos);
		GameLib::CollisionDetectionSetting::SetPos(viewPortPos);


		//if(flag>0)

	}
	void StageSelect::GoStage(int stageNum)
	{
		mGoStageFlag = stageNum;
	}

	void StageSelect::ChangeStageNum(int num)
	{
		if (num != 1) {


			MoveActors(mBackGround[num - 2].begin(), mBackGround[num - 2].end(), GameLib::Vector2{ 0.f,-20.f }, STAGE_CHANGE_TIME);
			MoveActors(mBackGround[num - 1].begin(), mBackGround[num - 1].end(), GameLib::Vector2{ 0.f,20.f }, STAGE_CHANGE_TIME);

			MoveActors(mStageWarpBox[num - 2].begin(), mStageWarpBox[num - 2].end(), GameLib::Vector2{ 0.f,-20.f }, STAGE_CHANGE_TIME);
			MoveActors(mStageWarpBox[num - 1].begin(), mStageWarpBox[num - 1].end(), GameLib::Vector2{ 0.f,20.f }, STAGE_CHANGE_TIME);

			
		}
		else {

			MoveActors(mBackGround[STAGE_NUM - 1].begin(), mBackGround[STAGE_NUM - 1].end(), GameLib::Vector2{ 0.f,-20.f }, STAGE_CHANGE_TIME);
			MoveActors(mBackGround[0].begin(), mBackGround[0].end(), GameLib::Vector2{ 0.f,20.f }, STAGE_CHANGE_TIME);

			MoveActors(mStageWarpBox[STAGE_NUM - 1].begin(), mStageWarpBox[STAGE_NUM - 1].end(), GameLib::Vector2{ 0.f,-20.f }, STAGE_CHANGE_TIME);
			MoveActors(mStageWarpBox[0].begin(), mStageWarpBox[0].end(), GameLib::Vector2{ 0.f,20.f }, STAGE_CHANGE_TIME);

			
		}
	}


	std::vector<StageWarpBoxs> CreateStageWarpBoxs(StageSelect* stageSelect)
	{
		std::vector<StageWarpBoxs> result{};
		for (int stage = 0; stage < STAGE_NUM; stage++) {
			StageWarpBoxs boxs;
			for (int cource = 0; cource < COURCE_NUM; cource++) {

				auto box = new WarpBox{ stageSelect,"../Assets/Box/001.png",cource + stage * COURCE_NUM + 1,true };
				box->SetPosition(GameLib::Vector2{ WARPBOX_LEFT + cource * WARPBOX_DISTANCE,-30.f });
				boxs.emplace_back(box);
			}
			result.emplace_back(std::move(boxs));
		}

		for (int i = 1; i < STAGE_NUM; i++)
			WarpActors(result[i].begin(), result[i].end(), GameLib::Vector2{ 0.f,-20.f }, STAGE_CHANGE_TIME);

		return result;
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