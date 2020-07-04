#pragma once
#include"GameLib/include/Actor/RootActor.hpp"
#include"Console/ConsoleMessage.hpp"
#include"GameLib/include/Draw/DrawCircle.hpp"

namespace StageEditor
{
	class StartActor : public GameLib::RootActor
	{
	public:
		StartActor()
			:GameLib::RootActor{}
			, mDeltaRadius{1.f}
			, mCircle{0}

		{
			new ConsoleMessage{ this };
			mCircle.SetRadius(200.f);
		}
		virtual ~StartActor() = default;

		void CustomizeUpdate() override {
			float r = mCircle.GetRadius();
			r += mDeltaRadius;
			if (r > 300.f) {
				r = 300.f;
				mDeltaRadius *= -1.f;
			}
			if (r < 100.f) {
				r = 100.f;
				mDeltaRadius *= -1.f;
			}
			mCircle.SetRadius(r);
		}

	private:
		float mDeltaRadius;
		GameLib::DrawCircle mCircle;

	};
}