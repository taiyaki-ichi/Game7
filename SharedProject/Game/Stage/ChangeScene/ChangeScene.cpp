#pragma once
#include"ChangeScene.hpp"
#include"Game/Stage/Stage.hpp"
#include"CircleCurtain.hpp"
#include"Game/Stage/Scene/Actor/WarpBase.hpp"
#include"Game/Stage/Scene/Scene.hpp"

#include<iostream>

namespace Game::Stage
{
	ChangeScene::ChangeScene(Stage* stage, Scene* prevScene, WarpBase* nextWapeGate)
		:GameLib::Actor{stage}
		, mPrevScene{prevScene}
		, mNextWarpBase{nextWapeGate}
		, mCurtain{nullptr}
	{
		mCurtain = std::make_unique<CircleCurtain>(stage->GetPlayerPos(), mNextWarpBase->GetPosition());
		stage->PlayerPause();

	}
	void ChangeScene::CustomizeUpdate()
	{
		mCurtain->Update();

		
		if (mCurtain->IsClosed()) {
			mPrevScene->Pause();
			auto scene = static_cast<Scene*>(mNextWarpBase->GetOwner());
			scene->Active();
			scene->SetState(GameLib::Actor::State::Pause);
			auto stage = static_cast<Stage*>(mOwner);
			stage->SetPlayerPos(mNextWarpBase->GetPosition());
			stage->PlayerPause();

			mCurtain->Open();
		}

		if (mCurtain->IsOpened()) {
			auto scene = static_cast<Scene*>(mNextWarpBase->GetOwner());
			scene->SetState(GameLib::Actor::State::Active);
			scene->Active();
			scene->GetStage()->PlayerAcitve();
			SetState(GameLib::Actor::State::Dead);
		}
		
	}
}