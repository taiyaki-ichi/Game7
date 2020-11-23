#include"AppImpl.hpp"
#include"GameLib/src/Windows/Time.hpp"
#include"GameLib/src/Windows/Window.hpp"
#include"GameLib/src/Windows/Graphics.hpp"
#include"GameLib/src/Windows/Input.hpp"
#include"GameLib/src/Windows/Event.hpp"
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/src/Draw/Manager/DrawManager.hpp"
#include"GameLib/include/Resource/ResourceManager.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/include/CollisionDetection/CollisionDetectionSetting.hpp"
#include"GameLib/src/CollisionDetection/ColliderManager.hpp"
#include<cassert>


namespace GameLib
{

	AppImpl::AppImpl(WindowData&& windowData, float fps)
		:mIsRunning(true)
		,mTime(0)
		,mRootActor(nullptr)
		,mWaitTime(static_cast<unsigned long>(1000.f / fps))
		, mSumTime{0}
		, mCnt{0}
		, mTree{}
	{
		mIsRunning = Init(std::move(windowData));
		//
		//タテヨコななめはモートンから
		//
		//
		
		//仮
		mTree.set_level(4);
		SetTree();
	}

	AppImpl::~AppImpl()
	{
		if (mRootActor)
			delete mRootActor;
	}

	void AppImpl::StartImpl(Actor* rootActor)
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

		/*
		mSumTime += GetTime() - mTime;
		mCnt++;
		if (mSumTime >= 1000) {
			std::cout << mCnt << std::endl;
			mSumTime = 0;
			mCnt = 0;
		}
		*/

		mTime = GetTime();

		mRootActor->Update();

		SetTree();
		mTree.clear();
		ColliderManager::TreeRegist(mTree);
		mTree.search();
		//mSpaceDivisionTree->SearchTree();
		
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

	void AppImpl::SetTree()
	{
		const Vector2& center = CollisionDetectionSetting::GetPos();
		float width = CollisionDetectionSetting::GetWidth();
		float height = CollisionDetectionSetting::GetHeight();

		float left = center.x - width / 2.f;
		float right = center.x + width / 2.f;
		float bottom = center.y - height / 2.f;
		float top = center.y + height / 2.f;

		mTree.set_range(left, right, bottom, top);
	}


	std::unique_ptr<App> CreatAppPtr(WindowData&& windowData,float fps) {
		static std::unique_ptr<App> SingletonAppPtr = std::make_unique<AppImpl>(std::move(windowData),fps);
		assert(SingletonAppPtr!=nullptr);
		return std::move(SingletonAppPtr);
	}

	
}