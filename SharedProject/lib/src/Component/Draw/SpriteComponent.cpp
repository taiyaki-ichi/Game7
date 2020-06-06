#include"lib/include/Component/Draw/SpriteCompoent.hpp"
#include"lib/src/DrawManager/DrawManager.hpp"

namespace GameLib
{
	GameLib::SpriteComponent::SpriteComponent(Actor* owner, int drawOrder, int updateOrde)
		:Component(owner,updateOrde)
		,mDrawOrder(drawOrder)
	{
		DrawManager::Add(this);

	}

	GameLib::SpriteComponent::~SpriteComponent() {
		DrawManager::Remove(this);
	}
}