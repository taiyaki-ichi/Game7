#include"Camera.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

namespace StageEditor
{
	Camera::Camera(GameLib::Actor* owner)
		:GameLib::Actor{owner}
	{
	}
	void Camera::CustomizeUpdate()
	{
		using namespace GameLib;

		if (InputState::GetState(Key::Period) == ButtonState::Held) {
			float scale = Viewport::GetScale();
			scale -= 0.05f;
			if (scale < 0.f)
				scale = 0.f;
			Viewport::SetScale(scale);
		}
		if (InputState::GetState(Key::Slash) == ButtonState::Held)
			Viewport::SetScale(Viewport::GetScale() + 0.05f);


		if (InputState::GetState(Key::Up) == ButtonState::Held) {
			auto pos = Viewport::GetPos();
			pos.y += 10.f;
			Viewport::SetPos(pos);
		}

		if (InputState::GetState(Key::Down) == ButtonState::Held) {
			auto pos = Viewport::GetPos();
			pos.y -= 10.f;
			Viewport::SetPos(pos);
		}

		if (InputState::GetState(Key::Right) == ButtonState::Held) {
			auto pos = Viewport::GetPos();
			pos.x += 10.f;
			Viewport::SetPos(pos);
		}

		if (InputState::GetState(Key::Left) == ButtonState::Held) {
			auto pos = Viewport::GetPos();
			pos.x -= 10.f;
			Viewport::SetPos(pos);
		}

	}
	void Camera::Reset()
	{
		using namespace GameLib;
		Viewport::SetPos(Vector2{ 0.f,0.f });
		Viewport::SetScale(1.f);
	}
}