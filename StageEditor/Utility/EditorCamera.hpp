#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace StageEditor
{
	class EditorCamera : public GameLib::Actor
	{
	public:
		EditorCamera(GameLib::Actor* owner);
		virtual ~EditorCamera() = default;

		void CustomizeUpdate() override;

		void Reset();
	};
}