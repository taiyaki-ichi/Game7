#include"GravityRotation.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"Gravity.hpp"
#include"GameLib/include/Math/Numbers.hpp"
#include"GameLib/include/InputState/InputState.hpp"

namespace Game::Stage
{
	GravityRotaion::GravityRotaion(GameLib::Actor* owner)
		:GameLib::Actor{owner}
		, mRotationCnt{0}
	{
	}

	void GravityRotaion::CustomizeUpdate()
	{
		if (mRotationCnt != 0) {
			float rot = GameLib::Viewport::GetRotation();
			if (mRotationCnt > 0)
				rot += DELTA_ROT;
			else
				rot -= DELTA_ROT;

			while (rot < 0.f)
				rot += GameLib::PI * 2.f;
			while (rot >= GameLib::PI * 2.f)
				rot -= GameLib::PI * 2.f;

			for (int i = 0; i < 4; i++) {
				if (std::abs(rot - GameLib::PI / 2.f * i) < DELTA_ROT / 2.f) {
					if (mRotationCnt > 0)
						mRotationCnt--;
					else
						mRotationCnt++;
					rot = GameLib::PI / 2.f * i;
				}
			}

			GameLib::Viewport::SetRotation(rot);
		}

		if (GameLib::InputState::GetState(GameLib::Key::no1) == GameLib::ButtonState::Pressed) {
			mRotationCnt = 1;
			int g = static_cast<int>(Gravity::GetGravityDir4());
			g += mRotationCnt;
			if (g > 3)
				g -= 4;
			Gravity::SetGravityDir4(static_cast<Dir4>(g));
		}
		if (GameLib::InputState::GetState(GameLib::Key::no2) == GameLib::ButtonState::Pressed) {
			mRotationCnt = 2;
			int g = static_cast<int>(Gravity::GetGravityDir4());
			g += mRotationCnt;
			if (g > 3)
				g -= 4;
			Gravity::SetGravityDir4(static_cast<Dir4>(g));
		}
		if (GameLib::InputState::GetState(GameLib::Key::no3) == GameLib::ButtonState::Pressed) {
			mRotationCnt = 3;
			int g = static_cast<int>(Gravity::GetGravityDir4());
			g += mRotationCnt;
			if (g > 3)
				g -= 4;
			Gravity::SetGravityDir4(static_cast<Dir4>(g));
		}
		if (GameLib::InputState::GetState(GameLib::Key::no4) == GameLib::ButtonState::Pressed) {
			mRotationCnt = 4;
			int g = static_cast<int>(Gravity::GetGravityDir4());
			g += mRotationCnt;
			if (g > 3)
				g -= 4;
			Gravity::SetGravityDir4(static_cast<Dir4>(g));
		}
	}
}