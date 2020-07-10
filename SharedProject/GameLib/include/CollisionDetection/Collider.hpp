#pragma once
#include<string>
#include<unordered_map>
#include<functional>
#include<optional>
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Draw/DrawLine.hpp"
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Math/Vector2Func.hpp"
#include"GameLib/include/Math/Numbers.hpp"

#include"GameLib/include/Draw/DrawRect.hpp"

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

		DrawRect mDrawRect;

		void SetDrawRect();

		//ìñÇΩÇËîªíËÇçsÇ¢Ç©Ç«Ç§Ç©
		bool mDoCollisionDetection;

	public:
		Collider(std::string&& nameTag = "", const Vector2& pos = { 0.f,0.f }, float width = 0.f, float heigth = 0.f
			, float scale = 1.f, float rot = 0.f, Color&& color = { 0,0,0,0 });
		virtual ~Collider();

		//ìñÇΩÇ¡ÇΩéûÇ…åƒÇŒÇÍÇÈä÷êîÇìoò^Ç∑ÇÈ
		void AddHitFunction(std::string&& nameTag, std::function<void(const Collider&)>&& hitFunc);
		void AddHitFunction(std::string&& nameTag, const std::function<void(const Collider&)>& hitFunc);

		std::optional<std::function<void(const Collider&)>> GetHitFunction(const std::string& nameTag);

		static void SetAllIsDrawing(bool b);
		void SetIsDrawing(bool b);

		void Set(const Vector2& pos, float width, float heigth, float scale, float rot);
		void SetPosition(const Vector2& pos);
		void SetWidthAndHeith(float w, float h);
		void SetRotation(float rot);
		void SetScale(float s);
		void SetNameTag(std::string&& nameTag);
		void SetDoCollisionDetection(bool a);

		void SetColor(Color&& color);

		const std::string& GetNameTag() const noexcept;
		float GetWidth()const noexcept;
		float GetHeigth() const noexcept;
		float GetScale() const noexcept;
		const Vector2& GetPosition() const noexcept;
		float GetRotation() const noexcept;
		bool GetDoCollisionDetection();


		void Active();
		void Pause();
		
	};
}