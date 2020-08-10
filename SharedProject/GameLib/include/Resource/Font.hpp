#pragma once
#include<vector>

namespace GameLib
{
	class Font
	{
	public:

		enum class Size {
			Size_12 = 12,
			Size_18 = 18,
			Size_24 = 24,
			Size_36 = 36,
			Size_48 = 48,
			Size_60 = 60,
			Size_72 = 72
		};

		static std::vector<Size> GetAllSize() {
			return { Size::Size_12,Size::Size_18,Size::Size_24,Size::Size_36,Size::Size_48,Size::Size_48,Size::Size_60,Size::Size_72 };
		}

		Font() = default;
		virtual ~Font() = default;

	};
}