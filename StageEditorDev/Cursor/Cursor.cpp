#include"Cursor.hpp"
#include"GameLib/include/InputState/InputState.hpp"

namespace StageEditor
{
	Cursor::Cursor(GameLib::Actor* actor)
		:GameLib::Actor{ actor }
		, mColiider{}
	{
		mColiider.SetNameTag("Cursor");
		mColiider.SetWidthAndHeith(1.f, 1.f);
		mColiider.SetColor({ 0,0,0,0 });
	}

	void Cursor::CustomizeUpdate()
	{
		mColiider.SetPosition(GameLib::InputState::GetMousePos());
	}

}