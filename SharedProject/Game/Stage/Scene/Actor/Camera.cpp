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
		auto cameraPos = GameLib::Viewport::GetPos();
		cameraPos = AffineInv(cameraPos, Vector2{}, -Viewport::GetRotation(), Viewport::GetScale());

		cameraPos.x = playerPos.x;

		if (cameraPos.y - WINDOW_HEIGHT / 2.f + MARGIN_Y > playerPos.y)
			cameraPos.y = playerPos.y + WINDOW_HEIGHT / 2.f - MARGIN_Y;
		if (cameraPos.y + WINDOW_HEIGHT / 2.f - MARGIN_Y < playerPos.y)
			cameraPos.y = playerPos.y - WINDOW_HEIGHT / 2.f + MARGIN_Y;

		if (cameraPos.x - WINDOW_WIDTH / 2.f < mLeft)
			cameraPos.x = mLeft + WINDOW_WIDTH / 2.f;
		else if (mRight < cameraPos.x + WINDOW_WIDTH / 2.f)
			cameraPos.x = mRight - WINDOW_WIDTH / 2.f;
		
		if (cameraPos.y - WINDOW_HEIGHT / 2.f < mBottom)
			cameraPos.y = mBottom + WINDOW_HEIGHT / 2.f;
		else if (mTop < cameraPos.y + WINDOW_HEIGHT / 2.f)
			cameraPos.y = mTop - WINDOW_HEIGHT / 2.f;
			
		cameraPos = Affine(cameraPos, Vector2{}, -Viewport::GetRotation(), Viewport::GetScale());
		GameLib::Viewport::SetPos(std::move(cameraPos));
		//std::cout << "camera: " << cameraPos.x << "," << cameraPos.y << "\n";
	}
}