#pragma once
#include<string>
#include<memory>
#include"lib/include/App.hpp"

namespace GameLib
{

	template<typename T>
	class SpaceDivisionTree;
	class Collider;

	class AppImpl : public App
	{
	public:
		AppImpl(WindowData&& windowData, float fps);
		~AppImpl();

	private:

		void StartImpl(RootActor* rootActor) override;

		bool mIsRunning;

		bool Init(WindowData&& windowData);
		void GameLoop();
		void Shutdown();

		RootActor* mRootActor;

		unsigned long mTime;
		unsigned long mWaitTime;

		std::unique_ptr<SpaceDivisionTree<Collider>> mSpaceDivisionTree;
	};
}