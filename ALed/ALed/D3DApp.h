#pragma once
#include <windows.h> 
#include <d3d9.h>
#include <d3dx9.h>
#include <vector>
#include "d3dUtil.h"
#include "Input.h"
#include "TexturedGameObject.h"
#include "ColoredGameObject.h"
#include <string>
#include <iostream>
#include "InputControlle.h"

// include the Direct3D Library file

#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib, "winmm.lib")

class D3DApp
{
public : 

	D3DApp(HINSTANCE hInstance);

	virtual ~D3DApp();

	int Run();

	virtual bool Init(); 
	virtual void Update(float dt);
	virtual void Render();
	LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	void CreateColoredGameObject(ColoredGameObject* _coloredGameObject);

protected: 
	//atributes
	HWND m_hAppWindow; 
	HINSTANCE m_hAppInstance;
	unsigned int m_uiClientWidth;
	unsigned int m_uiClientHeight;
	DWORD m_WindowStyle;
	POINT m_pt;
	InputController m_inputs;

	//DirectX attributes 
	IDirect3D9* m_pDirect3D;
	IDirect3DDevice9* m_pDevice3D;
	D3DPRESENT_PARAMETERS m_d3dpp;

	//Game attributes 
	std::vector<ColoredGameObject*> v_coloredGameObjects;

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