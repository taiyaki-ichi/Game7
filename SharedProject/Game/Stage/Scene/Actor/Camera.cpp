#include"Camera.hpp"
#include"Game/Stage/Scene/Scene.hpp"
#include"Game/Stage/Stage.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Game/Window.hpp"
#include<iostream>


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
		
	}
	void Camera::CustomizeUpdate()
	{
		
		auto playerPos = GetScene()->GetStage()->GetPlayerPos();
		auto cameraPos = GameLib::Viewport::GetPos();

		if ((cameraPos - playerPos).Length() > MAX_DISTANCE) {
			auto vec = cameraPos - playerPos;
			vec.Normalize();
			vec *= MAX_DISTANCE;
			cameraPos = vec + playerPos;
		}

		if (cameraPos.x - WINDOW_WIDTH / 2.f < mLeft)
			cameraPos.x = mLeft + WINDOW_WIDTH / 2.f;
		else if (mRight < cameraPos.x + WINDOW_WIDTH / 2.f)
			cameraPos.x = mRight - WINDOW_WIDTH / 2.f;

		if (cameraPos.y - WINDOW_HEIGHT / 2.f < mBottom)
			cameraPos.y = mBottom + WINDOW_HEIGHT / 2.f;
		else if (mTop < cameraPos.y + WINDOW_HEIGHT / 2.f)
			cameraPos.y = mTop - WINDOW_HEIGHT / 2.f;

		GameLib::Viewport::SetPos(std::move(cameraPos));
		

	}
}