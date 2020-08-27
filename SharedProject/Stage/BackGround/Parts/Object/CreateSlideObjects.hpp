#pragma once
#include<utility>
#include<vector>

namespace GameLib
{
	class Actor;
}

namespace Stage::BackGround
{
	//‰¡•ûŒü‚É‚Ì‚İˆÚ“®‚·‚éBackGround‚Ì¶¬
	template<typename T, typename... Args>
	std::vector<T*> CreateSlideObjects(GameLib::Actor* actor, int num, float marginX, float lineY, Args&& ...args)
	{
		std::vector<T*> result{};
		float w = (WindowSize::WIDTH + marginX * 2.f) / num;
		for (int i = 0; i < num; i++) {
			auto ptr = new T{ actor ,std::forward<Args>(args)... };
			ptr->SetPosition(GameLib::Vector2{ w / 2.f + w * i,lineY });
			ptr->SetMarginXY(marginX, -1.f);
			result.emplace_back(ptr);
		}

		return result;
	}
}