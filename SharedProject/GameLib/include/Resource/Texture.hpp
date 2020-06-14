#pragma once


namespace GameLib
{
	class Texture
	{
	public:
		Texture() = default;
		virtual ~Texture() = default;

		Texture operator=(Texture&) = delete;
		Texture(Texture&) = delete;

		virtual float GetWidth() const noexcept = 0;
		virtual float GetHeight() const noexcept = 0;
	};
}