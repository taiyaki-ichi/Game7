#pragma once
#include<string>
#include<unordered_map>
#include<functional>
#include<optional>
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Draw/DrawLine.hpp"
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"

namespace GameLib
{
	class Actor;

	constexpr int COLLIDER_DRAWORDER = 1000;

	class Collider
	{
		Vector2 mPosition;
		float mWidth;
		float mHeigth;
		float mScale;
		float mRotation;

		std::string mNameTag;

		std::unordered_map<std::string, std::function<void(const Collider&)>> mHitFunctions;

		//“–‚½‚è”»’è‚Ì—Ìˆæ‚Ì‰ÂŽ‹‰»—p
		Color mColor;
		DrawLine mLine1;
		DrawLine mLine2;
		DrawLine mLine3;
		DrawLine mLine4;
		//•`ŽÊ‚·‚é‚©‚Ç‚¤‚©
		static bool mIsDrawing;

		void CalcLinesPoint() {
			auto vecs = GetRectangleVectors(mPosition, mWidth * mScale, mHeigth * mScale, mRotation);
			mLine1.SetPoints(vecs[0], vecs[1]);
			mLine2.SetPoints(vecs[1], vecs[2]);
			mLine3.SetPoints(vecs[2], vecs[3]);
			mLine4.SetPoints(vecs[3], vecs[0]);
		}

	public:
		Collider(std::string&& nameTag = "", const Vector2& pos = { 0.f,0.f }, float width = 0.f, float heigth = 0.f
			, float scale = 1.f, float rot = 0.f, Color&& color = { 0,0,0,0 });
		virtual ~Collider();

		//“–‚½‚Á‚½Žž‚ÉŒÄ‚Î‚ê‚é
		void AddHitFunction(std::string&& nameTag, std::function<void(const Collider&)>&& hitFunc) {
			mHitFunctions.emplace(std::move(nameTag), std::move(hitFunc));
		}

		std::optional<std::function<void(const Collider&)>> GetHitFunction(const std::string& nameTag) {
			auto iter = mHitFunctions.find(nameTag);
			if (iter != mHitFunctions.end())
				return iter->second;
			else
				return std::nullopt;
		}

		static void SetIsDrawing(bool d) {
			mIsDrawing = d;
		}

		void Set(const Vector2& pos, float width, float heigth, float scale, float rot);

		void SetPosition(const Vector2& pos) {
			mPosition = pos;
			CalcLinesPoint();
		}

		void SetWidthAndHeith(float w, float h) {
			mWidth = w;
			mHeigth = h;
			CalcLinesPoint();
		}

		void SetRotation(float rot) {
			mRotation = rot;
			CalcLinesPoint();
		}

		void SetNameTag(std::string&& nameTag) {
			mNameTag = std::move(nameTag);
		}

		const std::string& GetNameTag() const noexcept {
			return mNameTag;
		}

		float GetWidth()const noexcept {
			return mWidth;
		}
		float GetHeigth() const noexcept {
			return mHeigth;
		}
		float GetScale() const noexcept {
			return mScale;
		}
		const Vector2& GetPosition() const noexcept {
			return mPosition;
		}
		float GetRotation() const noexcept {
			return mRotation;
		}
		void SetColor(Color&& color) {
			mColor = std::move(color);
			mLine1.SetColor(mColor);
			mLine2.SetColor(mColor);
			mLine3.SetColor(mColor);
			mLine4.SetColor(mColor);
		}
	};
}