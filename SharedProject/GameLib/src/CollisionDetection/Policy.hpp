#pragma once
#include"CollisionDetectionLib/include/policy.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"

namespace collision_detection
{
	template<>
	struct hit_policy<GameLib::Collider>
	{
		static void hit(GameLib::Collider& a,GameLib::Collider& b)
		{
			auto funcA = a.GetHitFunction(b.GetNameTag());
			auto funcB = b.GetHitFunction(a.GetNameTag());

			if (funcA)
				funcA.value()(b);
			if (funcB)
				funcB.value()(a);
		}
	};

	template<>
	struct collision_detection_policy<GameLib::Collider>
	{
		inline static bool collision_detection(GameLib::Collider& a, GameLib::Collider& b) {

			//’¸“_‚ª“à•ï‚µ‚Ä‚¢‚é‚©‚Ì‚Ý’²‚×‚é
			
			auto pos1 = GameLib::GetRectangleVectors(a.GetPosition(), a.GetWidth(), a.GetHeigth(), a.GetScale());
			auto pos2 = GameLib::GetRectangleVectors(b.GetPosition(), b.GetWidth(), b.GetHeigth(), b.GetScale());
			//std::cout << "a";
			return GameLib::CollisionDetection(std::move(pos1), std::move(pos2));
			
		}
	};
}