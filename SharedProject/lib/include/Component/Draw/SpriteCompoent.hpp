#pragma once
#include"lib/include/Component/Component.hpp"

namespace GameLib
{

	class Actor;

	class SpriteComponent : public Component
	{
	public:
		SpriteComponent(Actor* actor,int drawOrder = 0, int updateOrde = 0);
		virtual ~SpriteComponent();

		virtual void Draw() {}

		int GetDrawOrder() const noexcept {
			return mDrawOrder;
		}

	private:
		int mDrawOrder;

	};
}