#pragma once
#include<string>
#include<memory>
#include"lib/include/App.hpp"

namespace GameLib
{

	//ŒÅ’è60FPS
	constexpr unsigned long WAIT_TIME = static_cast<unsigned long>(1000.f / 30.f);

	template<typename T>
	class SpaceDivisionTree;
	class Collider;

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

		std::unique_ptr<SpaceDivisionTree<Collider>> mSpaceDivisionTree;
	};
}