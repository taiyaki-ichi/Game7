#pragma once
#include"GameLib/include/Draw/CustomizeDrawBase.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"
#include"GameLib/include/Draw/DrawCircle.hpp"
#include<vector>

namespace Game
{
	class Tohoho : public GameLib::CustomizeDrawBase
	{
	public:

		constexpr static int TRIANGLE_NUM = 20;

		Tohoho();
		virtual ~Tohoho() = default;

		void Draw() override;

		void SetRadius(float r) noexcept{
			mCircle.SetRadius(r);
		}
		float GetRadius() const noexcept {
			return mCircle.GetRadius();
		}

	private:
		float mRadius;
		GameLib::DrawRect mDrawRect;
		GameLib::DrawCircle mCircle;
	};
}