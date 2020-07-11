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
		, mCnt{0}
	{
		mCurtain = std::make_unique<CircleCurtain>(stage->GetPlayerPos(), mNextWarpBase->GetPosition());
		stage->PlayerPause();
		mNextWarpBase->PlayerWarpHere();
	}
	void ChangeScene::CustomizeUpdate()
	{
		mCurtain->Update();

		//std::cout << "called update\n";
		
		if (mCurtain->IsClosed()) {
			mCnt++;
			
			if (mCnt > BLACK_TINE)
			{
				mPrevScene->Pause();
				auto scene = static_cast<Scene*>(mNextWarpBase->GetOwner());
				scene->Active();
				scene->SetState(GameLib::Actor::State::Pause);
				auto stage = static_cast<Stage*>(mOwner);
				//std::cout << "next pos: " << mNextWarpBase->GetPosition().x << "," << mNextWarpBase->GetPosition().y << "\n";
				stage->ResetPlayerPos(mNextWarpBase->GetPosition());
				stage->PlayerPause();

				scene->AdjustCameraPos();

				mCurtain->Open();
				mCnt = 0;
			}

			//std::cout << "closed";
		}

		if (mCurtain->IsOpened()) {
			auto scene = static_cast<Scene*>(mNextWarpBase->GetOwner());
			scene->SetState(GameLib::Actor::State::Active);
			scene->Active();
			scene->GetStage()->PlayerAcitve();
			SetState(GameLib::Actor::State::Dead);

			//std::cout << "opened";
		}
		
	}
}