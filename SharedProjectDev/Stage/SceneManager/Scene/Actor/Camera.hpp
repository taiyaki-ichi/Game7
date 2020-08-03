#pragma once
#include"StageActorBase.hpp"

namespace Stage
{
	class Camera : public ActorBase
	{

	public:
		Camera(GameLib::Actor* scene);
		virtual ~Camera() = default;

		void CustomizeUpdate() override;

		void Active() override;
		void Pause() override;

		void LoadData(std::vector<float>&& data, std::unordered_map<std::string, std::string>&& stringData) override;

		void AdjustCameraPosition();
	};
}