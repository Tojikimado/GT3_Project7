#include "D3DApp.h"
#include "STimer.h"

namespace
{
	//Create a global pointer to D3DApp
	D3DApp* g_pd3dApp;
}

LRESULT CALLBACK MainWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return g_pd3dApp->MsgProc(hwnd,msg,wParam,lParam);
}

D3DApp::D3DApp(HINSTANCE hInstance)
{
	m_hAppInstance = hInstance;
	m_hAppWindow = NULL;
	m_uiClientHeight = 600;
	m_uiClientWidth = 800;
	m_WindowStyle = WS_OVERLAPPEDWINDOW;
	g_pd3dApp = this;

	m_d3dpp = D3DPRESENT_PARAMETERS{ 0 };
}

D3DApp::~D3DApp()
{

}

int D3DApp::Run()
{
	MSG msg = { 0 };
	STimer::InitSystemTime();

	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Update(STimer::s_deltaTime);
			STimer::UpdateDeltaTime();
			Render();
		}
	}
	return (int)msg.wParam;
}

bool D3DApp::Init()
{
	if (InitWindow() == false)
	{
		return false;
	}
	if (InitDirect3D() == false)
	{
		return false;
	}
	m_pInputController = InputController::Get();
	m_pRaycast = Raycast::Get();
	return true;
}

void D3DApp::Update(float dt)
{
	InputController::Get()->Update();
	for (ColoredGameObject* coloredGobj : v_coloredGameObjects)
	{
		if (coloredGobj->b_isActive)
		{
			coloredGobj->Update(dt);
		}
	}
}

void D3DApp::Render()
{
	m_pDevice3D->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, d3dColors::Black, 1.0f, 0);

	m_pDevice3D->BeginScene();

	for (ColoredGameObject* coloredGobj : v_coloredGameObjects)
	{
		if (coloredGobj->b_isActive)
		{
			coloredGobj->Render(m_pDevice3D);
		}
	}

	m_pDevice3D->EndScene();

	m_pDevice3D->Present(0, 0, 0, 0);
}

LRESULT D3DApp::MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	/*case Input::DXE_MOUSEMOVE:
	{
		GetCursorPos(&m_pt);
		int a = m_pt.x;
		std::string b = std::to_string(a);
		std::wstring c = std::wstring(b.begin(), b.end());
		int d = m_pt.y;
		std::string e = std::to_string(d);
		std::wstring f = std::wstring(e.begin(), e.end());
		std::wstring info = L"x = " + c + L" ; y = " + f;
		OutputDebugString((LPCWSTR)info.c_str());
		OutputDebugString(L"\n");
		return 0;
	}*/

	/*case WM_INPUT:
		RAWINPUT* raw = GetRawInput(lParam);
		if (raw->header.dwType == Input::DXI_KEYBOARD)
		{
			if (raw->data.keyboard.Message == Input::DXE_SYSKEYDOWN || raw->data.keyboard.Message == Input::DXE_KEYDOWN)
			{
				if (GetAsyncKeyState(m_inputController.m_controls["Menu"]))
				{
					PostQuitMessage(0);
				}
				if (GetAsyncKeyState(Input::DXK_A))
				{
					m_inputController.BindControl("Menu", Input::DXK_LCONTROL);
				}
			}
		}
		if (raw->header.dwType == Input::DXI_MOUSE)
		{
			if (GetAsyncKeyState(Input::DXK_LEFTMOUSEBUTTON))
			{
				OutputDebugString(L"LeftMB\n");
			}
				
		}
		return 0;*/
	}


	return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void D3DApp::CreateColoredGameObject(ColoredGameObject* _coloredGameObject)
{
	v_coloredGameObjects.push_back(_coloredGameObject);
}

void D3DApp::CreateTrack(Track* gameObject) 
{
	v_tracks.push_back(gameObject);
}

unsigned int D3DApp::GetClientWidth()
{
	return m_uiClientWidth;
}

unsigned int D3DApp::GetClientHeight()
{
	return m_uiClientHeight;
}

