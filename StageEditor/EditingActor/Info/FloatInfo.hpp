#pragma once
#include"InfoBase.hpp"

namespace StageEditor
{
	class FloatInfo : public InfoBase
	{
		float mFloat;

	public:
		FloatInfo(EditingActorBase* owner, std::string& name);
		virtual ~FloatInfo() = default;

		virtual void EditingInfoUpdate() override;

		void SetFloat(float f);

		void PrintInfo() override;

	};
}