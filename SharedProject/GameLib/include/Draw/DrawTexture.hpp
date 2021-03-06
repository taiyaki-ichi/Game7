#pragma once
#include<string>
#include"DrawBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"

namespace GameLib
{
	class Texture;

	class DrawTexture : public DrawBase
	{

		//�`�ʂ���e�N�X�`��
		Texture* mTexture;
		//�ꏊ
		Vector2 mPosition;
		//�g�嗦
		float mScale;
		//��]�p
		float mRotation;
		//�����x
		int mAlpha;
		//�t���b�v
		bool mHorizontalFlip;
		bool mVerticalFlip;


	public:
		DrawTexture(std::string&& fileName, const Vector2& pos = { 0.f,0.f }, float scale = 1.f, float rot = 0.f, int drawOrder = 0);
		DrawTexture(const Vector2& pos = { 0.f,0.f }, float scale = 1.f, float rot = 0.f, int drawOrder = 0);
		DrawTexture(int drawOrder = 0);
		virtual ~DrawTexture() = default;

		void Draw() override final;

		void SetTexture(std::string&& fileName);
		void SetTexture(Texture* texture);

		void Set(const Vector2& pos, float scale, float rot);
		void Set(Vector2&& pos, float scale, float rot);

		void SetPosition(const Vector2& pos);
		void SetScale(float scale);
		void SetRotation(float rot);

		void SetAlpha(int a);
		void SetHorizontalFlip(bool h);
		void SetVerticalFlip(bool v);

		const Vector2& GetPosition() const noexcept;
		float GetRotation() const noexcept;
		float GetScale() const noexcept;

		bool GetHorizontalFlip() const noexcept;
		bool GetVerticalFlip() const noexcept;
	};
}