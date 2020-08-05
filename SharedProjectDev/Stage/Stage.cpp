#include"Stage.hpp"
#include"LoadStage.hpp"
#include"Pause.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"SceneManager/StageSceneManager.hpp"
#include"Gravity/Gravity.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/CollisionDetection/CollisionDetectionSetting.hpp"

#include"BackGround/CreateBackGround.hpp"

namespace Stage
{

	Stage::Stage(GameLib::Actor* game,std::string&& fileName)
		:GameLib::Actor{ game }
		, mSceneManager{ nullptr }
		, mFlags{0}
	{
		mSceneManager = LoadStage(this, std::move(fileName));
		Gravity::Reset();

		BackGround::CreateIndianVillage(this);
	}

	void Stage::CustomizeUpdate()
	{

		char flag = mSceneManager->GetFlags();
		if (flag & SceneManager::CLEAR_FLAG)
			mFlags |= CLEAR_FLAG;
		if (flag & SceneManager::MISS_FLAG)
			mFlags |= MISS_FLAG;

		if (GameLib::InputState::GetState(GameLib::Key::P) == GameLib::ButtonState::Pressed) {
			new Pause{ this ,mSceneManager };
		}

		//マイナスrot???
		auto pos = GameLib::AffineInv(GameLib::Vector2{}, GameLib::Viewport::GetPos(), -GameLib::Viewport::GetRotation(), GameLib::Viewport::GetScale());

		//std::cout << pos.x << "," << pos.y << "\n";
		GameLib::CollisionDetectionSetting::SetPos(pos);

	}

	char Stage::GetFlags() const
	{
		return mFlags;
	}
	void Stage::ReturnToTitle()
	{
		mFlags |= RETURN_TO_TITLE_FLAG;
	}
}