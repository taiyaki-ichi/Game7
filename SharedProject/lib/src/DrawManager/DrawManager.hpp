#pragma once
#include<memory>
#include"lib/include/Manager/Manager.hpp"
#include"lib/include/Component/Draw/SpriteCompoent.hpp"
#include"DrawPolicy.hpp"


namespace GameLib
{
	class DrawManager
	{
	private:
		static WeakManager<SpriteComponent> mSprites;

	public:
		static void Draw() {
			mSprites.Invoke<DrawPolicy>();
		}

		static void Add(SpriteComponent* sprite) {
			mSprites.Add({ sprite,sprite->GetDrawOrder() });
		}

		static void Remove(SpriteComponent* sprite) {
			mSprites.Remove(sprite);
		}

	};



}