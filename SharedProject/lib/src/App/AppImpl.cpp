#include"AppImpl.hpp"
#include"lib/src/Windows/Time.hpp"
#include"lib/src/Windows/Window.hpp"
#include"lib/src/Windows/Graphics.hpp"
#include"lib/src/Windows/Input.hpp"
#include"lib/src/Windows/Event.hpp"
#include"lib/include/Actor/RootActor.hpp"
#include"lib/src/DrawManager/DrawManager.hpp"
#include"lib/include/Resource/ResourceManager.hpp"


namespace GameLib
{
	AppImpl::AppImpl(WindowData&& windowData)
		:mIsRunning(true)
		,mTime(0)
		,mRootActor(nullptr)
	{
		mIsRunning = Init(std::move(windowData));

	}

	AppImpl::~AppImpl()
	{
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

		//
		//キーボードとマウスの更新
		//

		Wait(mTime, WAIT_TIME);
		mTime = GetTime();

		mRootActor->Update();

		DrawStart();
		DrawManager::Draw();
		DrawEnd();
	}


	void AppImpl::Shutdown()
	{
		ShutdownGraphics();
		ShutdownInput();

		if (mRootActor)
			delete mRootActor;

		ResourceManager::ReleaseResources();
	}


	std::unique_ptr<App> CreatAppPtr(WindowData&& windowData) {
		return std::make_unique<AppImpl>(std::move(windowData));
	}
}