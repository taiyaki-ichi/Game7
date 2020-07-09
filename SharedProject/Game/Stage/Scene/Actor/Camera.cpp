#include"Camera.hpp"
#include"Game/Stage/Scene/Scene.hpp"
#include"Game/Stage/Stage.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Game/Window.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"

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
		
	}
	void Camera::UpdateActor()
	{
		using namespace GameLib;

		auto playerPos = GetScene()->GetStage()->GetPlayerPos();
		auto cameraPos = GameLib::Viewport::GetPos();
		cameraPos = AffineInv(cameraPos, Vector2{}, -Viewport::GetRotation(), Viewport::GetScale());
		/*
		if (GameLib::InputState::GetState(GameLib::Key::no9) == GameLib::ButtonState::Pressed) {
			std::cout << "playerPos: " << playerPos.x << "," << playerPos.y << "\n";
			std::cout << "cameraPos: " << cameraPos.x << "," << cameraPos.y << "\n";
			auto vec = cameraPos - playerPos;
			std::cout << "vec: " << vec.x << "," << vec.y << "\n";
			std::cout << "vec.len: " << vec.Length() <<"\n";
		}
		*/

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
			
		cameraPos= Affine(cameraPos, Vector2{}, -Viewport::GetRotation(), Viewport::GetScale());
		GameLib::Viewport::SetPos(std::move(cameraPos));


	}
}