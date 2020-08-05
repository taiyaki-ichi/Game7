#pragma once
#include"StageActorBase.hpp"

namespace Stage
{
	class Camera : public ActorBase
	{
		float mLeft;
		float mRight;
		float mTop;
		float mBottom;

		//ヨコ方向へはPlayerを追尾、タテに関しては大きく動いた場合追尾
		constexpr static float MARGIN_Y = 200.f;

	public:
		Camera(GameLib::Actor* scene);
		virtual ~Camera() = default;

		void Update() override;

		void BeginWorking() override {};
		void BeginToRest() override {};

		void LoadData(std::vector<float>&& data) override;

		void AdjustPos();
	};
}