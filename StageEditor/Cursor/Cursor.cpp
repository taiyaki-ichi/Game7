#include"Cursor.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

namespace StageEditor
{
	Cursor::Cursor(GameLib::Actor* actor)
		:GameLib::Actor{ actor }
		, mColiider{}
	{
		mColiider.SetNameTag("Cursor");
		mColiider.SetWidthAndHeith(2.f, 2.f);
		mColiider.SetColor({ 0,0,0,0 });
	}

	void Cursor::CustomizeUpdate()
	{
		using namespace GameLib;
		auto pos = AffineInv(InputState::GetMousePos(), Viewport::GetPos(), Viewport::GetRotation(), Viewport::GetScale());
		mColiider.SetPosition(std::move(pos));
	}

}