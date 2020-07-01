#include"StartActor.hpp"
#include"Stage/Ground.hpp"
#include"Stage/Character/Player.hpp"
#include"Game/Stage/Character/Enemy/Toge.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Stage/GravityManager.hpp"

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

		new Stage::Player(this);

		//new Stage::Triple::Actor{ this ,GameLib::Vector2{200.f,0.f} };
		//new Stage::Triple::Actor{ this ,GameLib::Vector2{-100.f,0.f} };

		new Stage::Toge::Actor(this, { 100.f,0.f });

		new Stage::GravityManager(this);
	}
	void StartActor::CustomizeUpdate()
	{
		using namespace GameLib;

		if (InputState::GetState(Key::O) == ButtonState::Held) {
			float scale = Viewport::GetScale();
			if (scale - 0.1f > 0.f)
				scale -= 0.01f;
			Viewport::SetScale(scale);
		}
		if (InputState::GetState(Key::P) == ButtonState::Held)
			Viewport::SetScale(Viewport::GetScale() + 0.01f);

		if (InputState::GetState(Key::I) == ButtonState::Held) {
			auto pos=Viewport::GetPos();
			pos.y += 2.f;
			Viewport::SetPos(pos);
		}

		if (InputState::GetState(Key::K) == ButtonState::Held) {
			auto pos = Viewport::GetPos();
			pos.y -= 2.f;
			Viewport::SetPos(pos);
		}

		if (InputState::GetState(Key::J) == ButtonState::Held) {
			auto pos = Viewport::GetPos();
			pos.x += 2.f;
			Viewport::SetPos(pos);
		}

		if (InputState::GetState(Key::L) == ButtonState::Held) {
			auto pos = Viewport::GetPos();
			pos.x -= 2.f;
			Viewport::SetPos(pos);
		}


	}
}