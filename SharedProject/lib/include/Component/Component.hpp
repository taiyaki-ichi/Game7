#pragma once

namespace GameLib
{
	class Actor;

	class Component
	{
	public:
		Component(Actor* owner, int updateOrder = 0);
		virtual ~Component();

		virtual void Update();

	private:
		Actor* mOwner;
		int mUpdateOrder;
	};

}