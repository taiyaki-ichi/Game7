#pragma once
#include"GameLib/include/Math/Vector2.hpp"
#include"Stage/Utilty/Dir4Vec.hpp"
#include"Stage/Utilty/PhysicsModel.hpp"

namespace Stage
{
	//Gravityによって変化した相対的な向きを考慮した関数たち

	//向きとサイズからVector2を生成
	GameLib::Vector2 GetVector2(const Dir4& dir, float size);

	//Vector2をDir4Vecに丸め込む
	Dir4Vec GetDir4Vec(const GameLib::Vector2& vec);

	//Vector2のDir4方向の大きさを取得、マイナスもあり
	float GetDir4DirectionSize(const GameLib::Vector2& vec, const Dir4& dir4);

	//Vector2の垂直方向を反転
	GameLib::Vector2 GetVertialFlippedVector2(const GameLib::Vector2& vec);
	//vecor2の水平方向を反転
	GameLib::Vector2 GetHolizonalFlippedVector2(const GameLib::Vector2& vec);

	//フレーム当たりの力の合計や重力の方向を踏まえて更新
	//maxSpeed以上のスピードなら補正、-1でその方向の最大値は無限
	//isRotetioは重力の回転を反映させるかどうか。浮いている物体などはfalse
	void UpdatePhysicsModelWithGravity(PhysicsModel& model, const GameLib::Vector2& power, float horizonMaxSpeed = -1.f, float virticalMaxSpeed = -1.f, bool isRotaion = true);

	//vecからdirの向きが大きさsizeに変更されたVector2を返す
	GameLib::Vector2 GetDirSizeSetVector2(const GameLib::Vector2& vec, const Dir4& dir, float size);

}