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
#include<cassert>

#include<iostream>

namespace GameLib
{

	AppImpl::AppImpl(WindowData&& windowData, float fps)
		:mIsRunning(true)
		,mTime(0)
		,mRootActor(nullptr)
		,mWaitTime(static_cast<unsigned long>(1000.f / fps))
	{
		mIsRunning = Init(std::move(windowData));
		mSpaceDivisionTree = std::make_unique<SpaceDivisionTree<Collider>>();

	}

	AppImpl::~AppImpl()
	{
		if (mRootActor)
			delete mRootActor;
	}

	void AppImpl::StartImpl(RootActor* rootActor)
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

		Wait(mTime, mWaitTime);
		mTime = GetTime();
		
		mRootActor->Update();

		mSpaceDivisionTree->SearchTree();
		
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


	std::unique_ptr<App> CreatAppPtr(WindowData&& windowData,float fps) {
		static std::unique_ptr<App> SingletonAppPtr = std::make_unique<AppImpl>(std::move(windowData),fps);
		assert(SingletonAppPtr!=nullptr);
		return std::move(SingletonAppPtr);
	}
}