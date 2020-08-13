#include"Stage.hpp"
#include"LoadStage.hpp"
#include"Pause.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"SceneManager/StageSceneManager.hpp"
#include"Gravity/Gravity.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/CollisionDetection/CollisionDetectionSetting.hpp"
#include"SceneManager/SceneManagerFlag.hpp"
#include"StageFlag.hpp"


#include"BackGround/CreateBackGround.hpp"

namespace Stage
{

	Stage::Stage(GameLib::Actor* game, std::string&& fileName, int playerLifeNum, int playerGemNum )
		:GameLib::Actor{ game }
		, mSceneManager{ nullptr }
		, mFlags{0}
	{
		mSceneManager = LoadStage(this, std::move(fileName), playerLifeNum, playerGemNum);
		Gravity::Reset();

		BackGround::CreateSharpTreeForest(this);
	}

	void Stage::CustomizeUpdate()
	{

		if (mSceneManager->CheckFlag(SceneManagerFlag::CLEAR_FLAG))
			mFlags |= StageFlag::CLEAR_FLAG;
		if (mSceneManager->CheckFlag(SceneManagerFlag::MISS_FLAG))
			mFlags |= StageFlag::MISS_FLAG;
		
		if (GameLib::InputState::GetState(GameLib::Key::P) == GameLib::ButtonState::Pressed) {
			new Pause{ this ,mSceneManager };
		}

		//マイナスrot???
		auto pos = GameLib::AffineInv(GameLib::Vector2{}, GameLib::Viewport::GetPos(), -GameLib::Viewport::GetRotation(), GameLib::Viewport::GetScale());

		//std::cout << pos.x << "," << pos.y << "\n";
		GameLib::CollisionDetectionSetting::SetPos(pos);

	}

	void Stage::ReturnToTitle()
	{
		mFlags |= StageFlag::RETURN_TO_TITLE_FLAG;;
	}

	bool Stage::CheckFlag(char flag)
	{
		return mFlags & flag;
	}

	ItemNumData Stage::GetItemNumData()
	{
		return mSceneManager->GetItemNumData();
	}
}