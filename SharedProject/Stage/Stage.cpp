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

	Stage::Stage(GameLib::Actor* game, std::string&& fileName, int playerLifeNum, int playerGemNum ,const BackGroundType& bgType)
		:GameLib::Actor{ game }
		, mSceneManager{ nullptr }
		, mFlags{0}
	{
		mSceneManager = LoadStage(this, std::move(fileName), playerLifeNum, playerGemNum);
		Gravity::Reset();

		if (bgType == BackGroundType::SharpTreeForest)
			BackGround::CreateSharpTreeForest(this);
		else if (bgType == BackGroundType::RoundTreeForest)
			BackGround::CreateRoundTreeForest(this);
		else if (bgType == BackGroundType::Sanctuary)
			BackGround::CreateSanctuary(this);
		else if (bgType == BackGroundType::IndianVilleage)
			BackGround::CreateIndianVillage(this);
		else if (bgType == BackGroundType::CreepyCave)
			BackGround::CreateCreepyCave(this);
			
	}

	void Stage::CustomizeUpdate()
	{

		if (mSceneManager->CheckFlag(SceneManagerFlag::CLEAR_FLAG))
			mFlags |= StageFlag::CLEAR_FLAG;
		if (mSceneManager->CheckFlag(SceneManagerFlag::MISS_FLAG))
			mFlags |= StageFlag::MISS_FLAG;
		if (mSceneManager->CheckFlag(SceneManagerFlag::RETURN_STAGESELECT_FLAG))
			mFlags |= StageFlag::RETURN_STAGESELECT_FLAG;
		
		if (GameLib::InputState::GetState(GameLib::Key::P) == GameLib::ButtonState::Pressed&&Pause::GetNum()==0&&
			!mSceneManager->CheckFlag(SceneManagerFlag::PLAYER_CLEAR_MOTION_FLAG)&&
			!mSceneManager->CheckFlag(SceneManagerFlag::PLAYER_DEATH_MOTION_FLAG)) {
			new Pause{ this ,mSceneManager };
		}

		//�}�C�i�Xrot???
		auto pos = GameLib::AffineInv(GameLib::Vector2{}, GameLib::Viewport::GetPos(), -GameLib::Viewport::GetRotation(), GameLib::Viewport::GetScale());

		//std::cout << pos.x << "," << pos.y << "\n";
		GameLib::CollisionDetectionSetting::SetPos(pos);

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