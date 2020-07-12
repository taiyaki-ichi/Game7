#pragma once
#include"WarpBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace Game::Stage
{
	class GuruWarp: public WarpBase
	{
		GameLib::DrawTexture mTexture;
		GameLib::Collider mCollder;

		constexpr static int WAIT_TIME = 60;
		int mCnt;

	public:
		GuruWarp(Scene* scene, std::vector<float>&& data);
		virtual ~GuruWarp() = default;

		void ActorUpdate() override;

		void Active() override;
		void Pause() override;

		//プレーやがここに飛んでくるとき使用
		void PlayerWarpHere() override;
	};
}