#include"Camera.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Stage/Gravity/Gravity.hpp"
#include"Stage/WindowSize.hpp"
#include"Player.hpp"

namespace Stage
{
	Camera::Camera(GameLib::Actor* scene)
		:ActorBase{ scene }
		, mLeft{}
		, mTop{}
		, mRight{}
		, mBottom{}
	{


	}

	void Camera::Update()
	{
		AdjustPos();
	}

	void Camera::LoadData(std::vector<float>&& data)
	{
		if (data[0] < data[2]) {
			mLeft = data[0];
			mRight = data[2];
		}
		else {
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

	void Camera::AdjustPos()
	{
		using namespace GameLib;

		auto playerPos = Player::GetPosition();
		playerPos = GameLib::Vector2::Rotation(std::move(playerPos), -Gravity::GetRotation());
		auto cameraPos = GameLib::Viewport::GetPos();

		//カメラが回転しているときは動かさない,
		//roundで大まかに判定しているが厳密にやるか？？
		//SceneにIsRotationとが作るか？？
		float rot = GameLib::Viewport::GetRotation();
		constexpr float round = 0.001f;
		for (int i = 0; i < 4; i++)
			if (std::abs(rot - GameLib::PI / 2.f * i) < round) {

				cameraPos.x = playerPos.x;

				if (cameraPos.y - WindowSize::HEIGHT / 2.f + MARGIN_Y > playerPos.y)
					cameraPos.y = playerPos.y + WindowSize::HEIGHT / 2.f - MARGIN_Y;
				if (cameraPos.y + WindowSize::HEIGHT / 2.f - MARGIN_Y < playerPos.y)
					cameraPos.y = playerPos.y - WindowSize::HEIGHT / 2.f + MARGIN_Y;

				break;
			}


		float yokoMargin, tateMargin;
		float left, right, top, bottom;

		if (Gravity::GetDir4() == Dir4::Down) {
			yokoMargin = WindowSize::WIDTH / 2.f;
			tateMargin = WindowSize::HEIGHT / 2.f;

			left = mLeft;
			right = mRight;
			bottom = mBottom;
			top = mTop;

		}
		else if (Gravity::GetDir4() == Dir4::Up) {
			yokoMargin = WindowSize::WIDTH / 2.f;
			tateMargin = WindowSize::HEIGHT / 2.f;

			left = -mRight;
			right = -mLeft;
			bottom = -mTop;
			top = -mBottom;
		}
		else if (Gravity::GetDir4() == Dir4::Right) {
			yokoMargin = WindowSize::HEIGHT / 2.f;
			tateMargin = WindowSize::WIDTH / 2.f;

			left = mBottom;
			right = mTop;
			bottom = -mRight;
			top = -mLeft;
		}
		else {
			yokoMargin = WindowSize::HEIGHT / 2.f;
			tateMargin = WindowSize::WIDTH / 2.f;

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



		//std::cout << cameraPos.x << "," << cameraPos.y << "\n";
		GameLib::Viewport::SetPos(std::move(cameraPos));
	}




}