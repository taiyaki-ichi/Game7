#pragma once
#include<memory>
#include"lib/src/Draw/DrawBase.hpp"
#include"DrawPolicy.hpp"
#include"lib/include/Manager/Manager.hpp"

namespace GameLib
{

	class DrawManager
	{
	private:
		static WeakManager<DrawBase> mSprites;

	public:
		static void Draw() {
			mSprites.Invoke<DrawPolicy>();
		}

		static void Add(DrawBase* sprite) {
			mSprites.Add({ sprite,sprite->GetDrawOrder() });
		}

		static void Remove(DrawBase* sprite) {
			mSprites.Remove(sprite);
		}

	};



}