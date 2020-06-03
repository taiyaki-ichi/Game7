#pragma once
#include<string>
#include<memory>
#include<d3d9.h>


namespace GameLib
{

	bool InitGraphics();
	void ShutdownGraphics();

	class Texture
	{
	public:
		Texture(LPDIRECT3DTEXTURE9 ptr,float w,float h);
		~Texture();

		Texture operator=(Texture&) = delete;
		Texture(Texture&) = delete;

		LPDIRECT3DTEXTURE9 GetPtr() const { return mPtr; }
		float GetWidth() const { return mWidth; }
		float GetHeight() const { return mHeight; }

	private:
		LPDIRECT3DTEXTURE9 mPtr;
		float mWidth;
		float mHeight;
	};


	std::shared_ptr<Texture> LoadTexture(const std::string& fileName);


	//flip=1　水平に反転　flip=2 垂直に反転 filp=3は両方
	void GraphicsDrawTexture(const std::shared_ptr<Texture>& texture, float posX, float posY, float rot, float scale, int flip = 0);
	//二点の座標、RGBとアルファは0-255
	void GraphicsDrawLine(float aX, float aY, float bX, float bY, int r, int g, int b, int alpha = 255);

	void GraphicsDrawFillTriangle(float aX, float aY, float bX, float bY, float cX, float cY, int r, int g, int b, int alpha = 255);



	//描写の開始と終了時に使用
	void DrawStart();
	void DrawEnd();
	
	
}
