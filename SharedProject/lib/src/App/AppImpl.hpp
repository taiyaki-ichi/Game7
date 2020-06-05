#pragma once
#include<string>
#include"lib/include/App.hpp"

namespace GameLib
{

	//ŒÅ’è60FPS
	constexpr unsigned long WAIT_TIME = static_cast<unsigned long>(1000.f / 60.f);

	class AppImpl : public App
	{
	public:
		AppImpl(WindowData&& windowData);
		~AppImpl();

		void Start(RootActor* rootActor) override;

	private:

		bool mIsRunning;

		bool Init(WindowData&& windowData);
		void GameLoop();
		void Shutdown();

		RootActor* mRootActor;

		unsigned long mTime;
	};
}