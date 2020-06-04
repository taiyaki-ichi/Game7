#include"Windows/Graphics.hpp"
#include"WindowClassName.hpp"

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include<cmath>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include<iostream>


namespace GameLib
{

	static LPDIRECT3D9 g_D3DInterface;						
	static LPDIRECT3DDEVICE9 g_D3DDevice;


	bool InitGraphics()
	{
		D3DPRESENT_PARAMETERS present_param;
		ZeroMemory(&present_param, sizeof(D3DPRESENT_PARAMETERS));

		// インターフェース作成
		g_D3DInterface = Direct3DCreate9(D3D_SDK_VERSION);
		if (g_D3DInterface == NULL)
		{
			// 作成失敗
			std::cout << "Direct3DCreate9 is failed\n";
			return false;
		}

		// バックバッファの数 => 1
		present_param.BackBufferCount = 1;
		// バックバッファのフォーマット => D3DFMT_UNKNOWN(フォーマットを知りません)
		present_param.BackBufferFormat = D3DFMT_UNKNOWN;
		// ウィンドウモード設定 => 定数で切り替え
		present_param.Windowed = true;

		// スワップエフェクト => バックバッファとフロントバッファへの切り替え方法
		present_param.SwapEffect = D3DSWAPEFFECT_DISCARD;

		// DirectDeviceの作成
		if (FAILED(g_D3DInterface->CreateDevice(D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			FindWindowA(WINDOW_CLASS_NAME, nullptr),
			D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
			&present_param,
			&g_D3DDevice)))
		{
			std::cout << "CreateDevice is failed\n";
			return false;
		}

		g_D3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
		g_D3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		g_D3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

		g_D3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
		g_D3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
		g_D3DDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_CURRENT);

