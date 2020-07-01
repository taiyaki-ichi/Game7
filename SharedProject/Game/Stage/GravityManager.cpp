#include"GravityManager.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"GameLib/include/Math/Numbers.hpp"

namespace Game::Stage
{
	GravityManager::GravityManager(Actor* owner, int updateOrder)
		:GravityActor(owner,updateOrder)
		,mDeltRotation(0.f)
		,mCnt(-1)
	{

	}
	void GravityManager::CustomizeUpdate()
	{
		using namespace GameLib;

		if (mCnt<0.f)
		{
			auto adjustRot = [](float rot) {
				while (rot < 0.f)
					rot += PI * 2.f;
				while (rot >= PI * 2.f)
					rot -= PI * 2.f;
				return rot;
			};

			auto rotaion = [this,adjustRot]() {
				float veiwRot = Viewport::GetRotation();
				float gravityRot = GetGravityRotation();
				mDeltRotation = adjustRot(gravityRot - veiwRot);
				if (mDeltRotation > PI * 5.f / 4.f)
					mDeltRotation = -PI / 2.f;
				mDeltRotation /= static_cast<float>(ROTATION_FLAME);
				mCnt = 0;

			};

			if (InputState::GetState(Key::Left) == ButtonState::Pressed) {
				SetGravityDir4(Dir4::Left);
				rotaion();
			}
			if (InputState::GetState(Key::Right) == ButtonState::Pressed) {
				SetGravityDir4(Dir4::Right);
				rotaion();
			}
			if (InputState::GetState(Key::Up) == ButtonState::Pressed) {
				SetGravityDir4(Dir4::Up);
				rotaion();
			}
			if (InputState::GetState(Key::Down) == ButtonState::Pressed) {
				SetGravityDir4(Dir4::Down);
				rotaion();
			}
			
		}
		else
		{
			mCnt++;

			float veiwRot = Viewport::GetRotation();
			veiwRot += mDeltRotation;
			if (mCnt > ROTATION_FLAME) {
				veiwRot = GetGravityRotation();
				mCnt = -1;
			}
			Viewport::SetRotation(veiwRot);
			
		}
	}
}