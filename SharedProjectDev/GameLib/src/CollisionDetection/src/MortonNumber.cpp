#include"GameLib/src/CollisionDetection/MortonNumber.hpp"
#include"GameLib/src/CollisionDetection/CollisionDetectionSettingImpl.hpp"
#include"GameLib/src/CollisionDetection/CollsionDetectionData.hpp"

namespace GameLib
{
	// ビット分割
	inline DWORD BitSeparate32(DWORD n)
	{
		n = (n | (n << 8)) & 0x00ff00ff;
		n = (n | (n << 4)) & 0x0f0f0f0f;
		n = (n | (n << 2)) & 0x33333333;
		return (n | (n << 1)) & 0x55555555;
	}

	// 2Dモートン空間番号算出関数
	inline WORD Get2DMortonNumber(WORD x, WORD y)
	{
		return (WORD)(BitSeparate32(x) | (BitSeparate32(y) << 1));
	}

	// 座標→線形4分木要素番号変換関数
	inline DWORD GetPointElem(float pos_x, float pos_y)
	{
		float left = CollisionDetectionSettingImpl::GetLeft();
		float top = CollisionDetectionSettingImpl::GetTop();
		float unitW = CollisionDetectionSettingImpl::GetUnitWidth();
		float unitH = CollisionDetectionSettingImpl::GetUnitHeigth();
		return Get2DMortonNumber((WORD)((pos_x - left) / unitW), (WORD)((pos_y - top) / unitH));
	}

	DWORD GetMortonNumber(float left, float top, float right, float bottom)
	{
		// 最小レベルにおける各軸位置を算出
		DWORD LT = GetPointElem(left, top);
		DWORD RB = GetPointElem(right, bottom);

		// 空間番号の排他的論理和から
		// 所属レベルを算出
		DWORD Def = RB ^ LT;
		unsigned int HiLevel = 0;
		unsigned int i;
		for (i = 0; i < TREE_LEVEL; i++)
		{
			DWORD Check = (Def >> (i * 2)) & 0x3;
			if (Check != 0)
				HiLevel = i + 1;
		}
		DWORD SpaceNum = RB >> (HiLevel * 2);
		DWORD AddNum = (POWER_OF_FOUR[TREE_LEVEL - HiLevel] - 1) / 3;
		SpaceNum += AddNum;

		if (SpaceNum > MAX_SPACECELL_NUM)
			return 0xffffffff;

		return SpaceNum;
	}

}