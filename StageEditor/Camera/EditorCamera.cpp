#include"EditorCamera.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/CollisionDetection/CollisionDetectionSetting.hpp"
#include"Stage/WindowSize.hpp"

namespace StageEditor
{
	Camera::Camera(GameLib::Actor* actor)
		:GameLib::Actor{actor}
	{}

	void Camera::CustomizeUpdate()
	{
		using namespace GameLib;

		float scale = Viewport::GetScale();
		if (InputState::GetState(Key::Period) == ButtonState::Held) {
			scale -= 0.05f;
			if (scale < 0.f)
				scale = 0.f;
			Viewport::SetScale(scale);
		}
		if (InputState::GetState(Key::Slash) == ButtonState::Held)
			Viewport::SetScale(Viewport::GetScale() + 0.05f);

		if (InputState::GetState(Key::Up) == ButtonState::Held) {
			auto pos = Viewport::GetPos();
			pos.y += 10.f / scale;
			Viewport::SetPos(pos);
		}

		if (InputState::GetState(Key::Down) == ButtonState::Held) {
			auto pos = Viewport::GetPos();
			pos.y -= 10.f / scale;
			Viewport::SetPos(pos);
		}

		if (InputState::GetState(Key::Right) == ButtonState::Held) {
			auto pos = Viewport::GetPos();
			pos.x += 10.f / scale;
			Viewport::SetPos(pos);
		}

		if (InputState::GetState(Key::Left) == ButtonState::Held) {
			auto pos = Viewport::GetPos();
			pos.x -= 10.f / scale;
			Viewport::SetPos(pos);
		}

		CollisionDetectionSetting::SetPos(Viewport::GetPos());
		GameLib::CollisionDetectionSetting::SetWidth(Stage::WindowSize::WIDTH * 2.f / scale);
		GameLib::CollisionDetectionSetting::SetHeight(Stage::WindowSize::HEIGHT * 2.f / scale);
	}

	void Camera::Reset()
	{
		using namespace GameLib;
		Viewport::SetPos(Vector2{ 0.f,0.f });
		Viewport::SetScale(1.f);
		Viewport::SetRotation(0.f);
	}
}