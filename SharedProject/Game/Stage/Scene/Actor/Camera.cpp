#include"Camera.hpp"
#include"Game/Stage/Scene/Scene.hpp"
#include"Game/Stage/Stage.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

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
			mRight = data[1];
		}
		else{
			mLeft = data[1];
			mRight = data[0];
		}

		if (data[1] < data[3]) {
			mLeft = data[1];
			mRight = data[3];
		}
		else {
			mLeft = data[3];
			mRight = data[1];
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
			GameLib::Viewport::SetPos(vec + playerPos);
		}


		

	}
}