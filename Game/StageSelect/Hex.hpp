#pragma once
#include<utility>

namespace Game::StageSelect
{
	class Hex
	{
		const int mX;
		const int mY;
	public:
		constexpr Hex(int inX,int inY)
			:mX{inX}
			, mY{inY}
		{}
		virtual ~Hex() = default;

		int GetX() const {
			return mX;
		}

		int GetY() const {
			return mY;
		}

		int GetZ() const {
			return -mX - mY;
		}

		static int ZToNotZ(int notZ,int z) {
			return -notZ - z;
		}
	};

	inline std::pair<int,int> ToPair(const Hex& h)
	{
		return std::make_pair(h.GetX(), h.GetY());
	}

	inline Hex ToHex(const std::pair<int, int>& p)
	{
		return { p.first,p.second };
	}


	inline Hex Move(Hex&& h, int x, int y, int z) {
		
		int xx = h.GetX() + x;
		int yy = h.GetY() + y;
		int zz = h.GetZ() + z;

		if (xx + yy + zz == 0)
			return Hex{ xx,yy };
		else
			return h;
	}
}