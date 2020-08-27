#pragma once
#include"BackGroundObjectBase.hpp"

namespace Stage::BackGround
{
	class Throat140 : public ObjectBase
	{
	public:
		Throat140(GameLib::Actor*, bool isUpsideDown = false);
	};

	class Throat120 : public ObjectBase
	{
	public:
		Throat120(GameLib::Actor*, bool isUpsideDown = false);
	};

	class Throat100 : public ObjectBase
	{
	public:
		Throat100(GameLib::Actor*, bool isUpsideDown = false);
	};
}