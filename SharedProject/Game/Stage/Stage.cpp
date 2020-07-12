#include"Stage.hpp"
#include"Scene/Scene.hpp"
#include"CreateStage.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Player.hpp"
#include"GameLib/include/CollisionDetection/CollisionDetectionSetting.hpp"
#include"Gravity.hpp"
#include"CollisionDetectionScope.hpp"
#include"GravityRotation.hpp"
#include"ChangeScene/ChangeScene.hpp"
#include"Scene/Actor/WarpBase.hpp"
#include"BackGround/Basis.hpp"

#include"BackGround/CreateFallObject.hpp"
#include"BackGround/CreateSlideObject.hpp"

namespace Game::Stage
{
	Stage::Stage(GameLib::Actor* owner,std::string&& fileName)
		:GameLib::Actor{owner}
		, mStageScenes{}
		, mPlayer{nullptr}
		, mWarpGates{}
		, mNowScene{nullptr}
	{
		CreateStage(this, std::move(fileName));
		new Gravity{ this };
		Gravity::SetGravityDir4(Dir4::Down);

		GameLib::CollisionDetectionSetting::SetWidth(CollisionDetectionScope::WIDTH);
		GameLib::CollisionDetectionSetting::SetHeight(CollisionDetectionScope::HEIGHT);

		new GravityRotaion{ this };

		new BackGround::Basis{ this };

		BackGround::CreateFallLeaf(this);
		BackGround::CreateSlideTree(this);

	}
	void Stage::CustomizeUpdate()
	{




		//マイナスrot???
		auto pos = GameLib::AffineInv(GameLib::Vector2{},GameLib::Viewport::GetPos(), -GameLib::Viewport::GetRotation(), GameLib::Viewport::GetScale());
		
		//std::cout << pos.x << "," << pos.y << "\n";
		GameLib::CollisionDetectionSetting::SetPos(pos);
	}

	Scene* Stage::AddScene(std::string&& sceneName)
	{
		auto ptr = new Scene(this);
		mStageScenes.emplace_back(ptr);
		ptr->Pause();
		return ptr;
	}

	void Stage::SetPlayerAndNowScene(Player::Actor* player,Scene* scene)
	{
		mPlayer = player;
		mNowScene = scene;
		mNowScene->Active();
	}
	const GameLib::Vector2& Stage::GetPlayerPos()
	{
		return mPlayer->GetPositon();
	}

	void Stage::ResetPlayerPos(const GameLib::Vector2& pos)
	{
		mPlayer->SetPosition(pos);
	}

	void Stage::AddWarpGate(WarpBase* warp)
	{
		mWarpGates.emplace_back(warp);
	}
	void Stage::RemoveWarpGate(WarpBase* warp)
	{
		auto i = std::find(mWarpGates.begin(), mWarpGates.end(), warp);
		if (i != mWarpGates.end())
			mWarpGates.erase(i);
	}

	void Stage::PlayerWarp(const std::string& destinationNameTag)
	{

		auto i = mWarpGates.begin();
		for (; i != mWarpGates.end(); i++) {
			if ((*i)->GetNameTag() == destinationNameTag)
				break;
		}
		if (i != mWarpGates.end()) {
			mNowScene->SetState(GameLib::Actor::State::Pause);
			new ChangeScene{ this,mNowScene,*i };
			mNowScene = static_cast<Scene*>((*i)->GetOwner());
		}

	}


	void Stage::PlayerAcitve()
	{
		mPlayer->SetState(GameLib::Actor::State::Active);
	}

	void Stage::PlayerPause()
	{
		mPlayer->SetState(GameLib::Actor::State::Pause);
	}

}