#pragma once
#include"ActorBase.hpp"

namespace Game::Stage
{
	class Camera : public ActorBase
	{
		float mLeft;
		float mRight;
		float mTop;
		float mBottom;

		//‚¨ŽŽ‚µ
		constexpr static float MAX_DISTANCE = 100.f;

	public:
		Camera(Scene* scene, std::vector<float>&& data);
		virtual ~Camera() = default;

		void UpdateActor() override;

		void Active() override {}
		void Pause() override {}

	};

}