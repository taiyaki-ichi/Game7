#include"Camera.hpp"
#include"Game/Stage/Scene/Scene.hpp"
#include"Game/Stage/Stage.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Game/Window.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"Game/Stage/Gravity.hpp"
#include"GameLib/include/Math/Numbers.hpp"


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
		
		//カメラが回転しているときは動かさない,
		//roundで大まかに判定しているが厳密にやるか？？
		//SceneにIsRotationとが作るか？？
		float rot = GameLib::Viewport::GetRotation();
		constexpr float round = 0.001f;
		for (int i = 0; i < 4; i++)
			if (std::abs(rot - GameLib::PI / 2.f * i) < round) {
				
				cameraPos.x = playerPos.x;

				if (cameraPos.y - WINDOW_HEIGHT / 2.f + MARGIN_Y > playerPos.y)
					cameraPos.y = playerPos.y + WINDOW_HEIGHT / 2.f - MARGIN_Y;
				if (cameraPos.y + WINDOW_HEIGHT / 2.f - MARGIN_Y < playerPos.y)
					cameraPos.y = playerPos.y - WINDOW_HEIGHT / 2.f + MARGIN_Y;

				break;
			}
			
		
		float yokoMargin,tateMargin;
		float left, right, top, bottom;
		
		if (Gravity::GetGravityDir4() == Dir4::Down) {
			yokoMargin = WINDOW_WIDTH / 2.f;
			tateMargin = WINDOW_HEIGHT / 2.f;

			left = mLeft;
			right = mRight;
			bottom = mBottom;
			top = mTop;

		}
		else if (Gravity::GetGravityDir4() == Dir4::Up) {
			yokoMargin = WINDOW_WIDTH / 2.f;
			tateMargin = WINDOW_HEIGHT / 2.f;

			left = -mRight;
			right = -mLeft;
			bottom = -mTop;
			top = -mBottom;
		}
		else if (Gravity::GetGravityDir4() == Dir4::Right) {
			yokoMargin = WINDOW_HEIGHT / 2.f;
			tateMargin = WINDOW_WIDTH / 2.f;

			left = mBottom;
			right = mTop;
			bottom = -mRight;
			top = -mLeft;
		}
		else {
			yokoMargin = WINDOW_HEIGHT / 2.f;
			tateMargin = WINDOW_WIDTH / 2.f;

			left = mBottom;
			right = mTop;
			bottom = mLeft;
			top = mRight;
		}


		if (cameraPos.x - yokoMargin < left)
			cameraPos.x = left + yokoMargin;
		if (cameraPos.x + yokoMargin > right)
			cameraPos.x = right - yokoMargin;
		if (cameraPos.y - tateMargin < bottom)
			cameraPos.y = bottom + tateMargin;
		if (cameraPos.y + tateMargin > top)
			cameraPos.y = top - tateMargin;
		
		

		std::cout << cameraPos.x << "," << cameraPos.y << "\n";
		GameLib::Viewport::SetPos(std::move(cameraPos));
	

	}
}