#pragma once
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"

#include<iostream>

namespace GameLib
{
	struct ColiisionDetectionPolicy {
		void operator()(Collider* collider1,Collider* collider2) {

			auto hitFunc1 = collider1->GetHitFunction(collider2->GetNameTag());
			auto hitFunc2 = collider2->GetHitFunction(collider1->GetNameTag());

			if (hitFunc1 || hitFunc2)
			{

				float s1 = collider1->GetScale();
				float s2 = collider2->GetScale();

				auto vecs1 = GetRectangleVectors(collider1->GetPosition(), collider1->GetWidth() * s1, collider1->GetHeigth() * s1, collider1->GetRotation());
				auto vecs2 = GetRectangleVectors(collider2->GetPosition(), collider2->GetWidth() * s2, collider2->GetHeigth() * s2, collider2->GetRotation());

				if (CollisionDetection(std::move(vecs1), std::move(vecs2)))
				{
					if (hitFunc1)
						hitFunc1.value()(*collider2);

					if(hitFunc2)
						hitFunc2.value()(*collider1);
				}
			}
			
		}
	};
}