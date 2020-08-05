#pragma once
#include"WarpBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace Stage
{
	class GuruWarp : public WarpBase
	{
		GameLib::DrawTexture mTexture;
		GameLib::Collider mCollder;

		constexpr static int WAIT_TIME = 60;
		int mCnt;

	public:
		GuruWarp(GameLib::Actor* scene);
		virtual ~GuruWarp() = default;

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadData(std::vector<float>&& data) override;

		void PlayerWarpHere() override;

		const GameLib::Vector2& GetPosition() const override;
	};
}