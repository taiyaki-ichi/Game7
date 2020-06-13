#include"AppImpl.hpp"
#include"lib/src/Windows/Time.hpp"
#include"lib/src/Windows/Window.hpp"
#include"lib/src/Windows/Graphics.hpp"
#include"lib/src/Windows/Input.hpp"
#include"lib/src/Windows/Event.hpp"
#include"lib/include/Actor/RootActor.hpp"
#include"lib/src/Draw/Manager/DrawManager.hpp"
#include"lib/include/Resource/ResourceManager.hpp"
#include"lib/include/InputState/InputState.hpp"
#include"lib/src/CollisionDetection/SpaceDivisionTree.hpp"
#include"lib/src/CollisionDetection/ColliderManager.hpp"
#include"lib/src/CollisionDetection/CollisionDetectionSettingImpl.hpp"
#include"lib/src/CollisionDetection/CollisionDetectinPolicy.hpp"

#include<iostream>

namespace GameLib
{
	AppImpl::AppImpl(WindowData&& windowData)
		:mIsRunning(true)
		,mTime(0)
		,mRootActor(nullptr)
	{
		mIsRunning = Init(std::move(windowData));
		mSpaceDivisionTree = std::make_unique<SpaceDivisionTree<Collider>>();

	}

	AppImpl::~AppImpl()
	{
		if (mRootActor)
			delete mRootActor;
	}

	void AppImpl::Start(RootActor* rootActor)
	{
		mRootActor = rootActor;

		while (mIsRunning && mRootActor) {
			mTime = GetTime();
			GameLoop();
		}
		Shutdown();
	}


	bool AppImpl::Init(WindowData&& windowData)
	{
		if (!CreateAppWindow(std::move(windowData.WindowName), windowData.WindowWidth, windowData.WindowHeigth))
			return false;

		if (!InitGraphics())
			return false;

		if (!InitInput())
			return false;

		return true;
	}


	void AppImpl::GameLoop()
	{
		mIsRunning = PollEvent();
		InputState::Update();

		//Wait(mTime, WAIT_TIME);
		std::cout << 1000.0 / (static_cast<double>(GetTime()) - static_cast<double>(mTime)) << "\n";
		mTime = GetTime();
		
		mRootActor->Update();

	
		CollisionDetectionSettingImpl::ColcMembers();
		mSpaceDivisionTree->DeleteAllSpaceCell();
		ColliderManager::RegistSpaceDivisionTree(*mSpaceDivisionTree);
		mSpaceDivisionTree->SearchTree<ColiisionDetectionPolicy>();
		

		DrawStart();
		DrawManager::Draw();
		DrawEnd();
	}


	void AppImpl::Shutdown()
	{
		ShutdownGraphics();
		ShutdownInput();

		ResourceManager::ReleaseResources();

	}


	std::unique_ptr<App> CreatAppPtr(WindowData&& windowData) {
		return std::make_unique<AppImpl>(std::move(windowData));
	}
}