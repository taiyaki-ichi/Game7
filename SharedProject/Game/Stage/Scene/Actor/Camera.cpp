#include"Camera.hpp"
#include"Game/Stage/Scene/Scene.hpp"
#include"Game/Stage/Stage.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Game/Window.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"Game/Stage/Gravity.hpp"

#include"GameLib/include/InputState/InputState.hpp"

namespace Game::Stage
{
	Camera::Camera(Scene* scene, std::vector<float>&& data)
		:ActorBase{scene}
		, mLeft{}
		, mTop{}
		, mRight{}
		, mBottom{}
	{
		if (data[0] < data[2]) {
			mLeft = data[0];
			mRight = data[2];
		}
		else{
			mLeft = data[2];
			mRight = data[0];
		}

		if (data[1] < data[3]) {
			mBottom = data[1];
			mTop = data[3];
		}
		else {
			mBottom = data[3];
			mTop = data[1];
		}
		
		scene->SetCamera(this);
	}
	void Camera::ActorUpdate()
	{
		AdjustCameraPos();
	}

	void Camera::AdjustCameraPos()
	{
		using namespace GameLib;
		
		auto playerPos = GetScene()->GetStage()->GetPlayerPos();
		playerPos = GameLib::Vector2::Rotation(std::move(playerPos), -Gravity::GetGravityRotation());
		auto cameraPos = GameLib::Viewport::GetPos();
		
		
		cameraPos.x = playerPos.x;

		if (cameraPos.y - WINDOW_HEIGHT / 2.f + MARGIN_Y > playerPos.y)
			cameraPos.y = playerPos.y + WINDOW_HEIGHT / 2.f - MARGIN_Y;
		if (cameraPos.y + WINDOW_HEIGHT / 2.f - MARGIN_Y < playerPos.y)
			cameraPos.y = playerPos.y - WINDOW_HEIGHT / 2.f + MARGIN_Y;

		
		GameLib::Viewport::SetPos(std::move(cameraPos));
	

	}
}