		// ◆テクスチャステージ：アルファ要素の設定
		g_D3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
		g_D3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
		g_D3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_CURRENT);

		// ビューポートパラメータ
		D3DVIEWPORT9 view_port;

		// ビューポートの左上座標
		view_port.X = 0;
		view_port.Y = 0;
		// ビューポートの幅
		view_port.Width = present_param.BackBufferWidth;
		// ビューポートの高さ
		view_port.Height = present_param.BackBufferHeight;
		// ビューポート深度設定
		view_port.MinZ = 0.0f;
		view_port.MaxZ = 1.0f;

		// ビューポート設定
		if (FAILED(g_D3DDevice->SetViewport(&view_port)))
		{
			std::cout << "SetViewport is failed\n";
			return false;
		}

		return true;
	}

	void ShutdownGraphics()
	{
		if (g_D3DInterface)
			g_D3DInterface->Release();
		if (g_D3DDevice)
			g_D3DDevice->Release();
	}


	Texture::Texture(LPDIRECT3DTEXTURE9 ptr, float w, float h)
		:mPtr(std::move(ptr))
		,mWidth(w)
		,mHeight(h)
	{
	}

	Texture::~Texture()
	{
		if (mPtr)
			mPtr->Release();
	}


	std::shared_ptr<Texture> LoadTexture(const std::string& fileName)
	{
		
		LPDIRECT3DTEXTURE9 tex;
		D3DXIMAGE_INFO info;

		// 2の累乗じゃないケースを想定して元のサイズを取得してD3DXCreateTextureFromFileExで使う
		D3DXGetImageInfoFromFileA(fileName.c_str(), &info);

		if (FAILED(D3DXCreateTextureFromFileExA(g_D3DDevice,
			fileName.c_str(),
			info.Width,
			info.Height,
			1,
			0,
			D3DFMT_UNKNOWN,
			D3DPOOL_MANAGED,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			0x0000ff00,
			nullptr,
			nullptr,
			&tex)
		))
		{
			std::cout << "CreateTexture is failed : " << fileName << "\n";
			return nullptr;
		}
		else
		{
			// テクスチャサイズの取得
			D3DSURFACE_DESC desc;

			if (FAILED(tex->GetLevelDesc(0, &desc)))
			{
				std::cout << "GetLevelDesc is failed : " << fileName << "\n";
				return nullptr;
			}

			return std::make_shared<Texture>(tex, static_cast<float>(desc.Width), static_cast<float>(desc.Height));
		}

	}

	struct CUSTOM_VERTEX
	{
		float x, y, z, rhw;
		// テクスチャ座標(横)
		float tu;
		// テクスチャ座標(縦)
		float tv;

	};

	struct CUSTOM_VERTEX2
	{
		float x, y, z, rhw;

		DWORD color;

	};

	struct CUSTOM_VERTEX3
	{
		float x, y, z, rhw;

		DWORD color;

		// テクスチャ座標(横)
		float tu;
		// テクスチャ座標(縦)
		float tv;

		

	};


	void GraphicsDrawTexture(const std::shared_ptr<Texture>& texture, float posX, float posY, float rot, float scale, int alpha, int flip)
	{
		if (texture)
		{
			auto color = D3DCOLOR_ARGB(alpha, 255, 255, 255);

			float halfWidth = texture->GetWidth() * scale / 2.f;
			float halfHeigth = texture->GetHeight() * scale / 2.f;

			float point[4][2] = {
				{ -halfWidth, -halfHeigth},
				{ halfWidth, -halfHeigth},
				{ halfWidth, halfHeigth},
				{ -halfWidth, halfHeigth}
			};

			float rotAndMovePoint[4][2];
			for (int i = 0; i < 4; i++) {
				rotAndMovePoint[i][0] = point[i][0] * std::cos(rot) - point[i][1] * std::sin(rot) + posX;
				rotAndMovePoint[i][1] = point[i][0] * std::sin(rot) + point[i][1] * std::cos(rot) + posY;
			}

			bool h = flip == 1 || flip == 3;
			bool v = flip == 2 || flip == 3;
			CUSTOM_VERTEX3 TriangleFan[] = {
				{ rotAndMovePoint[0][0], rotAndMovePoint[0][1],0.f, 1.f ,color,(h ? 1.f : 0.f),(v ? 1.f : 0.f)},
				{ rotAndMovePoint[1][0], rotAndMovePoint[1][1],0.f, 1.f ,color,(h ? 0.f : 1.f),(v ? 1.f : 0.f)},
				{ rotAndMovePoint[2][0], rotAndMovePoint[2][1],0.f, 1.f ,color,(h ? 0.f : 1.f),(v ? 0.f : 1.f)},
				{ rotAndMovePoint[3][0], rotAndMovePoint[3][1],0.f, 1.f ,color,(h ? 1.f : 0.f),(v ? 0.f : 1.f)},
			};

			// 頂点構造の指定
			g_D3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE| D3DFVF_TEX1 );
			g_D3DDevice->SetTexture(0, texture->GetPtr());
			g_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, TriangleFan, sizeof(CUSTOM_VERTEX3));


		}
	}


	void GraphicsDrawLine(float aX, float aY, float bX, float bY, int r, int g, int b, int alpha)
	{
		auto color = D3DCOLOR_ARGB(alpha, r, g, b);
		CUSTOM_VERTEX2 p[] = {
			{aX,aY,0.f,1,color},
			{bX,bY,0.f,1,color},
		};

		g_D3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
		g_D3DDevice->SetTexture(0, nullptr);
		g_D3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, 1, p, sizeof(CUSTOM_VERTEX2));
	}

	void GraphicsDrawFillTriangle(float aX, float aY, float bX, float bY, float cX, float cY, int r, int g, int b, int alpha)
	{
		auto color = D3DCOLOR_ARGB(alpha, r, g, b);
		CUSTOM_VERTEX2 p[] = {
			{aX,aY,0.f,1,color},
			{bX,bY,0.f,1,color},
			{cX,cY,0.f,1,color}
		};

		g_D3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
		g_D3DDevice->SetTexture(0, nullptr);
		g_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 1, p, sizeof(CUSTOM_VERTEX2));
	}

	void DrawStart()
	{
		g_D3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 0.0f, 0);

		if (D3D_OK != g_D3DDevice->BeginScene())
			std::cout << "BeginScene is failed\n";

	}

	void DrawEnd()
	{
		g_D3DDevice->EndScene();
		g_D3DDevice->Present(NULL, NULL, NULL, NULL);

	}




}
