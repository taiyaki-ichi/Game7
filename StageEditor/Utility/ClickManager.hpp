#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace StageEditor
{
	//何個もつくらない
	class ClickManager : public GameLib::Actor
	{
		//フレーム数いないに2回クリックされたらDoubleClickとして認識
		//しっかりクリック!!!!
		constexpr static int DOUBLE_CLICK_TIME = 60;
		static int mCnt;

		static bool mClickedFlag;
		static bool mDoubleClickedFlag;

	public:
		ClickManager(GameLib::Actor* owner);
		virtual ~ClickManager() = default;

		void CustomizeUpdate() override;

		static bool Clicked();
		static bool DoubleClicked();
	};
}