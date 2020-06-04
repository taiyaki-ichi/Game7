#include"../Input.hpp"
#include"WindowClassName.hpp"
#include<Windows.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

namespace GameLib
{

	namespace {

		LPDIRECTINPUT8 g_pInputInterface;
		LPDIRECTINPUTDEVICE8 g_pKeyDevice;
		LPDIRECTINPUTDEVICE8 g_MouseDevice;
	}

	bool CreateInputInterface();
	bool CreateKeyboardDevice();
	bool CreateMouseDevice();
	//!< 協調レベルの設定
	BOOL SetUpCooperativeLevel(LPDIRECTINPUTDEVICE8 device);
	//!< マウスの制御起動
	BOOL StartMouseControl();
	
	

	bool InitInput()
	{
		if (!CreateInputInterface())
			return false;

		if (!CreateKeyboardDevice())
			return false;

		if (!CreateMouseDevice())
			return false;

		return true;
		
	}

	bool CreateInputInterface()
	{
		// IDirectInput8インターフェイスの取得
		HRESULT hr = DirectInput8Create(
			GetModuleHandle(nullptr),
			DIRECTINPUT_VERSION,
			IID_IDirectInput8,
			(void**)&g_pInputInterface,
			NULL);
		if (FAILED(hr))
		{
			return false;
		}

		return true;
	}

	bool CreateKeyboardDevice()
	{
		HRESULT hr;
		// IDirectInputDevice8インターフェイスの取得
		hr = g_pInputInterface->CreateDevice(GUID_SysKeyboard, &g_pKeyDevice, NULL);
		if (FAILED(hr))
		{
			return false;
		}

		// デバイスのフォーマットの設定
		hr = g_pKeyDevice->SetDataFormat(&c_dfDIKeyboard);
		if (FAILED(hr))
		{
			return false;
		}

		HWND window_handle = FindWindowA(WINDOW_CLASS_NAME, nullptr);
		// 協調モードの設定
		hr = g_pKeyDevice->SetCooperativeLevel(window_handle, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
		if (FAILED(hr))
		{
			return false;
		}

		// デバイスの取得開始
		g_pKeyDevice->Acquire();

		return true;
	}

	bool CreateMouseDevice()
	{
		g_MouseDevice = nullptr;

		// デバイス生成
		HRESULT hr = g_pInputInterface->CreateDevice(
			GUID_SysMouse,
			&g_MouseDevice,
			NULL);

		if (FAILED(hr))
		{
			return false;
		}

		// 入力フォーマットの指定
		hr = g_MouseDevice->SetDataFormat(&c_dfDIMouse);
		if (FAILED(hr))
		{
			return false;
		}

		// 協調レベルの設定
		if (SetUpCooperativeLevel(g_MouseDevice) == false)
		{
			return false;
		}

		int count = 0;
		// 制御開始
		while (StartMouseControl() == false)
		{
			Sleep(100);
			count++;
			if (count >= 5)
			{
				break;
			}
		}

		return true;
	}

	void ShutdownInput()
	{
		g_pKeyDevice->Unacquire();
		g_pKeyDevice->Release();
		g_pInputInterface->Release();
	}


	BOOL SetUpCooperativeLevel(LPDIRECTINPUTDEVICE8 device)
	{
		// 協調モードの設定
		if (FAILED(device->SetCooperativeLevel(
			FindWindow(WINDOW_CLASS_NAME, nullptr),
			DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)
		))
		{
			return false;
		}

		return true;
	}


	BOOL StartMouseControl()
	{
		// デバイスが生成されてない
		if (g_MouseDevice == nullptr)
		{
			return false;
		}
		// 制御開始
		if (FAILED(g_MouseDevice->Acquire()))
		{
			return false;
		}

		DIDEVCAPS cap;
		g_MouseDevice->GetCapabilities(&cap);
		// ポーリング判定
		if (cap.dwFlags & DIDC_POLLEDDATAFORMAT)
		{
			DWORD error = GetLastError();
			// ポーリング開始
			if (FAILED(g_MouseDevice->Poll()))
			{
				return false;
			}
		}

		return true;
	}

	Keyboard::Keyboard()
	{
		memset(mCurrState, 0, 256);
		memset(mPrevState, 0, 256);
	}

	Keyboard::~Keyboard()
	{
	}

	void Keyboard::Update()
	{
		memcpy(mPrevState, mCurrState, 256);
		if (g_pKeyDevice)
			g_pKeyDevice->GetDeviceState(256, mCurrState);
	}

	bool Keyboard::GetKeyValue(unsigned char key ) const
	{

		if (mCurrState[key] & 0x80)
			return true;
		else
			return false;
		
	}

	int Keyboard::GetKeyState(unsigned char key) const
	{
	
		if (mPrevState[key] & 0x80)
		{
			if (mCurrState[key] & 0x80)
				return 2;
			else
				return 3;
		}
		else
		{
			if (mCurrState[key] & 0x80)
				return 1;
			else
				return 0;
		}
		
	}

	Mouse::Mouse()
		:mMousePosX()
		,mMousePosY()
		,mRelativeMousePosX()
		,mRelativeMousePosY()
	{
		ZeroMemory(&mCurrState, sizeof(DIMOUSESTATE));
		ZeroMemory(&mPrevState, sizeof(DIMOUSESTATE));
	}

	Mouse::~Mouse()
	{
	}

	void Mouse::Update()
	{
		if (g_MouseDevice == nullptr)
			return;

		// 更新前に最新マウス情報を保存する
		mPrevState = mCurrState;

		// マウスの状態を取得します
		HRESULT	hr = g_MouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), &mCurrState);
		if (FAILED(hr))
		{
			g_MouseDevice->Acquire();
			hr = g_MouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), &mCurrState);
		}
		POINT p;
		// マウス座標(スクリーン座標)を取得する
		GetCursorPos(&p);

		// スクリーン座標にクライアント座標に変換する
		ScreenToClient(FindWindowA(WINDOW_CLASS_NAME, nullptr), &p);

		mRelativeMousePosX = p.x - mMousePosX;
		mRelativeMousePosY = p.y - mMousePosY;

		mMousePosX = static_cast<float>(p.x);
		mMousePosY = static_cast<float>(p.y);
		
	}

	bool Mouse::GetMouseButtonValue(int mouseButton) const
	{
		if (mouseButton < 0 || 2 < mouseButton)
			return false;

		if (mCurrState.rgbButtons[mouseButton] & 0x80)
			return true;
		else
			return false;
	}

	int Mouse::GetMouseButtonState(int mouseButton) const
	{

		if (mPrevState.rgbButtons[mouseButton] & 0x80)
		{
			if (mCurrState.rgbButtons[mouseButton] & 0x80)
				return 2;
			else
				return 3;
		}
		else
		{
			if (mCurrState.rgbButtons[mouseButton] & 0x80)
				return 1;
			else
				return 0;
		}
	}


}