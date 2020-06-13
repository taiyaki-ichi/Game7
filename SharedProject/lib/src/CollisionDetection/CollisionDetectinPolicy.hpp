#pragma once
#include"lib/include/CollisionDetection/Collider.hpp"
#include"lib/include/Math/Vector2Func.hpp"

#include<iostream>

namespace GameLib
{
	struct ColiisionDetectionPolicy {
		void operator()(Collider* collider1,Collider* collider2) {

			float s1 = collider1->GetScale();
			float s2 = collider2->GetScale();

			auto vecs1 = GetRectangleVectors(collider1->GetPosition(), collider1->GetWidth() * s1, collider1->GetHeigth() * s1, collider1->GetRotation());
			auto vecs2 = GetRectangleVectors(collider2->GetPosition(), collider2->GetWidth() * s2, collider2->GetHeigth() * s2, collider2->GetRotation());

			if (CollisionDetection(std::move(vecs1), std::move(vecs2)))
			{
				collider1->HitCollider(*collider2);
				collider2->HitCollider(*collider1);
			}
			
		}
	};
}