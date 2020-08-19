#include"Camera.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Stage/Gravity/Gravity.hpp"
#include"Stage/WindowSize.hpp"
#include"Player.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"

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

	void Camera::LoadPosData(std::vector<GameLib::Vector2>&& data)
	{
		if (data[0].x < data[1].x) {
			mLeft = data[0].x;
			mRight = data[1].x;
		}
		else {
			mLeft = data[1].x;
			mRight = data[0].x;
		}

		if (data[0].y < data[1].y) {
			mBottom = data[0].y;
			mTop = data[1].y;
		}
		else {
			mBottom = data[1].y;
			mTop = data[0].y;
		}
	}

	void Camera::AdjustPos()
	{
		using namespace GameLib;

		//カメラが回転しているときは動かさない,
		//roundで大まかに判定しているが厳密にやるか？？
		//SceneにIsRotationとが作るか？？
		/*
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
			*/
		if (!Gravity::IsRotation())
		{

			auto playerPos = Player::GetPosition();
			playerPos = GameLib::Vector2::Rotation(std::move(playerPos), -Gravity::GetRotation());
			auto cameraPos = GameLib::Viewport::GetPos();

			//std::cout << "Player pos: " << playerPos.x << "," << playerPos.y << "\n";

			cameraPos.x = playerPos.x;

			if (cameraPos.y - WindowSize::HEIGHT / 2.f + MARGIN_Y > playerPos.y)
				cameraPos.y = playerPos.y + WindowSize::HEIGHT / 2.f - MARGIN_Y;
			if (cameraPos.y + WindowSize::HEIGHT / 2.f - MARGIN_Y < playerPos.y)
				cameraPos.y = playerPos.y - WindowSize::HEIGHT / 2.f + MARGIN_Y;



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




}