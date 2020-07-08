#include"Cursor.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

namespace StageEditor
{
	Cursor::Cursor(GameLib::Actor* owner)
		:GameLib::Actor(owner)
		, mCollider{"Cursor"}
	{
		using namespace GameLib;

		mCollider.SetWidthAndHeith(2.f, 2.f);
		auto pos = AffineInv(InputState::GetMousePos(), Viewport::GetPos(), Viewport::GetRotation(), Viewport::GetScale());
		mCollider.SetPosition(pos);
		mCollider.Active();
	}

	void Cursor::CustomizeUpdate()
	{
		using namespace GameLib;
		auto pos = AffineInv(InputState::GetMousePos(), Viewport::GetPos(), Viewport::GetRotation(), Viewport::GetScale());
		mCollider.SetPosition(pos);
	}
}