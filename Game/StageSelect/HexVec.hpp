#pragma once
#include<functional>

namespace Game
{
	struct HexVec
	{
		int x;
		int y;

		HexVec(int inX,int inY)
			:x{inX}
			, y{inY}
		{}

		HexVec()
			:x{0}
			, y{0}
		{}

		HexVec operator+(const HexVec& h) {
			return { x + h.x,y + h.y };
		}
		HexVec operator-(const HexVec& h) {
			return { x - h.x,y - h.y };
		}
	};

	bool operator==(const HexVec& l, const HexVec& r) {
		return l.x == r.x && l.y == r.y;
	}
}

namespace std
{
	template<>
	struct hash<Game::HexVec> {
		size_t operator()(const Game::HexVec& h) const {

			size_t seed = 0;
			auto xHash = hash<int>()(h.x);
			auto yHash = hash<int>()(h.y);

			seed ^= xHash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			seed ^= yHash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			return seed;
		}
	};
}

