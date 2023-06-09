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
#include "Track.h"
#include "InputController.h"
#include "Raycast.h"
#include "Label.h"
#include "STimer.h"
#include "Button.h"
#include "Image.h"

// include the Direct3D Library file

#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib, "winmm.lib")

class Label;

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
	void CreateTrack(Track* gameObject);
	void CreateLabels(Label* label);

	unsigned int GetClientWidth();
	unsigned int GetClientHeight();
	int GetRenderWidth();
	int GetRenderHeight();
	IDirect3DDevice9* GetDevice();
	HWND GetAppWindow();
	InputController* m_pInputController;
	Raycast* m_pRaycast;
	Camera* pCamera = nullptr;


protected: 
	//atributes
	HWND m_hAppWindow; 
	HINSTANCE m_hAppInstance;
	unsigned int m_uiClientWidth;
	unsigned int m_uiClientHeight;
	DWORD m_WindowStyle;
	POINT m_pt;
	int m_renderWidth;
	int m_renderHeight;

	//DirectX attributes 
	IDirect3D9* m_pDirect3D;
	IDirect3DDevice9* m_pDevice3D;
	D3DPRESENT_PARAMETERS m_d3dpp;

	//Game attributes 
	std::vector<ColoredGameObject*> v_coloredGameObjects;
	std::vector<Track*> v_tracks;
	std::vector<Label*> v_labels;

protected:
	//Methods 

	//Initialize the app window 
	bool InitWindow();

	//Initialize
	bool InitDirect3D();
	bool InitializeInput();

	//Get raw input data
	RAWINPUT* GetRawInput(LPARAM lParam);


	// Inherited via InputListener

};