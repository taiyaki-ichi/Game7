#include"../Window.hpp"
#include"WindowClassName.hpp"
#include<Windows.h>

namespace GameLib
{

    //ウィンドウの破壊メッセを処理、最低限のウィンドウの機能のみここで実装
    LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
            break;

        }

        return 0;
    }


	bool CreateAppWindow(const std::string& windowName, float windowWidth, float windowHeigth)
	{

		HWND hwnd;
        HINSTANCE hInstance = GetModuleHandle(NULL);
        if (!hInstance)
            return false;
        
        
        // シンプルウィンドウクラス設定
        WNDCLASSEX wcex = {
            sizeof(WNDCLASSEX),	
            CS_HREDRAW | CS_VREDRAW,
            WndProc,
            0,								
            0,								
            hInstance,		
            LoadIcon(NULL, IDI_APPLICATION),
            LoadCursor(NULL, IDC_ARROW),	
            NULL,							
            NULL,							
            WINDOW_CLASS_NAME,													
            NULL	
        };
        
        if (!RegisterClassEx(&wcex))
            return false;
       

        //ウィンドウの生成
        hwnd = CreateWindowEx(
            0,
            WINDOW_CLASS_NAME,
            TEXT(windowName.c_str()),
            (WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME) | WS_VISIBLE ,
            CW_USEDEFAULT,
            0,
            static_cast<int>(windowWidth),
            static_cast<int>(windowHeigth),
            NULL,
            NULL,
            hInstance, 
            NULL);

        if (!hwnd)
            return false;
        
        /*
        RECT window_rect;
        RECT client_rect;

        GetWindowRect(hwnd, &window_rect);
        GetClientRect(hwnd, &client_rect);

        int frame_size_x = (window_rect.right - window_rect.left) - (client_rect.right - client_rect.left);
        int frame_size_y = (window_rect.bottom - window_rect.top) - (client_rect.bottom - client_rect.top);

        SetWindowPos(hwnd, NULL, CW_USEDEFAULT, CW_USEDEFAULT,
            frame_size_x + static_cast<int>(windowData.WindowWidth),
            frame_size_y + static_cast<int>(windowData.WindowHeight),
            SWP_NOMOVE);


        */

        ShowWindow(hwnd, SW_SHOW);
        UpdateWindow(hwnd);
       
		

        return true;
	}

 
}