#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "D3DApp.h"
#include <string>
#include "d3dUtil.h"

class D3DApp;

class Label
{
protected:
	IDirect3DDevice9* m_device;
	LPD3DXSPRITE m_sprite;
	IDirect3DTexture9* m_texture;
	LPD3DXFONT m_font;
	std::string m_caption;
	D3DXCOLOR m_color;
	DWORD m_format;
	RECT m_rect;
	POINT m_mousePos;

public:
	Label(IDirect3DDevice9* device, D3DApp* app, std::string caption, D3DCOLOR color, DWORD format, RECT rect, bool isBg);
	~Label();

	bool OnRender();
	void SetCaption(std::string caption);
	std::string GetCaption();
	void SetColor(D3DXCOLOR color);
	D3DXCOLOR GetColor();
	void SetFormat(DWORD format);
	DWORD GetFormat();
	void SetRect(int left, int top, int right, int bottom);
	RECT GetRect();
	void SetSize(D3DApp* app);
	bool LoadTexture(LPCWSTR imagePath, bool isBg);
	void Update(HWND hwnd, std::string action);

};
