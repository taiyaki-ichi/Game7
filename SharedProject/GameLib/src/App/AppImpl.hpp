#pragma once
#include<string>
#include"GameLib/include/App.hpp"
#include"GameLib/src/CollisionDetection/Traits.hpp"
#include"GameLib/src/CollisionDetection/Policy.hpp"
#include"CollisionDetectionLib/include/tree.hpp"

namespace GameLib
{

	class Collider;

	class AppImpl : public App
	{
	public:
		AppImpl(WindowData&& windowData, float fps);
		~AppImpl();

	private:

		void StartImpl(Actor* rootActor) override;

		bool mIsRunning;

		bool Init(WindowData&& windowData);
		void GameLoop();
		void Shutdown();

		Actor* mRootActor;

		unsigned long mTime;
		unsigned long mWaitTime;

		collision_detection::tree<Collider> mTree;

		unsigned long mSumTime;
		int mCnt;

		//当たり判定を行う木の基本情報のセット
		void SetTree();
	};
}