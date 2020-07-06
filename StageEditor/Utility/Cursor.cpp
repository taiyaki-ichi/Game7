#include"Cursor.hpp"
#include"GameLib/include/InputState/InputState.hpp"

namespace StageEditor
{
	Cursor::Cursor(GameLib::Actor* owner)
		:GameLib::Actor(owner)
		, mCollider{"Cursor"}
	{
		mCollider.SetWidthAndHeith(1.f, 1.f);
		mCollider.SetPosition(GameLib::InputState::GetMousePos());
		mCollider.Active();
	}

	void Cursor::CustomizeUpdate()
	{
		mCollider.SetPosition(GameLib::InputState::GetMousePos());
	}
}