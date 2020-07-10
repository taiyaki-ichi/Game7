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

	public:
		GuruWarp(Scene* scene, std::vector<float>&& data);
		virtual ~GuruWarp() = default;

		void UpdateActor() override;

		void Active() override;
		void Pause() override;
	};
}