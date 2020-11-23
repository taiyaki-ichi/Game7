#include"ColliderManager.hpp"
#include<algorithm>
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace GameLib
{
	std::vector<Collider*> ColliderManager::mColliders;

	void ColliderManager::Add(Collider* collider)
	{
		mColliders.emplace_back(collider);
	}

	void ColliderManager::Remove(Collider* collder)
	{
		auto iter = std::find(mColliders.begin(), mColliders.end(), collder);
		if (iter != mColliders.end())
			mColliders.erase(iter);
	}

	void ColliderManager::TreeRegist(collision_detection::tree<Collider>& tree)
	{
		//std::cout << mColliders.size() << std::endl;
		for (auto tmp : mColliders) {
			tree.regist(*tmp);
		}
	}
	void ColliderManager::SetAllIsDrawing(bool b)
	{
		std::for_each(mColliders.begin(), mColliders.end(), [b](Collider* l)
			{l->SetIsDrawing(b); });
	}

}