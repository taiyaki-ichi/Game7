#pragma once
#include"Stage/Utilty/Dir4Vec.hpp"
#include"GameLib/include/Math/Vector2.hpp"

namespace Stage
{
	class Gravity {
		static Dir4Vec mDir4Vec;

	public:

		constexpr static Dir4Vec DEFAULT_GRAVITY = Dir4Vec{ Dir4::Down,1.f };

		static void SetDir4Vec(const Dir4Vec& vec);
		static void SetDir4Vec(Dir4Vec&& vec);
		static void SetSize(float size);
		static void SetDir4(const Dir4& dir);
		static void SetDir4(Dir4&& dir);
		
		static Dir4Vec GetDir4Vec();

		static float GetSize();
		static Dir4 GetDir4();

		static void Reset();

		static GameLib::Vector2 GetVector2();
		static float GetRotation();

	};
}