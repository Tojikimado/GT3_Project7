#pragma once
#include <windows.h> 
#include <d3d9.h>
#include <d3dx9.h>
#include "d3dUtil.h"
#include "Input.h"

// include the Direct3D Library file
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

class D3DApp
{
public : 

	D3DApp(HINSTANCE hInstance);

	virtual ~D3DApp();

	int Run();

	virtual bool Init(); 
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
	LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

protected: 
	//atributes
	HWND m_hAppWindow; 
	HINSTANCE m_hAppInstance;
	unsigned int m_uiClientWidth;
	unsigned int m_uiClientHeight;
	DWORD m_WindowStyle;

	//DirectX attributes 
	IDirect3D9* m_pDirect3D;
	IDirect3DDevice9* m_pDevice3D;
	D3DPRESENT_PARAMETERS m_d3dpp;

protected:
	//Methods 

	//Initialize the app window 
	bool InitWindow();

	//Initialize
	bool InitDirect3D();
	bool InitializeInput();

	//Get raw input data
	RAWINPUT* GetRawInput(LPARAM lParam);

};