#include"StartActor.hpp"
#include"Game/Stage/Ground.hpp"
#include"Game/Stage/Character/Player.hpp"
#include"Game/Stage/Character/Enemy/Toge.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Game/Stage/GravityManager.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"Game/Stage/Character/Enemy/Triple.hpp"

namespace Game
{
	StartActor::StartActor()
		:RootActor()
	{
		new Stage::Ground(this, { 0.f,-250.f }, 600.f, 100.f);
		new Stage::Ground(this, { 0.f,250.f }, 600.f, 100.f);
		new Stage::Ground(this, { 350.f,0.f }, 100.f, 600.f);
		new Stage::Ground(this, { -350.f,0.f }, 100.f, 600.f);
		new Stage::Ground(this, { 0.f,-150.f }, 100.f, 100.f);

		new Stage::Player::Actor(this, { 0.f,0.f });

		//new Stage::Triple::Actor{ this ,GameLib::Vector2{200.f,0.f} };
		new Stage::Triple::Actor{ this ,GameLib::Vector2{-100.f,0.f} };

		new Stage::Toge::Actor(this, { 100.f,0.f });

		new Stage::GravityManager(this);

		mTohoho = Tohoho{};
	}
	void StartActor::CustomizeUpdate()
	{
		using namespace GameLib;

		if (InputState::GetState(Key::O) == ButtonState::Held) {
			float scale = Viewport::GetScale();
			scale -= 0.05f;
			if (scale < 0.f)
				scale = 0.f;
			Viewport::SetScale(scale);
		}
		if (InputState::GetState(Key::P) == ButtonState::Held)
			Viewport::SetScale(Viewport::GetScale() + 0.05f);

		if (InputState::GetState(Key::I) == ButtonState::Held) {
			auto pos = Viewport::GetPos();
			pos.y += 5.f;
			Viewport::SetPos(pos);
		}

		if (InputState::GetState(Key::K) == ButtonState::Held) {
			auto pos = Viewport::GetPos();
			pos.y -= 5.f;
			Viewport::SetPos(pos);
		}

		if (InputState::GetState(Key::L) == ButtonState::Held) {
			auto pos = Viewport::GetPos();
			pos.x += 5.f;
			Viewport::SetPos(pos);
		}

		if (InputState::GetState(Key::J) == ButtonState::Held) {
			auto pos = Viewport::GetPos();
			pos.x -= 5.f;
			Viewport::SetPos(pos);
		}

		if (InputState::GetState(Key::U) == ButtonState::Pressed) {
			Collider::SwitchAllColliderDraw();
		}


		if (InputState::GetState(Key::T) == ButtonState::Held) {
			float r = mTohoho.GetRadius() - 5.f;
			if (r < 0.f)
				r = 0.f;
			mTohoho.SetRadius(r);
		}
		if (InputState::GetState(Key::Y) == ButtonState::Held) {
			mTohoho.SetRadius(mTohoho.GetRadius() + 5.f);
		}

	}
}