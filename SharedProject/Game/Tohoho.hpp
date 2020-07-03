#pragma once
#include"GameLib/include/Draw/CustomizeDrawBase.hpp"
#include"GameLib/include/Draw/DrawFillRect.hpp"
#include"GameLib/include/Draw/DrawFillTriangle.hpp"
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
			mRadius = r;
		}
		float GetRadius() const noexcept {
			return mRadius;
		}

	private:
		float mRadius;
		std::vector<GameLib::DrawFillTriangle> mTriangles;
		GameLib::DrawFillRect mRect;
	};
}