IDirect3DDevice9* D3DApp::GetDevice()
{
	return m_pDevice3D;
}

bool D3DApp::InitWindow()
{
	//create a window class struct 
	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(WNDCLASSEX));

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = MainWindowProc;
	wcex.hInstance = m_hAppInstance;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wcex.lpszClassName = L"ALed";
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	//register window class
	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL, L"Failed to register window class", NULL, NULL);
		return false;
	}

	RECT r = { 0,0, m_uiClientWidth, m_uiClientHeight };
	AdjustWindowRect(&r, m_WindowStyle, false);
	int width = r.right - r.left;
	int height = r.bottom - r.top;

	m_hAppWindow = CreateWindowEx(0,
		L"ALed",    // name of the window class
		L"Our First Windowed Program",   // title of the window
		m_WindowStyle,    // window style
		GetSystemMetrics(SM_CXSCREEN) / 2 - width / 2,    // x-position of the window
		GetSystemMetrics(SM_CYSCREEN) / 2 - height / 2,    // y-position of the window
		width,   // width of the window
		height,    // height of the window
		NULL,    // we have no parent window, NULL
		NULL,    // we aren't using menus, NULL
		m_hAppInstance,    // application handle
		NULL);    // used with multiple windows, NULL

	if (m_hAppWindow == NULL)
	{
		MessageBox(NULL, L"Failed to create window", NULL, NULL);
		return false;
	}

	ShowWindow(m_hAppWindow, SW_SHOW);

	return true;
}

bool D3DApp::InitDirect3D()
{
	//Get Interface to Direct3D
	m_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (m_pDirect3D == NULL)
	{
		MessageBox(NULL, L"Failed to create direct3D com object", NULL, NULL);
		return false;
	}

	//Fill out the present parameters
	ZeroMemory(&m_d3dpp, sizeof(m_d3dpp));    // clear out the struct for use
	m_d3dpp.Windowed = TRUE;    // program windowed, not fullscreen
	m_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;    // discard old frames
	m_d3dpp.hDeviceWindow = m_hAppWindow;    // set the window to be used by Direct3D
	m_d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;    // set the back buffer format to 32-bit
	m_d3dpp.BackBufferWidth = m_uiClientWidth;    // set the width of the buffer
	m_d3dpp.BackBufferHeight = m_uiClientHeight;    // set the height of the buffer
	m_d3dpp.EnableAutoDepthStencil = TRUE;    // automatically run the z-buffer for us
	m_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;    // 16-bit pixel format for the z-buffer

	//Create the device
	HRESULT res = m_pDirect3D->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL, m_hAppWindow, 
		D3DCREATE_HARDWARE_VERTEXPROCESSING| D3DCREATE_PUREDEVICE, &m_d3dpp, &m_pDevice3D);

	if (m_pDevice3D == NULL)
	{
		MessageBox(NULL, L"Failed device creation", NULL, NULL);
		return false;
	}

	return true;
}

bool D3DApp::InitializeInput()
{
	RAWINPUTDEVICE rawInput[2];

	//Keyboard
	rawInput[0].usUsagePage = 0x01;
	rawInput[0].usUsage = 0x06;
	rawInput[0].dwFlags = 0;
	rawInput[0].hwndTarget = 0;

	//////Mouse
	rawInput[1].usUsagePage = 0x01;
	rawInput[1].usUsage = 0x02;
	rawInput[1].dwFlags = 0;
	rawInput[1].hwndTarget = 0;


	if (RegisterRawInputDevices(rawInput, 2, sizeof(RAWINPUTDEVICE)) == FALSE)
		return false;

	return true;
}

RAWINPUT* D3DApp::GetRawInput(LPARAM lParam)
{
	UINT dwSize;
	GetRawInputData((HRAWINPUT)lParam, RID_INPUT, NULL, &dwSize, sizeof(RAWINPUTHEADER));
	LPBYTE lpb = new BYTE[dwSize];
	if (lpb == NULL)
		return nullptr;
	GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER));
	RAWINPUT* raw = (RAWINPUT*)lpb;
	return raw;
}
